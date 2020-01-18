
enum AREA {

	CRATERIA =		0x00000000,
	BRINSTAR =		0x00000001,
	NORFAIR =		0x00000002,
	WRECKED_SHIP =	0x00000003,
	MARIDIA =		0x00000004,
	TOURIAN =		0x00000005,
	CERES_COLONY =	0x00000006

};
enum CONFIG {

	// 0x40
	CONFIG_0x40_00 =0x00000001,	// Language

	// 0x42
	CONFIG_0x42_00 =0x00000001,	// Moon Walk

	// 0x48
	CONFIG_0x48_00 =0x00000000,	// Icon Cancel (manual)
	CONFIG_0x48_01 =0x00000001,	// Icon Cancel (automatic)

};
enum EVENT {

	// 0x60						// AREA			// INFO
	EVENT_0x60_00 =	0x00000001,	// Crateria		// Planet Zebes becomes active
	EVENT_0x60_01 =	0x00000002,	// 
	EVENT_0x60_02 =	0x00000004,	// Tourian		// Mother Brain's glass shield destroyed
	EVENT_0x60_03 =	0x00000008,	// 
	EVENT_0x60_04 =	0x00000010,	// 
	EVENT_0x60_05 =	0x00000020,	// Tourian		// Mother Brain's zebetites destroyed
	EVENT_0x60_06 =	0x00000040,	// Crateria		// Phantoon statue defunct
	EVENT_0x60_07 =	0x00000080,	// Crateria		// Ridley statue defunct

	// 0x61
	EVENT_0x61_00 =	0x00000001,	// Crateria		// Draygon statue defunct
	EVENT_0x61_01 =	0x00000002,	// Crateria		// Kraid statue defunct
	EVENT_0x61_02 =	0x00000004,	// Crateria		// Tourian elevator accessible
	EVENT_0x61_03 =	0x00000008,	// Maridia		// Glass tube broken
	EVENT_0x61_04 =	0x00000010,	// Norfair		// Chozo statue caused lava disappearance
	EVENT_0x61_05 =	0x00000020,	// Maridia		// Pathway to Spring Ball cleared
	EVENT_0x61_06 =	0x00000040,	// Crateria		// Ready to explode
	EVENT_0x61_07 =	0x00000080,	// Crateria		// Rescued animals during escape

	// 0x62
	EVENT_0x62_00 =	0x00000001,	// Tourian		// Metroids destroyed
	EVENT_0x62_01 =	0x00000002,	// Tourian		// Metroids destroyed
	EVENT_0x62_02 =	0x00000004,	// Tourian		// Metroids destroyed
	EVENT_0x62_03 =	0x00000008,	// Tourian		// Metroids destroyed
	EVENT_0x62_04 =	0x00000010, // 
	EVENT_0x62_05 =	0x00000020, // Norfair		// Pathway to Speed Boost flooded
	EVENT_0x62_06 =	0x00000040, // 
	EVENT_0x62_07 =	0x00000080, // 

	// 0x68
	EVENT_0x68_00 =	0x00000001,	// 
	EVENT_0x68_01 =	0x00000002,	// 
	EVENT_0x68_02 =	0x00000004,	// Crateria		// Silver Torizo defeated
	EVENT_0x68_03 =	0x00000008,	// 
	EVENT_0x68_04 =	0x00000010,	// 
	EVENT_0x68_05 =	0x00000020,	// 
	EVENT_0x68_06 =	0x00000040,	// 
	EVENT_0x68_07 =	0x00000080,	// 

	// 0x69
	EVENT_0x69_00 =	0x00000001,	// Brinstar		// Kraid defeated
	EVENT_0x69_01 =	0x00000002,	// Brinstar		// Spore Spawn defeated
	EVENT_0x69_02 =	0x00000004,	// 
	EVENT_0x69_03 =	0x00000008,	// 
	EVENT_0x69_04 =	0x00000010,	// 
	EVENT_0x69_05 =	0x00000020,	// 
	EVENT_0x69_06 =	0x00000040,	// 
	EVENT_0x69_07 =	0x00000080,	// 

