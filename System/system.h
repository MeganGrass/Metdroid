
#include FRAMEWORK

// Basic
typedef __int8				CHAR;
typedef unsigned __int8		UCHAR;
typedef __int16				SHORT;
typedef unsigned __int16	USHORT;
typedef __int32				INT;
typedef unsigned __int32	UINT;
typedef long int			LONG;
typedef unsigned long int	ULONG;
typedef __int64				LLONG;
typedef unsigned __int64	ULLONG;
typedef float				FLOAT;
typedef double				DOUBLE;
typedef long double			LDOUBLE;

#define FAIL		FALSE
#define SUCCESS		TRUE

#define OFF			FALSE
#define ON			TRUE

#define NO			FALSE
#define YES			TRUE

#define DISABLED	FALSE
#define ENABLED		TRUE
 
class System_Type {
private:
public:

	// De/Construction
	System_Type(VOID) {}
	virtual ~System_Type(VOID) {}

	// Bits and Bytes
	BOOL GetBit(uintmax_t iBit, UCHAR Value);
	uintmax_t GetByte(uintmax_t iByte, uintmax_t Value);
	BOOL * GetBitArray(UCHAR Value);

	// x86/x64
	uintmax_t GetValue(uintmax_t Value);
	uintmax_t GetValueFromStr(BOOL HexaDecimal, CONST CHAR * Value);
	uintmax_t GetValueFromStr(BOOL HexaDecimal, CONST WCHAR * Value);
	uintmax_t GetValueFromBits(uintmax_t Value, uintmax_t k, uintmax_t p);
	uintmax_t GetValueFromBytes(UCHAR n0, UCHAR n1, UCHAR n2, UCHAR n3, UCHAR n4, UCHAR n5, UCHAR n6, UCHAR n7);
	uintmax_t SwapEndianness(uintmax_t Value);

	// precision-point
	FLOAT GetFloat(uintmax_t Value);
	DOUBLE GetDouble(uintmax_t Value);
	DOUBLE GetDouble(FLOAT Value);

};

class System_String {
private:
public:

	// Boot
	System_String(VOID) {}
	virtual ~System_String(VOID) {}

	// Variable
	ULONG _StrLen;		// Temporary buffer for size of string from Format() for Get() // (*2)-4 for W size, -2 for A size

	// Create
	CHAR * Get(CONST CHAR * _Format, ...);
	WCHAR * Get(CONST WCHAR * _Format, ...);
	VOID Get(ULONG &StrLen, CHAR &String, CONST CHAR * _Format, ...);

	// Character Conversion
	CHAR * ToA(WCHAR * _Format, ...);
	WCHAR * ToW(CHAR * _Format, ...);
	CHAR * ToUpper(CHAR * _Format, ...);
	WCHAR * ToUpper(WCHAR * _Format, ...);
	CHAR * ToLower(CHAR * _Format, ...);
	WCHAR * ToLower(WCHAR * _Format, ...);

	// Integer Conversion
	CHAR * FromInt(LLONG Value);
	CHAR * FromIntU(ULLONG Value);
	LONG ToInt(CHAR * _Format, ...);
	ULONG ToIntU(CHAR * _Format, ...);
	LLONG ToInt64(CHAR * _Format, ...);
	ULLONG ToIntU64(CHAR * _Format, ...);

	// Floating-Point Conversion
	CHAR * FromFloat(DOUBLE Value);
	DOUBLE ToFloat(CHAR * _Format, ...);
	DOUBLE ToFloat(WCHAR * _Format, ...);

	// Commandline
	CHAR ** CommandLine(ULONG &nArgs, CONST CHAR * _Format, ...);
	ULONG GetArgCount(CHAR * _Format, ...);
	ULONG GetArgCountW(WCHAR * _Format, ...);
	CHAR * GetArg(ULONG iArg, CHAR * _Format, ...);
	WCHAR * GetArgW(ULONG iArg, WCHAR * _Format, ...);

	// Meta
	CHAR * GetDirectory(CHAR * _Format, ...);
	WCHAR * GetDirectory(WCHAR * _Format, ...);
	CHAR * GetNamebase(CHAR * _Format, ...);
	WCHAR * GetNamebase(WCHAR * _Format, ...);
	CHAR * GetExtension(CHAR * _Format, ...);
	WCHAR * GetExtension(WCHAR * _Format, ...);

	// Message Box
	VOID Message(CHAR * _Format, ...);
	VOID MessageW(WCHAR * _Format, ...);

};

