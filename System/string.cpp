
#include "system.h"

/*** deprecated ***/

// Create
CHAR * System_String::Get(CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vsprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// Create
	return _Buffer;
}
WCHAR * System_String::Get(CONST WCHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * _Buffer = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vswprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// complete
	return _Buffer;
}
VOID System_String::Get(ULONG &StrLen, CHAR &String, CONST CHAR * _Format, ...) {

	// Clear Buffer
	if (strlen(&String)) { memset(&String, 0x00, strlen(&String)); }

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (StrLen * 2));
	vsprintf_s(_Buffer, StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// Create
	RtlSecureZeroMemory(&String, StrLen+2);
	memcpy_s(&String, StrLen, _Buffer, StrLen);

	// Cleanup
	delete[] _Buffer;
}
// Character Conversion
CHAR * System_String::ToA(WCHAR * _Format, ...) {

	// String
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * String = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(String, (_StrLen * 2));
	vswprintf_s(String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// Conversion
	INT _SizeInBytes = WideCharToMultiByte(CP_ACP, 0, String, -1, NULL, NULL, NULL, NULL);
	CHAR * lpMultiByteStr = new CHAR[_SizeInBytes + 2];
	RtlSecureZeroMemory(lpMultiByteStr, (_SizeInBytes + 2));
	WideCharToMultiByte(CP_ACP, 0, String, -1, lpMultiByteStr, _SizeInBytes, NULL, NULL);

	// Terminate
	delete[]String;
	return lpMultiByteStr;
}
WCHAR * System_String::ToW(CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _DstBuf = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_DstBuf, (_StrLen * 2));
	vsprintf_s(_DstBuf, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// Conversion
	INT _SizeInBytes = MultiByteToWideChar(CP_ACP, 0, _DstBuf, -1, NULL, NULL);
	WCHAR * lpWideCharStr = new WCHAR[(_SizeInBytes * 2) + 2];
	RtlSecureZeroMemory(lpWideCharStr, ((_SizeInBytes * 2) + 2));
	MultiByteToWideChar(CP_ACP, 0, _DstBuf, -1, lpWideCharStr, (_SizeInBytes * 2));

	// Terminate
	delete[]_DstBuf;
	return lpWideCharStr;
}
CHAR * System_String::ToUpper(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vsprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	CHAR * _String;
	_strupr_s(_String = _strdup(_Buffer), strlen(_Buffer) + 1);
	delete[] _Buffer;
	return _String;
}
WCHAR * System_String::ToUpper(WCHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * _Buffer = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vswprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	WCHAR * _String;
	_wcsupr_s(_String = _wcsdup(_Buffer), wcslen(_Buffer) + 1);
	delete[] _Buffer;
	return _String;
}
CHAR * System_String::ToLower(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vsprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	CHAR * _String;
	_strlwr_s(_String = _strdup(_Buffer), strlen(_Buffer) + 1);
	delete[] _Buffer;
	return _String;
}
WCHAR * System_String::ToLower(WCHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * _Buffer = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vswprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	WCHAR * _String;
	_wcslwr_s(_String = _wcsdup(_Buffer), wcslen(_Buffer) + 2);
	delete[] _Buffer;
	return _String;
}
// Integer Conversion
CHAR * System_String::FromInt(LLONG Value) {
	CHAR * _String = (CHAR *)"\0\0\0\0";
	RtlSecureZeroMemory(_String, 65);
	_i64toa_s(Value, &_String[0x00], 65, 10);
	return _String;
}
CHAR * System_String::FromIntU(ULLONG Value) {
	CHAR * _String = (CHAR *)"\0\0\0\0";
	RtlSecureZeroMemory(_String, 65);
	_ui64toa_s(Value, &_String[0x00], 65, 10);
	return _String;
}
LONG System_String::ToInt(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _String = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_String, (_StrLen * 2));
	vsprintf_s(_String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	LONG Value = NULL;
	if (_String[1] != 0x58 && _String[1] != 0x78) {
		Value = strtol(_String, NULL, 10);
	}
	else {
		Value = strtol(_String, NULL, 16);
	}
	delete[] _String;
	return Value;
}
ULONG System_String::ToIntU(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _String = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_String, (_StrLen * 2));
	vsprintf_s(_String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	ULONG Value = NULL;
	if (_String[1] != 0x58 && _String[1] != 0x78) {
		Value = strtoul(_String, NULL, 10);
	} else {
		Value = strtoul(_String, NULL, 16);
	}
	delete[] _String;
	return Value;
}
LLONG System_String::ToInt64(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _String = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_String, (_StrLen * 2));
	vsprintf_s(_String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	LLONG Value = NULL;
	if (_String[1] != 0x58 && _String[1] != 0x78) {
		Value = strtoll(_String, NULL, 10);
	}
	else {
		Value = strtoll(_String, NULL, 16);
	}
	delete[] _String;
	return Value;
}
ULLONG System_String::ToIntU64(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _String = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_String, (_StrLen * 2));
	vsprintf_s(_String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	ULLONG Value = NULL;
	if (_String[1] != 0x58 && _String[1] != 0x78) {
		Value = strtoull(_String, NULL, 10);
	}
	else {
		Value = strtoull(_String, NULL, 16);
	}
	delete[] _String;
	return Value;
}
// Floating-Point Conversion
CHAR * System_String::FromFloat(DOUBLE Value) {
	CHAR * _String = (CHAR *)"\0\0\0\0";
	RtlSecureZeroMemory(_String, _CVTBUFSIZE);
	_gcvt_s(&_String[0x00], _CVTBUFSIZE, Value, 15);
	return _String;
}
DOUBLE System_String::ToFloat(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _String = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_String, (_StrLen * 2));
	vsprintf_s(_String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	DOUBLE Value = atof(_String);
	delete[] _String;
	return Value;
}
DOUBLE System_String::ToFloat(WCHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * _String = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_String, (_StrLen * 2));
	vswprintf_s(_String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	DOUBLE Value = _wtof(_String);
	delete[] _String;
	return Value;
}
// Commandline
CHAR ** System_String::CommandLine(ULONG &nArgs, CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	size_t _BufferCount = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(_BufferCount * 2)];
	RtlSecureZeroMemory(_Buffer, (_BufferCount * 2));
	vsprintf_s(_Buffer, _BufferCount, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// Error
	nArgs = NULL;
	if (!strlen(_Buffer)) { delete[] _Buffer; return NULL; }

	// Setup
	size_t i = ((_BufferCount + 2) / 2) * 8 + 8;
	PCHAR * argv = (PCHAR*)GlobalAlloc(GMEM_FIXED, i + (_BufferCount + 2));
	PCHAR _argv = (PCHAR)(((PUCHAR)argv) + i);
	if (_argv && argv) { argv[NULL] = _argv; }
	else { delete[] _Buffer; return NULL; }

	// Local
	CHAR a = '\0';
	size_t j = i = NULL;
	BOOLEAN in_QM = FALSE;
	BOOLEAN in_TEXT = FALSE;
	BOOLEAN in_SPACE = TRUE;

	// Parse
	while (_Buffer[i]) {
		a = _Buffer[i];
		if (in_QM) {
			if (a == '\"') { in_QM = FALSE; }
			else { _argv[j] = a; j++; }
		} else {
			switch (a) {
			case '\"':
				in_QM = TRUE;
				in_TEXT = TRUE;
				if (in_SPACE) {
					argv[nArgs] = _argv + j;
					nArgs++;
				}
				in_SPACE = FALSE;
			break;
			case ' ':
			case '\t':
			case '\n':
			case '\r':
				if (in_TEXT) {
					_argv[j] = '\0';
					j++;
				}
				in_TEXT = FALSE;
				in_SPACE = TRUE;
			break;
			default:
				in_TEXT = TRUE;
				if (in_SPACE) {
					argv[nArgs] = _argv + j;
					nArgs++;
				}
				_argv[j] = a;
				j++;
				in_SPACE = FALSE;
			break;
			}
		}
		i++;
	}

	// Complete
	delete[] _Buffer;
	_argv[j] = '\0';
	argv[nArgs] = NULL;

	// Terminate
	return argv;
}
ULONG System_String::GetArgCount(CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	size_t _BufferCount = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(_BufferCount * 2)];
	RtlSecureZeroMemory(_Buffer, (_BufferCount * 2));
	vsprintf_s(_Buffer, _BufferCount, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// Parse
	ULONG nArgs = NULL;
	CommandLine(nArgs, _Buffer);
	delete[] _Buffer;

	// Terminate
	return nArgs;
}
ULONG System_String::GetArgCountW(WCHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	size_t _BufferCount = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * CmdLine = new WCHAR[(_BufferCount * 2)];
	RtlSecureZeroMemory(CmdLine, (_BufferCount * 2));
	vswprintf_s(CmdLine, _BufferCount, _Format, _ArgList);
	__crt_va_end(_ArgList);

	INT NumArgs = NULL;
	CommandLineToArgvW(CmdLine, &NumArgs);
	delete[] CmdLine;
	return NumArgs;
}
CHAR * System_String::GetArg(ULONG iArg, CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	size_t _BufferCount = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(_BufferCount * 2)];
	RtlSecureZeroMemory(_Buffer, (_BufferCount * 2));
	vsprintf_s(_Buffer, _BufferCount, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// Error
	if (!strlen(_Buffer)) { delete[] _Buffer; return (CHAR *)"\0\0\0\0"; }

	// Parse
	ULONG nArgs = NULL;
	CHAR ** List = CommandLine(nArgs, _Buffer);
	delete[] _Buffer;

	// Terminate
	if (!nArgs || iArg >= nArgs) { return (CHAR *)"\0\0\0\0"; }
	return List[iArg];
}
WCHAR * System_String::GetArgW(ULONG iArg, WCHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	size_t _BufferCount = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * CmdLine = new WCHAR[(_BufferCount * 2)];
	RtlSecureZeroMemory(CmdLine, (_BufferCount * 2));
	vswprintf_s(CmdLine, _BufferCount, _Format, _ArgList);
	__crt_va_end(_ArgList);

	INT NumArgs = NULL;
	LPWSTR * List = CommandLineToArgvW(CmdLine, &NumArgs);
	delete[] CmdLine;
	if (!NumArgs || (INT)iArg >= NumArgs) { return (WCHAR *)L"\0\0\0\0"; }
	return List[iArg];
}
// Meta
CHAR * System_String::GetDirectory(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _String = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_String, (_StrLen * 2));
	vsprintf_s(_String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	CHAR Drive[_MAX_DRIVE];
	CHAR Directory[_MAX_DIR];
	CHAR Name[_MAX_FNAME];
	CHAR Extension[_MAX_EXT];
	_splitpath_s(_String, Drive, Directory, Name, Extension);

	// Directory
	if (!strlen(Extension)) {
		if (_String[strlen(_String) - 1] != 0x5C) {
			_String = Get("%s\\", _String);
		}
	}

	// Drive
	if (PathGetDriveNumberA(_String) == -1) {
		if (_String[0] != 0x5C) {
			_String = Get("\\%s", _String);
		}
		_String = Get("%s\\%s", _getcwd(NULL, NULL), PathSkipRootA(_String));
	}

	// Create
	_splitpath_s(_String, Drive, Directory, Name, Extension);
	delete[] _String;

	// Terminate
	return Get("%s%s", Drive, Directory);
}
WCHAR * System_String::GetDirectory(WCHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * _String = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_String, (_StrLen * 2));
	vswprintf_s(_String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	WCHAR Drive[_MAX_DRIVE+ _MAX_DRIVE];
	WCHAR Directory[_MAX_DIR];
	WCHAR Name[_MAX_FNAME];
	WCHAR Extension[_MAX_EXT];
	_wsplitpath_s(_String, Drive, Directory, Name, Extension);

	// Directory
	if (!wcslen(Extension)) {
		if (_String[wcslen(_String) - 1] != 0x5C) {
			_String = Get(L"%ws\\", _String);
		}
	}

	// Drive
	if (PathGetDriveNumberW(_String) == -1) {
		if (_String[0] != 0x5C) {
			_String = Get(L"\\%ws", _String);
		}
		_String = Get(L"%ws\\%ws", _wgetcwd(NULL, NULL), PathSkipRootW(_String));
	}

	// Create
	_wsplitpath_s(_String, Drive, Directory, Name, Extension);
	delete[] _String;

	// Terminate
	return Get(L"%ws%ws", Drive, Directory);
}
CHAR * System_String::GetNamebase(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vsprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);


	// Parse
	CHAR drive[_MAX_DRIVE];
	CHAR dir[_MAX_DIR];
	CHAR fname[_MAX_FNAME];
	CHAR ext[_MAX_EXT];
	_splitpath_s(_Buffer, drive, dir, fname, ext);
	delete[] _Buffer;

	// Terminate
	return Get(fname);
}
WCHAR * System_String::GetNamebase(WCHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * _Buffer = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vswprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);


	// Parse
	WCHAR drive[_MAX_DRIVE];
	WCHAR dir[_MAX_DIR];
	WCHAR fname[_MAX_FNAME];
	WCHAR ext[_MAX_EXT];
	_wsplitpath_s(_Buffer, drive, dir, fname, ext);
	delete[] _Buffer;

	// Terminate
	return Get(fname);
}
CHAR * System_String::GetExtension(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vsprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);


	// Parse
	CHAR drive[_MAX_DRIVE];
	CHAR dir[_MAX_DIR];
	CHAR fname[_MAX_FNAME];
	CHAR ext[_MAX_EXT];
	_splitpath_s(_Buffer, drive, dir, fname, ext);
	delete[] _Buffer;

	// Terminate
	return Get(ext);
}
WCHAR * System_String::GetExtension(WCHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * _Buffer = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vswprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);


	// Parse
	WCHAR drive[_MAX_DRIVE];
	WCHAR dir[_MAX_DIR];
	WCHAR fname[_MAX_FNAME];
	WCHAR ext[_MAX_EXT];
	_wsplitpath_s(_Buffer, drive, dir, fname, ext);
	delete[] _Buffer;

	// Terminate
	return Get(ext);
}
// Message
VOID System_String::Message(CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _String = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_String, (_StrLen * 2));
	vsprintf_s(_String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	MessageBoxA(0, _String, APPLICATION_NAME_A, 0);
	delete[] _String;
}
VOID System_String::MessageW(WCHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * _String = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_String, (_StrLen * 2));
	vswprintf_s(_String, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	MessageBoxW(0, _String, APPLICATION_NAME_W, 0);
	delete[] _String;
}