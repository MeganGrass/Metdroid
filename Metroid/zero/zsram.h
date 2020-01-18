
#define SRM		0		// SNES (Super Metroid)
#define SAV		1		// GBA (Metroid Zero Mission, Metroid Fusion)
#define SAMUS	2		// Exported Game Data

enum ZERO_MISSION_AREA {
	ZM_AREA_BRINSTAR =	0x00000000,
	ZM_AREA_KRAID =		0x00000001,
	ZM_AREA_NORFAIR =	0x00000002,
	ZM_AREA_RIDLEY =	0x00000003,
	ZM_AREA_TOURIAN =	0x00000004,
	ZM_AREA_CRATERIA =	0x00000005,
	ZM_AREA_CHOZODIA =	0x00000006
};
enum ZERO_MISSION_DIFFICULTY {
	ZM_LEVEL_EASY =		0x00000000,
	ZM_LEVEL_NORMAL =	0x00000001,
	ZM_LEVEL_HARD =		0x00000002
};
enum ZERO_MISSION_SUIT {
	ZM_SUIT_NORMAL =	0x00000000,	// Power
	ZM_SUIT_POWERED =	0x00000001,	// Varia and/or Gravity
	ZM_SUIT_NAKED =		0x00000002	// Samus
};
enum ZERO_MISSION_MAP {
	ZM_MAP_BRINSTAR =	0x00000001,
	ZM_MAP_KRAID =		0x00000002,
	ZM_MAP_NORFAIR =	0x00000004,
	ZM_MAP_RIDLEY =		0x00000008,
	ZM_MAP_TOURIAN =	0x00000010,
	ZM_MAP_CRATERIA =	0x00000020,
	ZM_MAP_CHOZODIA =	0x00000040
};
enum ZERO_MISSION_ITEM {

	ZM_ITEM_LONG =		0x00000001,
	ZM_ITEM_ICE =		0x00000002,
	ZM_ITEM_WAVE =		0x00000004,
	ZM_ITEM_PLASMA =	0x00000008,
	ZM_ITEM_CHARGE =	0x00000010,
	ZM_ITEM_NULL0 =		0x00000020,
	ZM_ITEM_NULL1 =		0x00000040,
	ZM_ITEM_BOMB =		0x00000080,

	ZM_ITEM_HIJUMP =	0x00000001,
	ZM_ITEM_SPEED =		0x00000002,
	ZM_ITEM_SPACE =		0x00000004,
	ZM_ITEM_SCREW =		0x00000008,
	ZM_ITEM_VARIA =		0x00000010,
	ZM_ITEM_GRAVITY =	0x00000020,
	ZM_ITEM_BALL =		0x00000040,
	ZM_ITEM_KADO =		0x00000080

};
enum ZERO_MISSION_EVENT {

	// 0x1200
	ZM_0 =				0x00000001,	// Normal Mode is active
	ZM_EASY =			0x00000002,	// Easy Mode is active
	ZM_HARD =			0x00000004,	// Hard Mode is active
	ZM_DMWAKEUP =		0x00000008, // Cutscene - Mother Brain
	ZM_DMRETURN =		0x00000010, // Cutscene - Ridley Pt. 1
	ZM_DMLANDING =		0x00000020, // Cutscene - Ridley Pt. 2
	ZM_DMMECHA =		0x00000040, // Cutscene - Mecha Ridley
	ZM_DMMETROID =		0x00000080,	// Cutscene - Metroids in Tourian

	// 0x1201
	ZM_LONGCHO =		0x00000001,	// Chozo Statue Hint - Long Beam
	ZM_BOMBCHO =		0x00000002,	// Chozo Statue Hint - Bomb
	ZM_ICECHO =			0x00000004,	// Chozo Statue Hint - Ice beam
	ZM_SPEEDCHO =		0x00000008,	// Chozo Statue Hint - Speed Booster
	ZM_HIJUMPCHO =		0x00000010,	// Chozo Statue Hint - Hi Jump Boots
	ZM_VARIACHO =		0x00000020,	// Chozo Statue Hint - Varia Suit
	ZM_WAVECHO =		0x00000040,	// Chozo Statue Hint - Wave Beam
	ZM_SCREWCHO =		0x00000080,	// Chozo Statue Hint - Screw Attack