	// 0x6A
	EVENT_0x6A_00 =	0x00000001,	// Norfair		// Ridley defeated
	EVENT_0x6A_01 =	0x00000002,	// Norfair		// Crocomire defeated
	EVENT_0x6A_02 =	0x00000004,	// Norfair		// Golden Torizo defeated
	EVENT_0x6A_03 =	0x00000008,	// 
	EVENT_0x6A_04 =	0x00000010,	// 
	EVENT_0x6A_05 =	0x00000020,	// 
	EVENT_0x6A_06 =	0x00000040,	// 
	EVENT_0x6A_07 =	0x00000080,	// 

	// 0x6B
	EVENT_0x6B_00 =	0x00000001,	// Wrecked Ship	// Phantoon defeated
	EVENT_0x6B_01 =	0x00000002,	// 
	EVENT_0x6B_02 =	0x00000004,	// 
	EVENT_0x6B_03 =	0x00000008,	// 
	EVENT_0x6B_04 =	0x00000010,	// 
	EVENT_0x6B_05 =	0x00000020,	// 
	EVENT_0x6B_06 =	0x00000040,	// 
	EVENT_0x6B_07 =	0x00000080,	// 

	// 0x6C
	EVENT_0x6C_00 =	0x00000001,	// Maridia		// Draygon defeated
	EVENT_0x6C_01 =	0x00000002,	// Maridia		// Botwoon defeated
	EVENT_0x6C_02 =	0x00000004,	// 
	EVENT_0x6C_03 =	0x00000008,	// 
	EVENT_0x6C_04 =	0x00000010,	// 
	EVENT_0x6C_05 =	0x00000020,	// 
	EVENT_0x6C_06 =	0x00000040,	// 
	EVENT_0x6C_07 =	0x00000080,	// 

	// 0x6D
	EVENT_0x6D_00 =	0x00000001,	// Tourian		// Mother Brain defeated
	EVENT_0x6D_01 =	0x00000002,	// Tourian		// Mother Brain defeated
	EVENT_0x6D_02 =	0x00000004,	// 
	EVENT_0x6D_03 =	0x00000008,	// 
	EVENT_0x6D_04 =	0x00000010,	// 
	EVENT_0x6D_05 =	0x00000020,	// 
	EVENT_0x6D_06 =	0x00000040,	// 
	EVENT_0x6D_07 =	0x00000080,	// 

	// 0x6E
	EVENT_0x6E_00 =	0x00000001,	// Ceres Colony	// Ridley defeated
	EVENT_0x6E_01 =	0x00000002,	// 
	EVENT_0x6E_02 =	0x00000002,	// 
	EVENT_0x6E_03 =	0x00000002,	// 
	EVENT_0x6E_04 =	0x00000010,	// 
	EVENT_0x6E_05 =	0x00000020,	// 
	EVENT_0x6E_06 =	0x00000040,	// 
	EVENT_0x6E_07 =	0x00000080,	// 

	// 0xB0
	EVENT_0xB0_00 =	0x00000001,	// 
	EVENT_0xB0_01 =	0x00000002,	// 
	EVENT_0xB0_02 =	0x00000004,	// 
	EVENT_0xB0_03 =	0x00000008,	// 
	EVENT_0xB0_04 =	0x00000010,	// 
	EVENT_0xB0_05 =	0x00000020,	// Crateria		// 7965B // Energy Tank obtained
	EVENT_0xB0_06 =	0x00000040,	// 
	EVENT_0xB0_07 =	0x00000080,	// Crateria		// 79804 // Bomb obtained

	// 0xB1
	EVENT_0xB1_00 =	0x00000001,	// Crateria		// 7990D // Energy Tank obtained
	EVENT_0xB1_01 =	0x00000002,	// Crateria		// 799BD // Missile obtained
	EVENT_0xB1_02 =	0x00000004,	// 
	EVENT_0xB1_03 =	0x00000008,	// 
	EVENT_0xB1_04 =	0x00000010,	// 
	EVENT_0xB1_05 =	0x00000020,	// 
	EVENT_0xB1_06 =	0x00000040,	// 
	EVENT_0xB1_07 =	0x00000080,	// 

};
enum OPCODE {

	// 7E0998

