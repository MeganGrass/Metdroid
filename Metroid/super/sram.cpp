
#include SYSTEM
#include "sram.h"

// SRAM
BOOL SMetroid::Open(CONST CHAR * _Filename) {

	// read
	SRAM = File->Buffer(_Filename);
	if(!SRAM) {return FALSE;}

	// cwd
	Dir = File->GetDirectory((CHAR*)_Filename);

	// magic
	CHAR * Magic = new CHAR [0x0D];
	RtlSecureZeroMemory(&Magic[0], 0x0D);
	memcpy_s(&Magic[0x00], 0x0C, &SRAM[0x1FE0], 0x0C);

	if(!strcmp(Magic, "madadameyohn")) {
	} else if(!strcmp(Magic, "supermetroid")) {
	} else {
		delete [] Magic;
		delete [] SRAM;
		return FALSE;
	}

	delete [] Magic;

	// terminate
	return TRUE;
}
BOOL SMetroid::Save(CONST CHAR * _Filename) {

	// error
	if(!SRAM) {return FALSE;}

	// write
	File->CreateFromSource(SRAM, 0x2000, _Filename);

	// terminate
	return TRUE;
}
BOOL SMetroid::Close(VOID) {

	// error
	if(!SRAM) {return FALSE;}

	// cleanup
	delete [] SRAM;

	// terminate
	return TRUE;
}
// SaveGame
BOOL SMetroid::Export(UINT ID) {

	// error
	if(!SRAM) {return FALSE;}

	// pointer
	ULONG _Offset = ((0x65C * ID) + 0x10);

	// export
	File->CreateFromSource(&SRAM[_Offset], 0x65C, "%s\\%s%02d.%s", Dir, "SAMUS", ID, "SUPER");

	//terminate
	return TRUE;
}
BOOL SMetroid::Export(UINT ID, CONST CHAR * SaveRAM) {

	// open
	if(!Open(SaveRAM)) {return FALSE;}

	// export
	if(!Export(ID)) {return FALSE;}

	// close
	if(!Close()) {return FALSE;}

	// terminate
	return TRUE;
}
BOOL SMetroid::Import(UINT ID, CONST CHAR * GameSAV) {

	// error
	if(!SRAM) {return FALSE;}

	// read
	UCHAR * GAME = File->Buffer(GameSAV);
	if(!GAME) {return FALSE;}

	// pointer
	ULONG _Offset = ((0x65C * ID) + 0x10);

	// import
	memcpy_s(&SRAM[_Offset], 0x65C, &GAME[0x00], 0x65C);

	// cleanup
	delete [] GAME;

	// adjust
	if(!SetChecksum(&SRAM[0x00], ID)) {return FALSE;}

	//terminate
	return TRUE;
}
BOOL SMetroid::Import(UINT ID, CONST CHAR * SaveRAM, CONST CHAR * GameSAV) {

	// open
	if(!Open(SaveRAM)) {return FALSE;}

	// import
	if(!Import(ID, GameSAV)) {return FALSE;}

	// save
	if(!Save(SaveRAM)) {return FALSE;}

	// close
	if(!Close()) {return FALSE;}

	// terminate
	return TRUE;
}
BOOL SMetroid::Clear(UINT ID) {

	// error
	if(!SRAM) {return FALSE;}

	// pointer
	ULONG _Offset = ((0x65C * ID) + 0x10);

	// clear
	memset(&SRAM[_Offset], 0x00, 0x65C);

	// adjust
	if(!SetChecksum(&SRAM[0x00], ID)) {return FALSE;}

	//terminate
	return TRUE;
}
BOOL SMetroid::Clear(UINT ID, CONST CHAR * SaveRAM) {

	// open
	if(!Open(SaveRAM)) {return FALSE;}

	// export
	if(!Clear(ID)) {return FALSE;}

	// save
	if(!Save(SaveRAM)) {return FALSE;}

	// close
	if(!Close()) {return FALSE;}

	// terminate
	return TRUE;
}
// Checksum
BOOL SMetroid::Update(CONST CHAR * _Filename) {

	// open
	if(!Open(_Filename)) {return FALSE;}

	// adjust
	for(UINT ID = 0; ID < 3; ID++) {
		if(!SetChecksum(&SRAM[0x00], ID)) {return FALSE;}
	}

	// save
	if(!Save(_Filename)) {return FALSE;}

	// close
	if(!Close()) {return FALSE;}

	// terminate
	return TRUE;
}
BOOL SMetroid::SetChecksum(UCHAR * SRAM, UINT ID) {

	// Copyright (C) 2005 emuWorks
	// John David Ratliff
	// phonymike

	// error
	if(!SRAM) {return FALSE;}

	// variable
	UCHAR value;
	UCHAR hb, lb, hc, lc;

	UCHAR * ptr = (SRAM + 0x10 + (0x65C * ID));
	SHORT high = 0;
	SHORT low = 0;

	// calculate
	for(UINT n = 0; n < 0x65C; ++n) {

		value = ptr[n];

		if((high += value) > 0xFF) {
			high &= 0xFF;
			++low;
		}

		value = ptr[++n];

		if((low += value) > 0xFF) {
			low &= 0xFF;
		}
	}

	hb = (UCHAR)high;
	lb = (UCHAR)low;
	hc = (hb ^ 0xFF);
	lc = (lb ^ 0xFF);

	// write
	SRAM[ID * 2] = hb;
	SRAM[ID * 2 + 1] = lb;

	SRAM[8 + ID * 2] = hc;
	SRAM[8 + ID * 2 + 1] = lc;

	SRAM[0x1FF0 + ID * 2] = hb;
	SRAM[0x1FF0 + ID * 2 + 1] = lb;

	SRAM[0x1FF8 + ID * 2] = hc;
	SRAM[0x1FF8 + ID * 2 + 1] = lc;

	// terminate
	return TRUE;
}