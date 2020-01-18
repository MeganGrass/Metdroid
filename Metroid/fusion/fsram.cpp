
#include SYSTEM
#include "fsram.h"

// sram
BOOL Fusion::Open(CONST CHAR * _Filename) {

	// read
	SRAM = File->Buffer(_Filename);
	if(!SRAM) {return FAIL;}

	// magic
	CHAR * Magic = new CHAR [8];
	RtlSecureZeroMemory(&Magic[0x00], 8);
	memcpy_s(&Magic[0x00], 7, &SRAM[0x0C], 7);

	// test
	if(strcmp(Magic, "Metroid") == 0) {
		delete [] Magic;
		Dir = File->GetDirectory((CHAR*)_Filename);
	} else {
		delete [] Magic;
		delete [] SRAM;
		Dir = File->Get("\0\0");
		return FAIL;
	}

	// terminate
	return TRUE;
}
BOOL Fusion::Save(CONST CHAR * _Filename) {

	// error
	if(!SRAM) {return FAIL;}

	// write
	File->CreateFromSource(SRAM, 0x10000, _Filename);

	// terminate
	return TRUE;
}
VOID Fusion::Close(VOID) {

	// cleanup
	if(!SRAM) {return;}
	else {delete [] SRAM;}

}
// game
BOOL Fusion::Export(INT ID) {

	// error
	if(!SRAM) {return FAIL;}

	// pointer
	LONG _Offset = ((0x1200 * ID) + 0x200);

	// export
	switch(ID)
	{
	case 0:
		File->CreateFromSource(&SRAM[_Offset], 0x1200, "%s\\%s%s.%s", Dir, "SAMUS", "0A", "FUSION");
	break;
	case 1:
		File->CreateFromSource(&SRAM[_Offset], 0x1200, "%s\\%s%s.%s", Dir, "SAMUS", "0B", "FUSION");
	break;
	case 2:
		File->CreateFromSource(&SRAM[_Offset], 0x1200, "%s\\%s%s.%s", Dir, "SAMUS", "0C", "FUSION");
	break;
	}

	//terminate
	return SUCCESS;
}
BOOL Fusion::Export(INT ID, CONST CHAR * SaveRAM) {

	// open
	if(Open(SaveRAM)) {return FAIL;}

	// export
	if(Export(ID)) {return FAIL;}

	// close
	Close();

	// terminate
	return SUCCESS;
}
BOOL Fusion::Import(INT ID, CONST CHAR * GameSAV) {

	// error
	if(!SRAM) {return FAIL;}

	// read
	UCHAR * GAME = File->Buffer(GameSAV);
	if(!GAME) {return FAIL;}

	// magic
	CHAR * Magic = new CHAR [0x0F];
	RtlSecureZeroMemory(&Magic[0x00], 0x0F);
	memcpy_s(&Magic[0x00], 0x0E, &GAME[0x00], 0x0E);

	// test
	if(strcmp(Magic, "MetroidEpisode") == 0) {
		delete [] Magic;
	} else {
		delete [] Magic;
		delete [] SRAM;
		return FAIL;
	}

	// original+backup
	LONG _Offset = ((0x2400 * ID) + 0x200);
	memcpy_s(&SRAM[_Offset], 0x1200, &GAME[0x00], 0x1200);
	memcpy_s(&SRAM[_Offset+0x1200], 0x1200, &GAME[0x00], 0x1200);

	// cleanup
	delete [] GAME;

	// adjust
	if(SetChecksum(&SRAM[0x00], ID)) {return FAIL;}

	//terminate
	return SUCCESS;
}
BOOL Fusion::Import(INT ID, CONST CHAR * SaveRAM, CONST CHAR * GameSAV) {

	// open
	if(Open(SaveRAM)) {return FAIL;}

	// import
	if(Import(ID, GameSAV)) {return FAIL;}

	// save
	if(Save(SaveRAM)) {return FAIL;}

	// close
	Close();

	// terminate
	return SUCCESS;
}
BOOL Fusion::Clear(INT ID) {

	// error
	if(!SRAM) {return FAIL;}

	// tag
	LONG _Offset = (0x80 * ID);
	memset(&SRAM[_Offset], 0xFF, 0x20);

	// original+backup
	_Offset = ((0x2400 * ID) + 0x200);
	memset(&SRAM[_Offset], 0xFF, 0x2400);

	//terminate
	return SUCCESS;
}
BOOL Fusion::Clear(INT ID, CONST CHAR * SaveRAM) {

	// open
	if(Open(SaveRAM)) {return FAIL;}

	// clear
	if(Clear(ID)) {return FAIL;}

	// update
	if(Save(SaveRAM)) {return FAIL;}

	// close
	Close();

	// terminate
	return SUCCESS;
}
// checksum
BOOL Fusion::Update(CONST CHAR * _Filename) {

	// open
	_iobuf * _File = File->Open(READ_FILE, _Filename);
	if(!_File) {return FAIL;}

	LONG _Filesize = File->Size(_File);

	// read
	INT Buf = 0;
	INT Sum = 0;
	INT NegSum = 0;
	LONG _Offset = 0x200;	// TEMP
	for(UINT n = 0; n < 1151; n++, _Offset+=0x04)
	{
		fseek(_File, _Offset, SEEK_SET);
		fread(&Buf, 4, 1, _File);
		Buf && 0xFFFFFFFF;
		Sum += Buf;
	}

	// close
	fclose(_File);

	// checksum
	NegSum = (-1 - Sum);

	//Common->Message("", "Checksum:\t%08X\r\nNegative:\t\t%08X", Sum, NegSum);

	// update
	UCHAR * DATA = File->Buffer(_Filename);

	memcpy_s(&DATA[0x210], 0x04, &Sum, 0x04);	// TEMP
	memcpy_s(&DATA[0x214], 0x04, &NegSum, 0x04);	// TEMP

	File->CreateFromSource(DATA, _Filesize, _Filename);

	// cleanup
	delete [] DATA;

	// terminate
	return SUCCESS;
}
BOOL Fusion::SetChecksum(UCHAR * SRAM, INT ID) {

	// Many thanks to
	// x0_000

	// error
	if(!SRAM) {return FAIL;}

	// variable
	INT Buf = 0;
	INT Sum = 0;
	INT NegSum = 0;
	LONG _Offset = ((0x1200 * ID) + 0x200);

	// calculate
	for(UINT n = 0; n < 1151; n++, _Offset+=0x04)
	{
		memcpy_s(&Buf, 0x04, &SRAM[_Offset], 0x04);
		Buf && 0xFFFFFFFF;
		Sum += Buf;
	}

	// negative
	Sum -= 1;
	NegSum = (-1 - Sum);

	// original+backup
	_Offset = ((0x2400 * ID) + 0x200);
	memcpy_s(&SRAM[_Offset+0x10], 0x04, &Sum, 0x04);
	memcpy_s(&SRAM[_Offset+0x14], 0x04, &NegSum, 0x04);
	memcpy_s(&SRAM[_Offset+0x1210], 0x04, &Sum, 0x04);
	memcpy_s(&SRAM[_Offset+0x1214], 0x04, &NegSum, 0x04);

	// terminate
	return SUCCESS;
}