	ROUTINE_00 =	0x00000000,	// Title Screen
	ROUTINE_01 =	0x00000001,	// 
	ROUTINE_02 =	0x00000002,	// Option Mode
	ROUTINE_03 =	0x00000003,	// 
	ROUTINE_04 =	0x00000004,	// Samus Data
	ROUTINE_05 =	0x00000005,	// Planet Zebes Map
	ROUTINE_06 =	0x00000006,	// Gameplay Initialization
	ROUTINE_07 =	0x00000007,	// Gameplay
	ROUTINE_08 =	0x00000008,	// Gameplay (active)
	ROUTINE_09 =	0x00000009,	// 
	ROUTINE_0A =	0x0000000A,	// Disable Joypad
	ROUTINE_0B =	0x0000000B,	// Door Transition
	ROUTINE_0C =	0x0000000C,	// Room Initialization
	ROUTINE_0D =	0x0000000D,	// Start Button Menu Initialization
	ROUTINE_0E =	0x0000000E,	// Start Button Menu
	ROUTINE_0F =	0x0000000F,	// Start Button Menu (active)
	ROUTINE_10 =	0x00000010,	// 
	ROUTINE_11 =	0x00000011,	// 
	ROUTINE_12 =	0x00000012,	// 
	ROUTINE_13 =	0x00000013,	// 
	ROUTINE_14 =	0x00000014,	// Death
	ROUTINE_15 =	0x00000015,	// Game Over Screen
	ROUTINE_16 =	0x00000016,	// 
	ROUTINE_17 =	0x00000017,	// 
	ROUTINE_18 =	0x00000018,	// 
	ROUTINE_19 =	0x00000019,	// 
	ROUTINE_1A =	0x0000001A,	// Game Over Screen (NES font type)
	ROUTINE_1B =	0x0000001B,	// 
	ROUTINE_1C =	0x0000001C,	// 
	ROUTINE_1D =	0x0000001D,	// "Would You Play?"
	ROUTINE_1E =	0x0000001E,	// "The last Metroid is in captivity..."
	ROUTINE_1F =	0x0000001F,	// Continue/New Game
	ROUTINE_20 =	0x00000020,	// 
	ROUTINE_21 =	0x00000021,	// 
	ROUTINE_22 =	0x00000022,	// Ceres Colony Explosion (Samus Escapes)
	ROUTINE_23 =	0x00000023,	// 
	ROUTINE_24 =	0x00000024,	// Ceres Colony Explosion (Samus Dies)
	ROUTINE_25 =	0x00000025,	// 
	ROUTINE_26 =	0x00000026,	// Planet Zebes Explosion
	ROUTINE_27 =	0x00000027,	// Staff Roll
	ROUTINE_28 =	0x00000028,	// Gameplay Demo
	ROUTINE_29 =	0x00000029,	// 
	ROUTINE_2A =	0x0000002A,	// 
	ROUTINE_2B =	0x0000002B,	// Gameplay Demo, Title Screen
	ROUTINE_2C =	0x0000002C,	// 
	ROUTINE_2D =	0x0000002D,	// 
	ROUTINE_2E =	0x0000002E,	// 
	ROUTINE_2F =	0x0000002F,	// 

};
enum ENEMY {