	// 0x1202
	ZM_POWERHANGGET =	0x00000001,	// Crateria	// Power Grip & Geron destroyed (Norfair)
	ZM_CHOJINTOWER =	0x00000002,	// Crateria	// Power Grip Tower activated
	ZM_HIJUMP =			0x00000004,	// Norfair	// Hi Jump Boots obtained
	ZM_VARIA =			0x00000008,	// Chozodia	// Varia Suit obtained (Chozo Test)
	ZM_CHARGEGET =		0x00000010,	// Brinstar	// Charge Beam obtained
	ZM_SCREW =			0x00000020,	// Norfair	// Screw Attack obtained
	ZM_SPACEJ =			0x00000040,	// Kraid	// Unknown Item obtained
	ZM_GRAVITYGET =		0x00000080,	// Ridley	// Unknown Item obtained

	// 0x1203
	ZM_PLASMAB =		0x00000001,	// Crateria	// Unknown Item obtained
	ZM_MUKADEA =		0x00000002,	// Brinstar	// Deorem encounter
	ZM_MUKADEB =		0x00000004,	// Brinstar	// Deorem encounter
	ZM_MUKADEAORB =		0x00000008,
	ZM_WORMSHI =		0x00000010,	// Kraid	// Mua defeated
	ZM_GADORAKRAID =	0x00000020,	// Kraid	// Gadora destroyed
	ZM_KRAIDSHI =		0x00000040,	// Kraid	// Kraid defeated
	ZM_KRAIDELZO =		0x00000080,	// Brinstar	// Hidden Entrance revealed

	// 0x1204
	ZM_IMOMUSHI =		0x00000001,	// Norfair	// Larvae defeated
	ZM_SANAGIFUKA =		0x00000002,	// Norfair	// Kiru Giru incubation
	ZM_SANAGISI =		0x00000004,	// Norfair	// Kiru Giru pupa defeated
	ZM_SEICHUSI =		0x00000008,	// Ridley	// Kiru Giru imago defeated
	ZM_GADORARIDLEY =	0x00000010,	// Ridley	// Gadora destroyed
	ZM_RIDLEYSI =		0x00000020,	// Ridley	// Ridley defeated
	ZM_RIDLEYELZO =		0x00000040,	// Norfair	// Hidden Entrance revealed
	ZM_MOTHERSI =		0x00000080,	// Tourian	// Mother Brain defeated

	// 0x1205
	ZM_CROCOSI =		0x00000001,	// UNUSED	// Crocomire defeated
	ZM_GEKITAIM =		0x00000002,
	ZM_KRARIDZO =		0x00000004,	// Brinstar	// Tourian Access viewed
	ZM_DEATHGIGASI =	0x00000008,	// Brinstar	// Dessgeega defeated (Ridley)
	ZM_MERONOSU =		0x00000010,	// Brinstar	// X-78Q destroyed
	ZM_MAMEMUSHI24 =	0x00000020,	// Brinstar	// Bomb Parasites destroyed
	ZM_HANG =			0x00000040,	// Kraid	// Zip Lines activated
	ZM_TAMAGOMAME1SI =	0x00000080,	// Brinstar	// Geron destroyed

	// 0x1206
	ZM_TAMAGOMAME2SI =	0x00000001,
	ZM_TAMAGOMAME3SI =	0x00000002,	// Brinstar	// Geron destroyed
	ZM_TAMAGOMAME4SI =	0x00000004,	// Brinstar	// Geron destroyed
	ZM_TAMAGOMAME5SI =	0x00000008,	// Brinstar	// Geron destroyed
	ZM_BARISUTOSI =		0x00000010,	// Kraid	// Baristute defeated
	ZM_KRAIDZOOP =		0x00000020,	// Brinstar	// Tourian Access (Kraid)
	ZM_RIDLEYZOOP =		0x00000040,	// Brinstar	// Tourian Access (Ridley)
	ZM_METOCHUSI =		0x00000080,	// Tourian	// Metroids were defeated (1)

	// 0x1207
	ZM_METSIROOM1 =		0x00000001,	// Tourian	// Metroids were defeated (3)
	ZM_METSIROOM2 =		0x00000002,	// Tourian	// Metroids were defeated (5)
	ZM_METSIROOM3 =		0x00000004,	// Tourian	// Metroids were defeated (2)
	ZM_METSIROOM4 =		0x00000008,	// Tourian	// Metroids were defeated (6)
	ZM_METSIROOM5 =		0x00000010,	// Tourian	// Metroids were defeated (4)
	ZM_ZEBETAITO1SI =	0x00000020,	// Tourian	// Zebetite destroyed (1)
	ZM_ZEBETAITO2SI =	0x00000040,	// Tourian	// Zebetite destroyed (2)
	ZM_ZEBETAITO3SI =	0x00000080,	// Tourian	// Zebetite destroyed (3)

