
enum FUSION_AREA {
	F_AREA_MAIN_DECK =	0x00000000,
	F_AREA_SECTOR_1 =	0x00000001,
	F_AREA_SECTOR_2 =	0x00000002,
	F_AREA_SECTOR_3 =	0x00000003,
	F_AREA_SECTOR_4 =	0x00000004,
	F_AREA_SECTOR_5 =	0x00000005,
	F_AREA_SECTOR_6 =	0x00000006,
	F_AREA_DEBUG =		0x00000007
};
enum FUSION_MAP {
	F_MAP_MAIN_DECK =	0x00000001,
	F_MAP_SECTOR_1 =	0x00000002,
	F_MAP_SECTOR_2 =	0x00000004,
	F_MAP_SECTOR_3 =	0x00000008,
	F_MAP_SECTOR_4 =	0x00000010,
	F_MAP_SECTOR_5 =	0x00000020,
	F_MAP_SECTOR_6 =	0x00000040
};
enum FUSION_LOCK {
	F_CLEARANCE_L1 =	0x00000001,
	F_CLEARANCE_L2 =	0x00000002,
	F_CLEARANCE_L3 =	0x00000003,
	F_CLEARANCE_L4 =	0x00000004
};
enum FUSION_ITEM {
	F_ITEM_MISSILE =	0x00000001,
};
// 2038000	// Metroid Fusion
struct FusionSaveGame {
	/* 0x0000 */	char Magic1[0x10];				// MetroidEpisode4A
	/* 0x0010 */	signed int Checksum;
	/* 0x0014 */	signed int NegSum;				// Negative of Checksum
	/* 0x0018 */	unsigned char MissionComplete;	// 00=NO, 01=YES
	/* 0x0019 */	unsigned char unk00;
	/* 0x001A */	unsigned char unk01;
	/* 0x001B */	unsigned char unk02;
	/* 0x001C */	unsigned char NewGame;			// 00=YES, 01=NO
	/* 0x001D */	unsigned char Area;				// Area ID
	/* 0x001E */	unsigned char RoomPrev;			// Previous Room ID
	/* 0x001F */	unsigned char RoomCur;			// Current Room ID

	/* 0x00C4 */	unsigned short int Health;		// Current Health Count
	/* 0x00C6 */	unsigned short int HealthMax;	// Maximum Health Capacity
	/* 0x00C8 */	unsigned short int Missile;		// Current Missile Count
	/* 0x00CA */	unsigned short int MissileMax;	// Maximum Missile Capacity
	/* 0x00CC */	unsigned char PBomb;			// Current Power Bomb Count
	/* 0x00CD */	unsigned char PBombMax;			// Maximum Power Bomb Capacity
	/* 0x00CE */	unsigned char Beam;				// Beam Collection
	/* 0x00CF */	unsigned short int Item;		// Item Collection
	/* 0x00D1 */	unsigned char DoorLock;			// Security Clearance
	/* 0x00D2 */	unsigned short int Map;			// Map Collection
};
class Fusion {
private:
public:

	// variable
	CHAR * Dir;
	UINT DateType;
	UCHAR * SRAM;
	FusionSaveGame * Game;

	// framework
	System_File * File;

	// boot
	Fusion(VOID) {}
	~Fusion(VOID) {}

	// sram
	BOOL Open(CONST CHAR * _Filename);
	BOOL Save(CONST CHAR * _Filename);
	VOID Close(VOID);

	// game
	BOOL Export(INT ID);
	BOOL Export(INT ID, CONST CHAR * SaveRAM);

	BOOL Import(INT ID, CONST CHAR * GameSAV);
	BOOL Import(INT ID, CONST CHAR * SaveRAM, CONST CHAR * GameSAV);

	BOOL Clear(INT ID);
	BOOL Clear(INT ID, CONST CHAR * SaveRAM);

	// checksum
	BOOL Update(CONST CHAR* _Filename);
	BOOL SetChecksum(UCHAR * SRAM, INT ID);

};