// To edit an existing file, use w+ for Mode
typedef enum tagOpenFileMode {
	READ_FILE = 0x00,		// rb
	CREATE_FILE = 0x01,		// wb
	EDIT_FILE = 0x02,		// rb+
	APPEND_FILE = 0x03		// ab+
} OpenFileMode;
class System_File :
	public System_Type,
	public System_String {
private:
public:

	// Boot
	System_File(VOID) {}
	virtual ~System_File(VOID) {}

	// Status
	BOOL IsOpen(_iobuf * FILE);
	BOOL Exists(CONST CHAR * _Format, ...);
	BOOL Exists(CONST WCHAR * _Format, ...);

	// Memory
	UCHAR * Buffer(CONST CHAR * _Format, ...);
	UCHAR * Buffer(CONST WCHAR * _Format, ...);
	UCHAR * Buffer(ULONG &_ElementSize, CONST CHAR * _Format, ...);
	UCHAR * Buffer(ULONG _Offset, ULONG &_ElementSize, CONST CHAR * _Format, ...);

	// Input
	_iobuf * Open(OpenFileMode _Mode, CONST CHAR * _Format, ...);
	_iobuf * Open(OpenFileMode _Mode, CONST WCHAR * _Format, ...);
	CHAR* GetFilename(CONST CHAR* DefExt, CONST CHAR* Filter);
	CHAR* GetSavename(CONST CHAR* DefExt, CONST CHAR* Filter);
	_iobuf * OpenFromFile(_iobuf * FILE, ULONG _Offset, ULONG _ElementSize, CONST CHAR * _Format, ...);
	_iobuf * OpenFromSource(UCHAR * _SrcBuf, ULONG _ElementSize, CONST CHAR * _Format, ...);

	// Output
	VOID CreateDummy(ULONG Size, CONST CHAR * _Format, ...);
	VOID CreateDummy(ULONG Size, CONST WCHAR * _Format, ...);
	VOID CreateDir(CONST CHAR * _Format, ...);
	VOID CreateDir(CONST WCHAR * _Format, ...);
	BOOL CreateFromSource(UCHAR * _SrcBuf, ULONG _ElementSize, CONST CHAR * _Format, ...);
	BOOL CreateFromSource(UCHAR * _SrcBuf, ULONG _ElementSize, CONST WCHAR * _Format, ...);
	BOOL CreateFromSource(_iobuf * FILE, ULONG _Offset, ULONG _ElementSize, CONST CHAR * _Format, ...);
	BOOL CreateFromSource(_iobuf * FILE, ULONG _Offset, ULONG _ElementSize, CONST WCHAR * _Format, ...);

	// Read
	UCHAR * Read(_iobuf * FILE, ULONG _Offset, PVOID _Buffer, ULONG _ElementSize);
	UCHAR * Read(_iobuf * FILE, ULONG _Offset, ULONG _ElementSize);

	// Write
	fpos_t Write(_iobuf * FILE, fpos_t _Offset, PVOID _Buffer, size_t _ElementSize);

	// Size
	ULONG Size(_iobuf * FILE);
	ULONG Size(CONST CHAR * _Format, ...);
	ULONG Size(CONST WCHAR * _Format, ...);

	// Search
	ULONG Search(_iobuf * FILE, ULONG _Offset, PVOID _SrcBuf, ULONG _ElementSize);

	// Print
	ULONG Print(_iobuf * FILE, ULONG _Offset, CONST CHAR * _Format, ...);
	ULONG Print(_iobuf * FILE, ULONG _Offset, CONST WCHAR * _Format, ...);
	ULONG Print(_iobuf * FILE, CONST CHAR * _Format, ...);
	ULONG Print(_iobuf * FILE, CONST  WCHAR * _Format, ...);

	// Disk
	ULONG Align(ULONG nAlign, ULONG Value);	// needs to be moved to and expanded upon in Types
	VOID Align(ULONG nAlign, CONST CHAR * _Format, ...);
	VOID Align(ULONG nAlign, CONST WCHAR * _Format, ...);

};

// Text File
typedef struct tagConfigurationSettings {
	ULONG nLine;		// Total amount of Lines in Configuration File (*.ini)
	ULONG * Offset;		// Pointer to each Line
	ULONG * Length;		// Length of each Line (including any mix of 0x0D, 0x0A and/or 0x00)
	ULONG * StrLen;		// Length of each Line (excluding any mix of 0x0D, 0x0A and/or 0x00)
	ULONG * nArgs;		// Total amount of argument strings of each line
	UCHAR * Data;		// File Buffer
	ULONG _ElementSize;	// File Size
} Configuration, *pINI;
class System_Configuration_A :
	private System_String {
private:
	CHAR * Format(CONST CHAR * _Format, ...);
	WCHAR * Format(CONST WCHAR * _Format, ...);
	ULONG _StrLen;		// Temporary buffer for size of string from Format()	// (*2)-4 for size
public:

	// Boot
	System_Configuration_A(VOID) {}
	~System_Configuration_A(VOID) {}

	// Framework
	System_File * File;

	// Open
	pINI Open(CHAR * _FileName, ...);
	pINI Open(_iobuf * FILE, ULONG _Offset, ULONG _ElementSize);

	// Read
	CHAR * Arg(pINI INI, ULONG iLine, ULONG iArg);
	CHAR * Line(pINI INI, ULONG iLine);
	CHAR * Line(pINI INI, CHAR * Section, ULONG iLine);
	CHAR * Value(pINI INI, CHAR * Section, CHAR * Key);
	CHAR * Value(pINI INI, CHAR * Section, CHAR * Key, ULONG iArg);
	CHAR * Value(pINI INI, CHAR * Section, ULONG iLine, ULONG iArg);
	ULONG Find(pINI INI, ULONG iLine, CHAR * Key);
	ULONG SectionLine(pINI INI, CHAR * Section);

	// Write
	BOOL Extract(pINI INI, ULONG LineStart, ULONG LineFinish, CONST CHAR * _OutputFile, ...);

	// Cleanup
	VOID Close(pINI INI);

};