	// 0x1208
	ZM_ZEBETAITO4SI =	0x00000001,	// Tourian	// Zebetite destroyed (4)
	ZM_ESCAPE1 =		0x00000002,	// Crateria	// Escape Sequence
	ZM_AFROHAKKEN =		0x00000004,
	ZM_POWSUITGET =		0x00000008,	// Chozodia	// Power Suit obtained (Chozo Test)
	ZM_VARIATYOKU =		0x00000010,	// Chozodia	// Varia Suit obtained (Chozo Test)
	ZM_CHOZOBLOCK =		0x00000020,
	ZM_LASTPBOMB =		0x00000040,	// Chozodia	// P.Bomb disappeared
	ZM_PBOMBZEBES1 =	0x00000080,	// Chozodia	// P.Bomb was moved by Space Pirate

	// 0x1209
	ZM_PBOMBZEBES2 =	0x00000001,
	ZM_GLASSTUBE =		0x00000002,	// Chozodia	// Glass Tube destroyed
	ZM_MECHARIDLEYS =	0x00000004,	// Chozodia	// Mecha Ridley defeated
	ZM_LASTESCAPE =		0x00000008,	// Chozodia // Cutscene - Escape Sequence
	ZM_AKI =			0x00000010,
	ZM_BOMBGATE =		0x00000020,
	ZM_END =			0x00000040

};
// 2038000	// Metroid Zero Mission
typedef struct tagZeroSaveGame {
	/* 0x0000 */	CHAR Magic1[0x10];		// ZERO_MISSION_010
	/* 0x0010 */	INT Checksum;			// Check sum of individual savegame
	/* 0x0014 */	INT NegSum;				// Negative of Check sum
	/* 0x0018 */	UCHAR MissionComplete;	// 00=NO, 01=YES	Game Previously Completed?
	/* 0x0019 */	UCHAR unk00;
	/* 0x001A */	UCHAR unk01;
	/* 0x001B */	UCHAR unk02;
	/* 0x001C */	UCHAR NewGame;			// 00=YES, 01=NO	Begin New Game?
	/* 0x001D */	UCHAR Area;				// Area ID
	/* 0x001E */	UCHAR RoomPrev;			// Previous Room ID
	/* 0x001F */	UCHAR RoomCur;			// Current Room ID

	UCHAR unk03[0x1C];

	/* 0x003C */	UCHAR Difficulty;		// 00=EASY, 01=NORMAL, 02=HARD
	/* 0x003D */	UCHAR DoorType;			// 00=Zebes, 01=Ship
	/* 0x003E */	USHORT TimeAttack;		// 00=NO, 01=YES	Time-Attack Mode?

	UCHAR unk04[0x10];

	/* 0x004F */	CHAR Magic2[0x10];		// Planet Zebes... 

	UCHAR unk05[0x13D];

	/* 0x019C */	USHORT HealthMax;		// Maximum Health Capacity
	/* 0x019E */	USHORT MissileMax;		// Maximum Missile Capacity
	/* 0x01A0 */	UCHAR SMissileMax;		// Maximum Super Missile Capacity
	/* 0x01A1 */	UCHAR PBombMax;			// Maximum Power Bomb Capacity
	/* 0x01A2 */	USHORT Health;			// Current Health Count
	/* 0x01A4 */	USHORT Missile;			// Current Missile Count
	/* 0x01A6 */	UCHAR SMissile;			// Current Super Missile Count
	/* 0x01A7 */	UCHAR PBomb;			// Current Power Bomb Count
	/* 0x01A8 */	USHORT Item00;			// Item Collection (bitfield)
	/* 0x01AA */	USHORT Item01;			// Item Collection (bitfield)
	/* 0x01AC */	USHORT Map;				// Map Collection (bitfield)
	/* 0x01AE */	USHORT SuitStatus;		// Suit Status

	UCHAR unk06[0x48];

	/* 0x01FC */	UCHAR Hour;				// Gameplay Time (Current)
	/* 0x01FD */	UCHAR Minute;			// Gameplay Time (Current)
	/* 0x01FE */	UCHAR Second;			// Gameplay Time (Current)
	/* 0x01FF */	UCHAR Millisecond;		// Gameplay Time (Current)

	UCHAR unk07[0x14];

	/* 0x0214 */	UCHAR HourComplete;		// Gameplay Time (Time Attack)
	/* 0x0215 */	UCHAR MinuteComplete;	// Gameplay Time (Time Attack)
	/* 0x0216 */	UCHAR SecondComplete;	// Gameplay Time (Time Attack)
	/* 0x0217 */	UCHAR MilliComplete;	// Gameplay Time (Time Attack)

	UCHAR unk08[0x38];

	/* 0x0250 */	CHAR Magic3[0x10];		//  - Samus Aran - 

	UCHAR unk0A[0xFA0];

	/* 0x1200 */
	union uEvent {
		UCHAR Event[10];
		struct {

			// 0x1200
			UINT ZERO:1;			// Normal Mode is active
			UINT EASY:1;			// Easy Mode is active
			UINT HARD:1;			// Hard Mode is active
			UINT DMWAKEUP:1;		// Cutscene - Mother Brain
			UINT DMRETURN:1;		// Cutscene - Ridley Pt. 1
			UINT DMLANDING:1;		// Cutscene - Ridley Pt. 2
			UINT DMMECHA:1;			// Cutscene - Mecha Ridley
			UINT DMMETROID:1;		// Cutscene - Metroids in Tourian

			// 0x1201
			UINT LONGCHO:1;			// Chozo Statue Hint - Long Beam
			UINT BOMBCHO:1;			// Chozo Statue Hint - Bomb
			UINT ICECHO:1;			// Chozo Statue Hint - Ice beam
			UINT SPEEDCHO:1;		// Chozo Statue Hint - Speed Booster
			UINT HIJUMPCHO:1;		// Chozo Statue Hint - Hi Jump Boots
			UINT VARIACHO:1;		// Chozo Statue Hint - Varia Suit
			UINT WAVECHO:1;			// Chozo Statue Hint - Wave Beam
			UINT SCREWCHO:1;		// Chozo Statue Hint - Screw Attack

			// 0x1202
			UINT POWERHANGGET:1;	// Crateria	// Power Grip & Geron destroyed (Norfair)
			UINT CHOJINTOWER:1;		// Crateria	// Power Grip Tower activated
			UINT HIJUMP:1;			// Norfair	// Hi Jump Boots obtained
			UINT VARIA:1;			// Chozodia	// Varia Suit obtained (Chozo Test)
			UINT CHARGEGET:1;		// Brinstar	// Charge Beam obtained
			UINT SCREW:1;			// Norfair	// Screw Attack obtained
			UINT SPACEJ:1;			// Kraid	// Unknown Item obtained
			UINT GRAVITYGET:1;		// Ridley	// Unknown Item obtained

			// 0x1203
			UINT PLASMAB:1;			// Crateria	// Unknown Item obtained
			UINT MUKADEA:1;			// Brinstar	// Deorem encounter
			UINT MUKADEB:1;			// Brinstar	// Deorem encounter
			UINT MUKADEAORB:1;
			UINT WORMSHI:1;			// Kraid	// Mua defeated
			UINT GADORAKRAID:1;		// Kraid	// Gadora destroyed
			UINT KRAIDSHI:1;		// Kraid	// Kraid defeated
			UINT KRAIDELZO:1;		// Brinstar	// Hidden Entrance revealed

			// 0x1204
			UINT IMOMUSHI:1;		// Norfair	// Larvae defeated
			UINT SANAGIFUKA:1;		// Norfair	// Kiru Giru incubation
			UINT SANAGISI:1;		// Norfair	// Kiru Giru pupa defeated
			UINT SEICHUSI:1;		// Ridley	// Kiru Giru imago defeated
			UINT GADORARIDLEY:1;	// Ridley	// Gadora destroyed
			UINT RIDLEYSI:1;		// Ridley	// Ridley defeated
			UINT RIDLEYELZO:1;		// Norfair	// Hidden Entrance revealed
			UINT MOTHERSI:1;		// Tourian	// Mother Brain defeated

			// 0x1205
			UINT CROCOSI:1;			// UNUSED	// Crocomire defeated
			UINT GEKITAIM:1;
			UINT KRARIDZO:1;		// Brinstar	// Tourian Access viewed
			UINT DEATHGIGASI:1;		// Brinstar	// Dessgeega defeated (Ridley)
			UINT MERONOSU:1;		// Brinstar	// X-78Q destroyed
			UINT MAMEMUSHI24:1;		// Brinstar	// Bomb Parasites destroyed
			UINT HANG:1;			// Kraid	// Zip Lines activated
			UINT TAMAGOMAME1SI:1;	// Brinstar	// Geron destroyed

			// 0x1206
			UINT TAMAGOMAME2SI:1;
			UINT TAMAGOMAME3SI:1;	// Brinstar	// Geron destroyed
			UINT TAMAGOMAME4SI:1;	// Brinstar	// Geron destroyed
			UINT TAMAGOMAME5SI:1;	// Brinstar	// Geron destroyed
			UINT BARISUTOSI:1;		// Kraid	// Baristute defeated
			UINT KRAIDZOOP:1;		// Brinstar	// Tourian Access (Kraid)
			UINT RIDLEYZOOP:1;		// Brinstar	// Tourian Access (Ridley)
			UINT METOCHUSI:1;		// Tourian	// Metroids were defeated (1)

			// 0x1207
			UINT METSIROOM1:1;		// Tourian	// Metroids were defeated (3)
			UINT METSIROOM2:1;		// Tourian	// Metroids were defeated (5)
			UINT METSIROOM3:1;		// Tourian	// Metroids were defeated (2)
			UINT METSIROOM4:1;		// Tourian	// Metroids were defeated (6)
			UINT METSIROOM5:1;		// Tourian	// Metroids were defeated (4)
			UINT ZEBETAITO1SI:1;	// Tourian	// Zebetite destroyed (1)
			UINT ZEBETAITO2SI:1;	// Tourian	// Zebetite destroyed (2)
			UINT ZEBETAITO3SI:1;	// Tourian	// Zebetite destroyed (3)

			// 0x1208
			UINT ZEBETAITO4SI:1;	// Tourian	// Zebetite destroyed (4)
			UINT ESCAPE1:1;			// Crateria	// Escape Sequence
			UINT AFROHAKKEN:1;
			UINT POWSUITGET:1;		// Chozodia	// Power Suit obtained (Chozo Test)
			UINT VARIATYOKU:1;		// Chozodia	// Varia Suit obtained (Chozo Test)
			UINT CHOZOBLOCK:1;
			UINT LASTPBOMB:1;		// Chozodia	// P.Bomb disappeared
			UINT PBOMBZEBES1:1;		// Chozodia	// P.Bomb was moved by Space Pirate

			// 0x1209
			UINT PBOMBZEBES2:1;
			UINT GLASSTUBE:1;		// Chozodia	// Glass Tube destroyed
			UINT MECHARIDLEYS:1;	// Chozodia	// Mecha Ridley defeated
			UINT LASTESCAPE:1;		// Chozodia // Cutscene - Escape Sequence
			UINT AKI:1;
			UINT BOMBGATE:1;
			UINT END:1;
			UINT UNUSED:1;			// Unused

		} Flags;
	} Event;	// 0x50

	UCHAR unk0B[0x14];

} ZeroSaveGame;
class ZeroMission {
private:
public:

	// framework
	System_File * File;

	// variable
	CONST CHAR * Dir;
	UINT DateType;
	UCHAR * SRAM;
	ZeroSaveGame * Game;
//	MetroidNES IMetroidNES, * PassWord;

	// boot
	ZeroMission(VOID) {}
	~ZeroMission(VOID) {}

	// sram
	BOOL Open(CONST CHAR * _Filename);
	BOOL Save(CONST CHAR * _Filename);
	BOOL Close(VOID);

	// game
	BOOL Export(UINT ID);
	BOOL Export(UINT ID, CONST CHAR * SaveRAM);

	BOOL Import(UINT ID, CONST CHAR * GameSAV);
	BOOL Import(UINT ID, CONST CHAR * SaveRAM, CONST CHAR * GameSAV);

	BOOL Clear(UINT ID);
	BOOL Clear(UINT ID, CONST CHAR * SaveRAM);

	BOOL Copy(UINT ID1, UINT ID2);
	BOOL Copy(UINT ID1, UINT ID2, CONST CHAR * SaveRAM);

	// modification
	BOOL Disassemble(CONST CHAR * _Filename);
	BOOL Disassemble(UCHAR * SRAM, UINT ID);

	// checksum
	BOOL Update(CONST CHAR * _Filename);
	BOOL SetChecksum(UCHAR * SRAM, UINT ID);
	BOOL HeaderSum(UCHAR * SRAM);
	BOOL KeySum(UCHAR * SRAM, ULONG _Offset);
	BOOL TimeAttackSum(UCHAR * SRAM);

	// orignal metroid
	BOOL MetroidPassWord(UCHAR * SRAM);

};