	NODATA =		0x00000000,	// E2F3	// 
	ATOMIC =		0x00000001,	// E2F6	// 
	BANG =			0x00000002,	// E309	// 
	BATTA1 =		0x00000003,	// E33C	// 
	BATTA2 =		0x00000004,	// E34F	// 
	BATTA3 =		0x00000005,	// E362	// 
	BOTOON =		0x00000006,	// E375	// 
	BOYON =			0x00000007,	// E388	// 
	DESSGEEGA =		0x00000008,	// E39B	// 
	DORI =			0x00000009,	// E3AE	// 
	DRAGON =		0x0000000A,	// E421	// 
	EBI =			0x0000000B,	// E444	// 
	EYE =			0x0000000C,	// E477	// 
	NAMI =			0x0000000D,	// E49A	// 
	FISH =			0x0000000E,	// E4AD	// 
	GAI =			0x0000000F,	// E4C0	// 
	GAMET =			0x00000010,	// E4D3	// 
	GEEGA =			0x00000011,	// E526	// 
	GERUDA =		0x00000012,	// E539	// 
	GRAVY =			0x00000013,	// E55C	// 
	HACHI1 =		0x00000014,	// E55F	// 
	HAND =			0x00000015,	// E582	// 
	HIBASHI =		0x00000016,	// E595	// 
	HIRU =			0x00000017,	// E5B8	// 
	HOLTZ =			0x00000018,	// E5CB	// 
	HOTARY =		0x00000019,	// E5EE	// 
	HZOOMER =		0x0000001A,	// E601	// 
	KAGO =			0x0000001B,	// E614	// 
	KAME =			0x0000001C,	// E627	// 
	KAMER =			0x0000001D,	// E67A	// 
	KANI =			0x0000001E,	// E68D	// 
	KOMA =			0x0000001F,	// E6A0	// 
	KZAN =			0x00000020,	// E6B3	// 
	LAVAMAN =		0x00000021,	// E6D6	// 
	MELLA =			0x00000022,	// E709	// 
	MEMU =			0x00000023,	// E71C	// 
	MERO =			0x00000024,	// E72F	// 
	METALEE =		0x00000025,	// E742	// 
	METMOD =		0x00000026,	// E755	// 
	METROID =		0x00000027,	// E768	// 
	MULTI =			0x00000028,	// E77B	// 
	MZOOMER =		0x00000029,	// E78E	// 
	NDRA =			0x0000002A,	// E7A1	// 
	NOMI =			0x0000002B,	// E7B4	// 
	NOVA =			0x0000002C,	// E7C7	// 
	OUM =			0x0000002D,	// E7DA	// 
	OUMU =			0x0000002E,	// E7ED	// 
	PIPE =			0x0000002F,	// E800	// 
	POLYP =			0x00000030,	// E813	// 
	PUROMI =		0x00000031,	// E826	// 
	PUU =			0x00000032,	// E839	// 
	PUYO =			0x00000033,	// E85C	// 
	REFLEC =		0x00000034,	// E86F	// 
	RINKA =			0x00000035,	// E882	// 
	RIO =			0x00000036,	// E895	// 
	RIPPER =		0x00000037,	// E8A8	// 
	RIPPER2 =		0x00000038,	// E8BB	// 
	ROBO =			0x00000039,	// E8CE	// 
	RSTONE =		0x0000003A,	// E8E1	// 
	SABOTEN =		0x0000003B,	// E8F4	// 
	SBUG =			0x0000003C,	// E907	// 
	SCLAYD =		0x0000003D,	// E91A	// 
	SDEATH =		0x0000003E,	// E92D	// 
	SHUTTER =		0x0000003F,	// E940	// 
	SHUTTER2 =		0x00000040,	// E953	// 
	SIDE =			0x00000041,	// E966	// 
	SKREE =			0x00000042,	// E979	// 
	SPA =			0x00000043,	// E98C	// 
	SQUEEWPT =		0x00000044,	// E99F	// 
	SSIDE =			0x00000045,	// E9C2	// 
	STOKE =			0x00000046,	// E9D5	// 
	TOGE =			0x00000047,	// E9E8	// 
	VIOLA =			0x00000048,	// E9FB	// 
	WAVER =			0x00000049,	// EA0E	// 
	YARD =			0x0000004A,	// EA21	// 
	ZEB =			0x0000004B,	// EA34	// 
	ZEBBO =			0x0000004C,	// EA47	// 
	ZEELA =			0x0000004D,	// EA5A	// 
	ZOA =			0x0000004E,	// EA6D	// 
	ZOOMER =		0x0000004F,	// EA80	// 
	BATTA1Br =		0x00000050,	// EA93	// 
	BATTA1No =		0x00000051,	// EAA6	// 
	BATTA1Na =		0x00000052,	// EAB9	// 
	BATTA1Ma =		0x00000053,	// EACC	// 
	BATTA1Tu =		0x00000054,	// EADF	// 
	BATTA2Br =		0x00000055,	// EAF2	// 
	BATTA2No =		0x00000056,	// EB05	// 
	BATTA2Na =		0x00000057,	// EB18	// 
	BATTA2Ma =		0x00000058,	// EB2B	// 
	BATTA2Tu =		0x00000059,	// EB3E	// 
	BATTA3Br =		0x0000005A,	// EB51	// 
	BATTA3No =		0x0000005B,	// EB64	// 
	BATTA3Na =		0x0000005C,	// EB77	// 
	BATTA3Ma =		0x0000005D,	// EB8A	// 
	BATTA3Tu =		0x0000005E,	// EB9D	// 
	FUNE =			0x0000005F,	// EBB0	// 
	HACHI2 =		0x00000060,	// EBC3	// 
	HACHI3 =		0x00000061,	// EBE6	// 
	ROBO2 =			0x00000062,	// EC09	// 

};
// 7E09A2	// Super Metroid
typedef struct tagSuperMetroid {

	union uItemEquip {
		USHORT Equip;
		struct {

			UCHAR VARIA_SUIT:1;
			UCHAR SPRING_BALL:1;
			UCHAR MORPH_BALL:1;
			UCHAR SCREW_ATTACK:1;
			UCHAR RESERVED00:1;			// unused
			UCHAR GRAVITY_SUIT:1;
			UCHAR RESERVED01:1;			// unused
			UCHAR RESERVED02:1;			// unused
			UCHAR HIGH_JUMP:1;
			UCHAR SPACE_JUMP:1;
			UCHAR RESERVED03:1;			// unused
			UCHAR RESERVED04:1;			// unused
			UCHAR BOMB:1;
			UCHAR SPEED_BOOSTER:1;
			UCHAR GRAPPLING_BEAM:1;
			UCHAR XRAY_VISOR:1;

		} Item;
	} ItemEquip;
	union uItemMenu {
		USHORT Menu;
		struct {

			UCHAR VARIA_SUIT:1;
			UCHAR SPRING_BALL:1;
			UCHAR MORPH_BALL:1;
			UCHAR SCREW_ATTACK:1;
			UCHAR RESERVED00:1;			// unused
			UCHAR GRAVITY_SUIT:1;
			UCHAR RESERVED01:1;			// unused
			UCHAR RESERVED02:1;			// unused
			UCHAR HIGH_JUMP:1;
			UCHAR SPACE_JUMP:1;
			UCHAR RESERVED03:1;			// unused
			UCHAR RESERVED04:1;			// unused
			UCHAR BOMB:1;
			UCHAR SPEED_BOOSTER:1;
			UCHAR GRAPPLING_BEAM:1;
			UCHAR XRAY_VISOR:1;

		} Item;
	} ItemMenu;
	union uBeamEquip {
		USHORT Equip;
		struct {

			UCHAR WAVE_BEAM:1;			// 01
			UCHAR ICE_BEAM:1;			// 02
			UCHAR SPAZER_BEAM:1;		// 04
			UCHAR PLASMA_BEAM:1;		// 08
			UCHAR RAPID_BEAM:1;			// 10
			UCHAR RESERVED00:1;			// unused
			UCHAR RESERVED01:1;			// unused
			UCHAR RESERVED02:1;			// unused
			UCHAR MISSILE00:1;
			UCHAR SUPER_MISSILE:1;
			UCHAR MISSILE01:1;
			UCHAR BOMB:1;
			UCHAR CHARGE_BEAM:1;
			UCHAR RESERVED03:1;			// unused
			UCHAR RESERVED04:1;			// unused
			UCHAR RESERVED05:1;			// unused

		} Beam;
	} BeamEquip;
	union uBeamMenu {
		USHORT Menu;
		struct {

			UCHAR WAVE_BEAM:1;
			UCHAR ICE_BEAM:1;
			UCHAR SPAZER_BEAM:1;
			UCHAR PLASMA_BEAM:1;
			UCHAR RAPID_BEAM:1;
			UCHAR RESERVED00:1;			// unused
			UCHAR RESERVED01:1;			// unused
			UCHAR RESERVED02:1;			// unused
			UCHAR MISSILE00:1;
			UCHAR SUPER_MISSILE:1;
			UCHAR MISSILE01:1;
			UCHAR BOMB:1;
			UCHAR CHARGE_BEAM:1;
			UCHAR RESERVED03:1;			// unused
			UCHAR RESERVED04:1;			// unused
			UCHAR RESERVED05:1;			// unused

		} Beam;
	} BeamMenu;
	/* 0x0008 */	USHORT BtnXrayUp;
	/* 0x000A */	USHORT BtnXrayDown;
	/* 0x000C */	USHORT BtnXrayLeft;
	/* 0x000E */	USHORT BtnXrayRight;
	/* 0x0010 */	USHORT BtnShot;		// 40 = X
	/* 0x0012 */	USHORT BtnJump;		// 80 = A
	/* 0x0014 */	USHORT BtnDash;		// 8000 = B
	/* 0x0016 */	USHORT BtnCancel;
	/* 0x0018 */	USHORT BtnSelect;
	/* 0x001A */	USHORT BtnAimDown;
	/* 0x001C */	USHORT BtnAimUp;
	/* 0x001E */	// pad
	/* 0x0020 */	USHORT Health;
	/* 0x0022 */	USHORT HealthMax;
	/* 0x0024 */	USHORT Missile;
	/* 0x0026 */	USHORT MissileMax;
	/* 0x0028 */	USHORT SMissile;
	/* 0x002A */	USHORT SMissileMax;
	/* 0x002C */	USHORT PBomb;
	/* 0x002E */	USHORT PBombMax;
	/* 0x0030 */	// pad
	/* 0x0032 */	USHORT HPReserve;
	/* 0x0034 */	USHORT HPReserveMax;
	/* 0x0036 */	// u16 (always 0001)
	/* 0x0038 */	// u16 (unknown variable)
	/* 0x003A */	// u16 (unknown variable)
	/* 0x003C */	USHORT Minute;
	/* 0x003E */	USHORT Hour;
	/* 0x0040 */	USHORT Language;
	/* 0x0042 */	USHORT MoonWalk;
	/* 0x0044 */	// u16 (always 0001)
	/* 0x0046 */	// u16 (always 0001)
	/* 0x0048 */	USHORT IconCancel;

	union uAreaEvent {
		UCHAR Area[4];
		struct {

			// 0x60			// AREA			// INFO
			UCHAR x6000:1;	// Crateria		// Planet Zebes becomes active
			UCHAR x6001:1;	// 
			UCHAR x6002:1;	// Tourian		// Mother Brain's glass shield destroyed
			UCHAR x6003:1;	// 
			UCHAR x6004:1;	// 
			UCHAR x6005:1;	// Tourian		// Mother Brain's zebetites destroyed
			UCHAR x6006:1;	// Crateria		// Phantoon statue defunct
			UCHAR x6007:1;	// Crateria		// Ridley statue defunct

			// 0x61
			UCHAR x6100:1;	// Crateria		// Draygon statue defunct
			UCHAR x6101:1;	// Crateria		// Kraid statue defunct
			UCHAR x6102:1;	// Crateria		// Tourian elevator accessible
			UCHAR x6103:1;	// Maridia		// Glass tube broken
			UCHAR x6104:1;	// Norfair		// Chozo statue caused lava disappearance
			UCHAR x6105:1;	// Maridia		// Pathway to Spring Ball cleared
			UCHAR x6106:1;	// Crateria		// Ready to explode
			UCHAR x6107:1;	// Crateria		// Rescued animals during escape

			// 0x62
			UCHAR x6200:1;	// Tourian		// Metroids destroyed
			UCHAR x6201:1;	// Tourian		// Metroids destroyed
			UCHAR x6202:1;	// Tourian		// Metroids destroyed
			UCHAR x6203:1;	// Tourian		// Metroids destroyed
			UCHAR x6204:1;	// 
			UCHAR x6205:1;	// Norfair		// Pathway to Speed Boost flooded
			UCHAR x6206:1;	// 
			UCHAR x6207:1;	// 

			// 0x63
			UCHAR x6300:1;	// 
			UCHAR x6301:1;	// 
			UCHAR x6302:1;	// 
			UCHAR x6303:1;	// 
			UCHAR x6304:1;	// 
			UCHAR x6305:1;	// 
			UCHAR x6306:1;	// 
			UCHAR x6307:1;	// 

		} Event;
	} AreaEvent;
	/* 0x0064 */	
	/* 0x0066 */	
	union uEnemyEvent {
		UCHAR Enemy[8];
		struct {

			// 0x68
			UCHAR x6800:1;	// 
			UCHAR x6801:1;	// 
			UCHAR x6802:1;	// Crateria		// Silver Torizo defeated
			UCHAR x6803:1;	// 
			UCHAR x6804:1;	// 
			UCHAR x6805:1;	// 
			UCHAR x6806:1;	// 
			UCHAR x6807:1;	// 

			// 0x69
			UCHAR x6900:1;	// Brinstar		// Kraid defeated
			UCHAR x6901:1;	// Brinstar		// Spore Spawn defeated
			UCHAR x6902:1;	// 
			UCHAR x6903:1;	// 
			UCHAR x6904:1;	// 
			UCHAR x6905:1;	// 
			UCHAR x6906:1;	// 
			UCHAR x6907:1;	// 

			// 0x6A
			UCHAR x6A00:1;	// Norfair		// Ridley defeated
			UCHAR x6A01:1;	// Norfair		// Crocomire defeated
			UCHAR x6A02:1;	// Norfair		// Golden Torizo defeated
			UCHAR x6A03:1;	// 
			UCHAR x6A04:1;	// 
			UCHAR x6A05:1;	// 
			UCHAR x6A06:1;	// 
			UCHAR x6A07:1;	// 

			// 0x6B
			UCHAR x6B00:1;	// Wrecked Ship	// Phantoon defeated
			UCHAR x6B01:1;	// 
			UCHAR x6B02:1;	// 
			UCHAR x6B03:1;	// 
			UCHAR x6B04:1;	// 
			UCHAR x6B05:1;	// 
			UCHAR x6B06:1;	// 
			UCHAR x6B07:1;	// 

			// 0x6C
			UCHAR x6C00:1;	// Maridia		// Draygon defeated
			UCHAR x6C01:1;	// Maridia		// Botwoon defeated
			UCHAR x6C02:1;	// 
			UCHAR x6C03:1;	// 
			UCHAR x6C04:1;	// 
			UCHAR x6C05:1;	// 
			UCHAR x6C06:1;	// 
			UCHAR x6C07:1;	// 

			// 0x6D
			UCHAR x6D00:1;	// Tourian		// Mother Brain defeated
			UCHAR x6D01:1;	// Tourian		// Mother Brain defeated
			UCHAR x6D02:1;	// 
			UCHAR x6D03:1;	// 
			UCHAR x6D04:1;	// 
			UCHAR x6D05:1;	// 
			UCHAR x6D06:1;	// 
			UCHAR x6D07:1;	// 

			// 0x6E
			UCHAR x6E00:1;	// Ceres Colony	// Ridley defeated
			UCHAR x6E01:1;	// 
			UCHAR x6E02:1;	// 
			UCHAR x6E03:1;	// 
			UCHAR x6E04:1;	// 
			UCHAR x6E05:1;	// 
			UCHAR x6E06:1;	// 
			UCHAR x6E07:1;	// 

		} Event;
	} EnemyEvent;

	/* 0x00B0 */	UCHAR ItemEvent[0x14];

	/* 0x00F0 */	UCHAR DoorEvent[0x16];

	/* 0x0138 */	USHORT AreaVisit[8];
	/* 0x0148 */	UCHAR AreaMap[8];
	/* 0x0150 */	
	/* 0x0152 */	
	/* 0x0154 */	USHORT Opcode;
	/* 0x0156 */	USHORT AreaLocation;
	/* 0x0158 */	USHORT Area;
	/* 0x015A */	// u16 (unknown variable)
	/* 0x015C */	UCHAR AreaExplore[0x500];
} SuperMetroid;
class SMetroid {
private:
public:

	// Variable
	CHAR * Dir;
	UCHAR * SRAM;

	UINT Selection;		// 0=SAMUS_A, 1=SAMUS_B, 2=SAMUS_C

	// Framework
	System_File * File;

	// Boot
	SMetroid(VOID) {}
	~SMetroid(VOID) {}

	// SRAM
	BOOL Open(CONST CHAR * _Filename);
	BOOL Save(CONST CHAR * _Filename);
	BOOL Close(VOID);

	// SaveGame
	BOOL Export(UINT ID);
	BOOL Export(UINT ID, CONST CHAR * SaveRAM);

	BOOL Import(UINT ID, CONST CHAR * GameSAV);
	BOOL Import(UINT ID, CONST CHAR * SaveRAM, CONST CHAR * GameSAV);

	BOOL Clear(UINT ID);
	BOOL Clear(UINT ID, CONST CHAR * SaveRAM);

	// Checksum
	BOOL SetChecksum(UCHAR * SRAM, UINT ID);
	BOOL Update(CONST CHAR * _Filename);

};
