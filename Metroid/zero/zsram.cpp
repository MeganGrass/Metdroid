
#include SYSTEM
#include "zsram.h"

// SRAM
BOOL ZeroMission::Open(CONST CHAR * _Filename) {

	// read
	SRAM = File->Buffer(_Filename);
	if(!SRAM) {return FALSE;}

	// cwd
	Dir = File->GetDirectory((CHAR*)_Filename);

	// magic
	char * Magic = new char [0x0E];
	memset(&Magic[0x00], 0x00, 0x0E);
	memcpy_s(&Magic[0x00], 0x0B, &SRAM[0x1C], 0x0B);

	if(!strcmp(Magic, "ZeroMission")) {
	} else {
		delete [] Magic;
		delete [] SRAM;
		return FALSE;
	}

	delete [] Magic;

	// Terminate
	return TRUE;
}
BOOL ZeroMission::Save(CONST CHAR * _Filename) {

	// error
	if(!SRAM) {return FALSE;}

	// write
	File->CreateFromSource(SRAM, 0x10000, _Filename);

	// Terminate
	return TRUE;
}
BOOL ZeroMission::Close(VOID) {

	// error
	if(!SRAM) {return FALSE;}

	// cleanup
	delete [] SRAM;

	// Terminate
	return TRUE;
}
// Game
BOOL ZeroMission::Export(UINT ID) {

	// error
	if(!SRAM) {return FALSE;}

	// pointer
	ULONG _Offset = ((0x1220 * ID) + 0x80);

	// export
	switch(ID)
	{
	case 0:
		File->CreateFromSource(&SRAM[_Offset], 0x1220, "%s\\%s%s.%s", Dir, "SAMUS", "0A", "ZERO");
	break;
	case 1:
		File->CreateFromSource(&SRAM[_Offset], 0x1220, "%s\\%s%s.%s", Dir, "SAMUS", "0B", "ZERO");
	break;
	case 2:
		File->CreateFromSource(&SRAM[_Offset], 0x1220, "%s\\%s%s.%s", Dir, "SAMUS", "0C", "ZERO");
	break;
	}

	//Terminate
	return TRUE;
}
BOOL ZeroMission::Export(UINT ID, CONST CHAR * SaveRAM) {

	// open
	if(!Open(SaveRAM)) {return FALSE;}

	// export
	if(!Export(ID)) {return FALSE;}

	// close
	if(!Close()) {return FALSE;}

	// Terminate
	return TRUE;
}
BOOL ZeroMission::Import(UINT ID, CONST CHAR * GameSAV) {

	// error
	if(!SRAM) {return FALSE;}

	// read
	UCHAR * GAME = File->Buffer(GameSAV);
	if(!GAME) {return FALSE;}

	// magic
	char * Magic = new char [0x0D];
	memset(&Magic[0x00], 0x00, 0x0D);
	memcpy_s(&Magic[0x00], 0x0C, &GAME[0x00], 0x0C);

	if(!strcmp(Magic, "ZERO_MISSION")) {
	} else {
		delete [] Magic;
		delete [] SRAM;
		return FALSE;
	}

	delete [] Magic;

	// original
	ULONG _Offset = ((0x1220 * ID) + 0x80);
	memcpy_s(&SRAM[_Offset], 0x1220, &GAME[0x00], 0x1220);

	// backup
	_Offset = ((0x1220 * ID) + 0x36E0);
	memcpy_s(&SRAM[_Offset], 0x1220, &GAME[0x00], 0x1220);

	// cleanup
	delete [] GAME;

	// adjust
	if(!SetChecksum(&SRAM[0x00], ID)) {return FALSE;}

	//Terminate
	return TRUE;
}
BOOL ZeroMission::Import(UINT ID, CONST CHAR * SaveRAM, CONST CHAR * GameSAV) {

	// open
	if(!Open(SaveRAM)) {return FALSE;}

	// import
	if(!Import(ID, GameSAV)) {return FALSE;}

	// save
	if(!Save(SaveRAM)) {return FALSE;}

	// close
	if(!Close()) {return FALSE;}

	// Terminate
	return TRUE;
}
BOOL ZeroMission::Clear(UINT ID) {

	// error
	if(!SRAM) {return FALSE;}

	// original
	ULONG _Offset = ((0x1220 * ID) + 0x80);
	memset(&SRAM[_Offset], 0xFF, 0x1220);

	// backup
	_Offset = ((0x1220 * ID) + 0x36E0);
	memset(&SRAM[_Offset], 0xFF, 0x1220);

	//Terminate
	return TRUE;
}
BOOL ZeroMission::Clear(UINT ID, CONST CHAR * SaveRAM) {

	// open
	if(!Open(SaveRAM)) {return FALSE;}

	// export
	if(!Clear(ID)) {return FALSE;}

	// save
	if(!Save(SaveRAM)) {return FALSE;}

	// close
	if(!Close()) {return FALSE;}

	// Terminate
	return TRUE;
}
BOOL ZeroMission::Copy(UINT ID1, UINT ID2) {

	// error
	if(!SRAM) {return FALSE;}

	// data
	ULONG _Offset = ((0x1220 * ID1) + 0x80);
	UCHAR * GAME = new UCHAR [0x1220];

	memcpy_s(&GAME[0x00], 0x1220, &SRAM[_Offset], 0x1220);

	// original
	_Offset = ((0x1220 * ID2) + 0x80);
	memcpy_s(&SRAM[_Offset], 0x1220, &GAME[0x00], 0x1220);

	// backup
	_Offset = ((0x1220 * ID2) + 0x36E0);
	memcpy_s(&SRAM[_Offset], 0x1220, &GAME[0x00], 0x1220);

	// cleanup
	delete [] GAME;

	// Terminate
	return TRUE;
}
BOOL ZeroMission::Copy(UINT ID1, UINT ID2, CONST CHAR * SaveRAM) {

	// open
	if(!Open(SaveRAM)) {return FALSE;}

	// export
	if(!Copy(ID1, ID2)) {return FALSE;}

	// save
	if(!Save(SaveRAM)) {return FALSE;}

	// close
	if(!Close()) {return FALSE;}

	// Terminate
	return TRUE;
}
// Modification
BOOL ZeroMission::Disassemble(CONST CHAR * _Filename) {

	// open
	SRAM = File->Buffer(_Filename);
	if(!SRAM) {return FALSE;}

	// magic
	char * Magic = new char [0x0D];
	memset(&Magic[0x00], 0x00, 0x0D);
	memcpy_s(&Magic[0x00], 0x0B, &SRAM[0x1C], 0x0B);

	if(!strcmp(Magic, "ZeroMission")) {
		DateType = SAV;
	} else {
		memset(&Magic[0x00], 0x00, 0x0D);
		memcpy_s(&Magic[0x00], 0x0C, &SRAM[0x00], 0x0C);
		if(!strcmp(Magic, "ZERO_MISSION")) {
			DateType = SAMUS;
		} else {
			delete [] Magic;
			delete [] SRAM;
			return FALSE;
		}
	}

	delete [] Magic;

	// disassemble
	switch(DateType)
	{
	case SAV:
		for(UINT ID = 0; ID < 3; ID++)
		{
			Disassemble(&SRAM[0x00], ID);
		}
	break;
	case SAMUS:
		Disassemble(&SRAM[0x00], -1);
	break;
	}

	// cleanup
	Close();

	// Terminate
	return TRUE;
}
BOOL ZeroMission::Disassemble(UCHAR * SRAM, UINT ID) {

	// pointer
	ULONG _Offset = 0x00;
	switch(ID)
	{
	case -1:
		ID = 0;
	break;
	default:
		_Offset = ((0x1220 * ID) + 0x80);
	break;
	}

	// read
	Game = new tagZeroSaveGame;
	RtlSecureZeroMemory(Game, sizeof(tagZeroSaveGame));
	memcpy_s(Game, 0x1220, &SRAM[_Offset], 0x1220);

	switch(Game->Checksum)
	{
	case 0xFFFFFFFF:
		delete [] Game;
		return TRUE;
	}

	// output
	_iobuf * _File = File->Open(CREATE_FILE, File->Get(".\\%s%02d.%s", "ZERO", ID, "INI"));
	if(!_File) {return FALSE;}

	// disassemble
	File->Print(_File, "%s\t%d\r\n", "MissionComplete", Game->MissionComplete);
	File->Print(_File, "%s\t\t%d\r\n", "NewGame", Game->NewGame);
	File->Print(_File, "%s\t\t%d\r\n", "Area", Game->Area);
	File->Print(_File, "%s\t%d\r\n", "RoomPrev", Game->RoomPrev);
	File->Print(_File, "%s\t\t%d\r\n", "RoomCur", Game->RoomCur);
	File->Print(_File, "%s\t%d\r\n", "DoorType", Game->DoorType);
	File->Print(_File, "%s\t%d\r\n", "Difficulty", Game->Difficulty);
	File->Print(_File, "%s\t%d\r\n", "HealthMax", Game->HealthMax);
	File->Print(_File, "%s\t%d\r\n", "MissileMax", Game->MissileMax);
	File->Print(_File, "%s\t%d\r\n", "SMissileMax", Game->SMissileMax);
	File->Print(_File, "%s\t\t%d\r\n", "Health", Game->Health);
	File->Print(_File, "%s\t\t%d\r\n", "Missile", Game->Missile);
	File->Print(_File, "%s\t%d\r\n", "SMissile", Game->SMissile);
	File->Print(_File, "%s\t\t0x%02X\r\n", "Item00", Game->Item00);
	File->Print(_File, "%s\t\t0x%02X\r\n", "Item01", Game->Item01);
	File->Print(_File, "%s\t\t%d\r\n", "Map", Game->Map);
	File->Print(_File, "%s\t%d\r\n", "SuitStatus", Game->SuitStatus);

	File->Print(_File, "%s\t\t%02d:%02d:%02d:%02d\r\n", "Time",
		Game->Hour, Game->Minute, Game->Second, Game->Millisecond);

	// close
	fclose(_File);

	// cleanup
	delete [] Game;

	// Terminate
	return TRUE;
}
// Checksum
BOOL ZeroMission::Update(CONST CHAR * _Filename) {

	// Open
	if(!Open(_Filename)) {return FALSE;}

	// Header
	if(!HeaderSum(&SRAM[0x00])) {return FALSE;}

	// Key - SEL_SAVE
	if(!KeySum(&SRAM[0x00], 0x6D80)) {return FALSE;}

	// Key - LANGUAGE_
	if(!KeySum(&SRAM[0x00], 0x6DC0)) {return FALSE;}

	// Key - LANGUAGE_
	if(!KeySum(&SRAM[0x00], 0x6E00)) {return FALSE;}

	// Key - SoundMode
	if(!KeySum(&SRAM[0x00], 0x6E40)) {return FALSE;}

	// Time Attack
	if(!TimeAttackSum(&SRAM[0x00])) {return FALSE;}

	// NES Metroid Save Game
	if(!MetroidPassWord(&SRAM[0x00])) {return FALSE;}

	// SaveGame
	for(UINT ID = 0; ID < 3; ID++)
	{
		if(!SetChecksum(&SRAM[0x00], ID)) {return FALSE;}
	}

	// Save
	if(!Save(_Filename)) {return FALSE;}

	// Close
	if(!Close()) {return FALSE;}

	// Terminate
	return TRUE;
}
BOOL ZeroMission::SetChecksum(UCHAR * SRAM, UINT ID) {

	// Many thanks to
	// x0_000

	// error
	if(!SRAM) {return FALSE;}

	// variable
	INT Buf = 0;
	INT Sum = 0;
	INT NegSum = 0;
	ULONG _Offset = ((0x1220 * ID) + 0x80);

	// calculate
	for(UINT n = 0; n < 1159; n++, _Offset+=0x04)
	{
		memcpy_s(&Buf, 0x04, &SRAM[_Offset], 0x04);
		Buf && 0xFFFFFFFF;
		Sum += Buf;
	}

	// negative
	NegSum = (-1 - Sum);

	// empty
	switch(Sum)
	{
	case 0xFFFFFB79:
		Sum = 0xFFFFFFFF;
		NegSum = 0xFFFFFFFF;
	break;
	}

	// original
	_Offset = ((0x1220 * ID) + 0x90);
	memcpy_s(&SRAM[_Offset], 0x04, &Sum, 0x04);
	memcpy_s(&SRAM[_Offset+4], 0x04, &NegSum, 0x04);

	// backup
	_Offset = (((0x1220 * ID) + 0x36E0) + 0x10);
	memcpy_s(&SRAM[_Offset], 0x04, &Sum, 0x04);
	memcpy_s(&SRAM[_Offset+4], 0x04, &NegSum, 0x04);

	// Terminate
	return TRUE;
}
BOOL ZeroMission::HeaderSum(UCHAR * SRAM) {

	// error
	if(!SRAM) {return FALSE;}

	// variable
	INT Buf = 0;
	INT Sum = 0;
	INT NegSum = 0;
	ULONG _Offset = 0x00;

	// calculate
	for(UINT n = 0; n < 16; n++, _Offset+=0x04)
	{
		memcpy_s(&Buf, 0x04, &SRAM[_Offset], 0x04);
		Buf && 0xFFFFFFFF;
		Sum += Buf;
	}

	// negative
	NegSum = (-1 - Sum);

	// original
	memcpy_s(&SRAM[0x00], 0x04, &Sum, 0x04);
	memcpy_s(&SRAM[0x04], 0x04, &NegSum, 0x04);

	// backup
	UCHAR * Backup = new UCHAR [0x40];
	memcpy_s(&Backup[0x00], 0x40, &SRAM[0x00], 0x40);
	memcpy_s(&SRAM[0x40], 0x40, &Backup[0x00], 0x40);
	memcpy_s(&SRAM[0x6D40], 0x40, &Backup[0x00], 0x40);
	delete [] Backup;

	// Terminate
	return TRUE;
}
BOOL ZeroMission::KeySum(UCHAR * SRAM, ULONG _Offset) {

	// error
	if(!SRAM) {return FALSE;}

	// variable
	INT Buf = 0;
	INT Sum = 0;
	INT NegSum = 0;

	// calculate
	for(UINT n = 0; n < 32; n++, _Offset+=0x02)
	{
		memcpy_s(&Buf, 0x02, &SRAM[_Offset], 0x02);
		Buf && 0xFFFFFFFF;
		Sum += Buf;
	}

	// negative
	NegSum = (-1 - Sum);

	// empty
	switch(Sum)
	{
	case 0xFFFFFFE0:
		Sum = 0xFFFF;
		NegSum = 0xFFFF;
	break;
	}

	// update
	_Offset -= 0x40;
	memcpy_s(&SRAM[_Offset+0x02], 0x02, &Sum, 0x02);
	memcpy_s(&SRAM[_Offset+0x04], 0x02, &NegSum, 0x02);

	// Terminate
	return TRUE;
}
BOOL ZeroMission::TimeAttackSum(UCHAR * SRAM) {

	// error
	if(!SRAM) {return FALSE;}

	// variable
	INT Buf = 0;
	INT Sum = 0;
	INT NegSum = 0;
	ULONG _Offset = 0x6E80;

	SHORT Additive = 0x00;
	memcpy_s(&Additive, 0x01, &SRAM[_Offset], 0x01);

	// calculate
	for(UINT n = 0; n < 64; n++, _Offset+=0x02)
	{
		memcpy_s(&Buf, 0x02, &SRAM[_Offset], 0x02);
		Buf && 0xFFFFFFFF;
		Sum += Buf;
	}

	// negative
	NegSum = (-1 - Sum);

	// empty
	switch(Sum)
	{
	case 0xFFFFFFC0:
		Sum = 0xFFFF;
		NegSum = 0xFFFF;
	break;
	default:
		Sum -= Additive;
		NegSum += Additive;
	break;
	}

	// update
	memcpy_s(&SRAM[0x6E92], 0x02, &Sum, 0x02);
	memcpy_s(&SRAM[0x6E94], 0x02, &NegSum, 0x02);

	// backup
	UCHAR * Backup = new UCHAR [0x80];
	memcpy_s(&Backup[0x00], 0x80, &SRAM[0x6E80], 0x80);
	memcpy_s(&SRAM[0x6F80], 0x80, &Backup[0x00], 0x80);
	delete [] Backup;

	// Terminate
	return TRUE;
}
BOOL ZeroMission::MetroidPassWord(UCHAR * SRAM) {

	/* error
	if(!SRAM) {return Fail("MetroidPassWord()");}

	char * Password = Common->CreateString("00200000000000W06O0000bD");

	// test
	PassWord = &IMetroidNES;
	UCHAR * Data = PassWord->Decode(Password);
	Common->Message("", "%s", PassWord->Encode(Data));

	// cleanup
	delete [] Password;
	delete [] Data;*/

	// Terminate
	return TRUE;
}