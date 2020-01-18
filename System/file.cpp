
#include "system.h"

// Status
BOOL System_File::IsOpen(_iobuf * FILE) {
	if ((_get_osfhandle(_fileno(FILE))) != -1) { return SUCCESS; }
	else { return FAIL; }
}
BOOL System_File::Exists(CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// 
	struct _stat64i32 Status;
	if (_stat64i32(FileName, &Status)) {
		delete[] FileName;
		return FAIL;
	}
	else {
		delete[] FileName;
		return SUCCESS;
	}
}
BOOL System_File::Exists(CONST WCHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * FileName = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	struct _stat64i32 Status;
	if (_wstat64i32(FileName, &Status)) {
		delete[] FileName;
		return FAIL;
	}
	else {
		delete[] FileName;
		return SUCCESS;
	}
}
// Memory
UCHAR * System_File::Buffer(CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// open
	if (!Exists(FileName)) { delete[]FileName; return NULL; }
	_iobuf * _File = Open(READ_FILE, FileName);
	if (!IsOpen(_File)) { return NULL; }

	// read
	ULONG _ElementSize = Size(_File);
	UCHAR * _Src = Read(_File, 0x00, _ElementSize);
	fclose(_File);

	// terminate
	delete[]FileName;
	return _Src;
}
UCHAR * System_File::Buffer(CONST WCHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * FileName = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// parse
	if (!Exists(FileName)) { delete[]FileName; return NULL; }

	// open
	_iobuf * _File = Open(READ_FILE, FileName);
	if (!IsOpen(_File)) { return NULL; }

	// read
	ULONG _ElementSize = Size(_File);
	UCHAR * _Src = Read(_File, 0x00, _ElementSize);
	fclose(_File);

	// terminate
	delete[]FileName;
	return _Src;
}
UCHAR * System_File::Buffer(ULONG &_ElementSize, CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// open
	if (!Exists(FileName)) { delete[]FileName; return NULL; }
	_iobuf * _File = Open(READ_FILE, FileName);
	if (!IsOpen(_File)) { return NULL; }

	// read
	_ElementSize = Size(_File);
	UCHAR * _Src = Read(_File, 0x00, _ElementSize);
	fclose(_File);

	// terminate
	delete[]FileName;
	return _Src;
}
UCHAR * System_File::Buffer(ULONG _Offset, ULONG &_ElementSize, CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// open
	if (!Exists(FileName)) { delete[]FileName; return NULL; }
	_iobuf * _File = Open(READ_FILE, FileName);
	if (!IsOpen(_File)) { return NULL; }

	// read
	_ElementSize = Size(_File);
	UCHAR * _Src = Read(_File, _Offset, _ElementSize);
	fclose(_File);

	// terminate
	delete[]FileName;
	return _Src;

}
// Input
_iobuf * System_File::Open(OpenFileMode _Mode, CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// Parse
	CHAR * Mode = (CHAR *)"\0\0\0\0";
	switch (_Mode)
	{
	case READ_FILE:
		if (!Exists(FileName)) { delete[] FileName; return NULL; }
		Mode = Get("rb");
	break;
	case CREATE_FILE:
		CreateDir(FileName);
		Mode = Get("wb");
	break;
	case EDIT_FILE:
		CreateDir(FileName);
		Mode = Get("rb+");
	break;
	case APPEND_FILE:
		CreateDir(FileName);
		Mode = Get("ab+");
	break;
	}

	// open
	_iobuf * _Stream = NULL;
	errno_t Open = fopen_s(&_Stream, FileName, Mode);
	if (!_Stream || Open != 0) { delete[] FileName; return NULL; }

	// terminate
	delete[] FileName;
	return _Stream;

}
_iobuf * System_File::Open(OpenFileMode _Mode, CONST WCHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * FileName = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// parse
	WCHAR * Mode = (WCHAR *)L"\0\0\0\0";
	switch (_Mode)
	{
	case READ_FILE:
		if (!Exists(FileName)) { delete[] FileName; return NULL; }
		Mode = Get(L"rb");
		break;
	case CREATE_FILE:
		CreateDir(FileName);
		Mode = Get(L"wb");
		break;
	case EDIT_FILE:
		CreateDir(FileName);
		Mode = Get(L"rb+");
		break;
	}

	// open
	_iobuf * _Stream = NULL;
	errno_t Open = _wfopen_s(&_Stream, FileName, Mode);
	if (!_Stream || Open != 0) { delete[] FileName; return NULL; }

	// terminate
	delete[] FileName;
	return _Stream;

}
CHAR* System_File::GetFilename(CONST CHAR* DefExt, CONST CHAR* Filter) {

	char* _Filename = new char[_MAX_PATH];

	OPENFILENAMEA OpenFilename;
	RtlSecureZeroMemory(&OpenFilename, sizeof(OPENFILENAMEA));

	OpenFilename.lStructSize = sizeof(OPENFILENAMEA);
	OpenFilename.hwndOwner = 0;
	OpenFilename.lpstrFilter = Filter;
	OpenFilename.lpstrFile = _Filename;
	OpenFilename.lpstrFile[0] = '\0';
	OpenFilename.nMaxFile = _MAX_PATH;
	OpenFilename.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST
		| OFN_DONTADDTORECENT;
	OpenFilename.lpstrDefExt = DefExt;

	if (!GetOpenFileNameA(&OpenFilename)) { return (CHAR*)"\0\0"; }
	else { return _Filename; }
}
CHAR* System_File::GetSavename(CONST CHAR* DefExt, CONST CHAR* Filter) {

	char* _Filename = new char[_MAX_PATH];

	OPENFILENAMEA SaveFilename;
	RtlSecureZeroMemory(&SaveFilename, sizeof(OPENFILENAMEA));

	SaveFilename.lStructSize = sizeof(OPENFILENAMEA);
	SaveFilename.hwndOwner = 0;
	SaveFilename.lpstrFilter = Filter;
	SaveFilename.lpstrFile = _Filename;
	SaveFilename.lpstrFile[0] = '\0';
	SaveFilename.nMaxFile = _MAX_PATH;
	SaveFilename.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_DONTADDTORECENT;
	SaveFilename.lpstrDefExt = DefExt;

	if (!GetSaveFileNameA(&SaveFilename)) { return (CHAR*)"\0\0"; }
	else { return _Filename; }
}
// Output
VOID System_File::CreateDummy(ULONG Size, CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// 
	_iobuf * _File = Open(CREATE_FILE, FileName);
	delete[] FileName;
	if (!_File) { return; }

	// Write
	UCHAR * Buffer = new UCHAR[Size];
	RtlSecureZeroMemory(Buffer, Size);
	Write(_File, 0x00, Buffer, Size);
	delete[] Buffer;

	// Close
	fclose(_File);

}
VOID System_File::CreateDummy(ULONG Size, CONST WCHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * FileName = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// parse
	_iobuf * _File = Open(CREATE_FILE, FileName);
	delete[] FileName;
	if (!_File) { return; }

	// Write
	UCHAR * Buffer = new UCHAR[Size];
	RtlSecureZeroMemory(Buffer, Size);
	Write(_File, 0x00, Buffer, Size);
	delete[] Buffer;

	// Close
	fclose(_File);

}
VOID System_File::CreateDir(CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// 
	CHAR * lpPathName = GetDirectory(FileName);
	SHCreateDirectoryExA(NULL, lpPathName, NULL);
	delete[]lpPathName;
}
VOID System_File::CreateDir(CONST WCHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * FileName = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	WCHAR * lpPathName = GetDirectory(FileName);
	SHCreateDirectoryExW(NULL, lpPathName, NULL);
	delete[]lpPathName;
}
BOOL System_File::CreateFromSource(UCHAR * _SrcBuf, ULONG _ElementSize, CONST CHAR * _Format, ...) {

	// error
	if (_SrcBuf == NULL) { return FAIL; }

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// parse
	_iobuf * _File = Open(CREATE_FILE, FileName);
	if (!IsOpen(_File)) { return FAIL; }

	// write
	Write(_File, 0x00, &_SrcBuf[0x00], _ElementSize);

	// cleanup
	delete[] FileName;
	fclose(_File);

	// terminate
	return SUCCESS;
}
BOOL System_File::CreateFromSource(UCHAR * _SrcBuf, ULONG _ElementSize, CONST WCHAR * _Format, ...) {

	// error
	if (_SrcBuf == NULL) { return FAIL; }

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * FileName = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// parse
	_iobuf * _File = Open(CREATE_FILE, FileName);
	if (!IsOpen(_File)) { return FAIL; }

	// write
	Write(_File, 0x00, &_SrcBuf[0x00], _ElementSize);

	// cleanup
	delete[] FileName;
	fclose(_File);

	// terminate
	return SUCCESS;
}
BOOL System_File::CreateFromSource(_iobuf * FILE, ULONG _Offset, ULONG _ElementSize, CONST CHAR * _Format, ...) {

	// error
	if (!IsOpen(FILE)) { return NULL; }

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// parse
	_iobuf * _File = Open(CREATE_FILE, FileName);
	if (!IsOpen(_File)) { return FAIL; }

	// write
	UCHAR * _SrcBuf = Read(FILE, _Offset, _ElementSize);
	Write(_File, 0x00, &_SrcBuf[0x00], _ElementSize);

	// cleanup
	delete[] FileName;
	delete[] _SrcBuf;
	fclose(_File);

	// terminate
	return SUCCESS;
}
BOOL System_File::CreateFromSource(_iobuf * FILE, ULONG _Offset, ULONG _ElementSize, CONST WCHAR * _Format, ...) {

	// error
	if (!IsOpen(FILE)) { return NULL; }

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * FileName = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// parse
	_iobuf * _File = Open(CREATE_FILE, FileName);
	if (!IsOpen(_File)) { return FAIL; }

	// write
	UCHAR * _SrcBuf = Read(FILE, _Offset, _ElementSize);
	Write(_File, 0x00, &_SrcBuf[0x00], _ElementSize);

	// cleanup
	delete[] FileName;
	delete[] _SrcBuf;
	fclose(_File);

	// terminate
	return SUCCESS;
}
// Read
UCHAR * System_File::Read(_iobuf * FILE, ULONG _Offset, PVOID _Buffer, ULONG _ElementSize) {

	if (!IsOpen(FILE)) { return NULL; }
	fpos_t pos = GetValue(_Offset);
	fsetpos(FILE, &pos);
	fread(_Buffer, _ElementSize, 1, FILE);
	return static_cast<UCHAR *>(_Buffer);

}
UCHAR * System_File::Read(_iobuf * FILE, ULONG _Offset, ULONG _ElementSize) {

	if (!IsOpen(FILE)) { return NULL; }
	fpos_t pos = GetValue(_Offset);
	fsetpos(FILE, &pos);
	UCHAR * _Buffer = new UCHAR [_ElementSize];
	RtlSecureZeroMemory(_Buffer, _ElementSize);
	Read(FILE, _Offset, _Buffer, _ElementSize);
	return static_cast<UCHAR *>(_Buffer);

}
// Write
fpos_t System_File::Write(_iobuf * FILE, fpos_t _Offset, PVOID _Buffer, size_t _ElementSize) {

	if (!IsOpen(FILE)) { return NULL; }
	fpos_t pos = GetValue(_Offset);
	fsetpos(FILE, &pos);
	fwrite(_Buffer, _ElementSize, 1, FILE);
	return (_Offset += _ElementSize);
}
// Size
ULONG System_File::Size(_iobuf * FILE) {
	if (!IsOpen(FILE)) { return NULL; }
	fseek(FILE, 0x00, SEEK_END);
	return static_cast<ULONG>(ftell(FILE));
}
ULONG System_File::Size(CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// 
	_iobuf * _File = Open(READ_FILE, FileName);
	if (!IsOpen(_File)) { delete[]FileName; return NULL; }
	ULONG _ElementSize = Size(_File);
	fclose(_File);
	delete[]FileName;
	return _ElementSize;
}
ULONG System_File::Size(CONST WCHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * FileName = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	_iobuf * _File = Open(READ_FILE, FileName);
	if (!IsOpen(_File)) { delete[]FileName; return NULL; }
	ULONG _ElementSize = Size(_File);
	fclose(_File);
	delete[]FileName;
	return _ElementSize;
}
// Search
ULONG System_File::Search(_iobuf * FILE, ULONG _Offset, PVOID _SrcBuf, ULONG _ElementSize) {

	// Error
	if (!IsOpen(FILE)) { return _Offset; }

	// Search
	UCHAR * Buffer = new UCHAR [_ElementSize];
	ULONG _Filesize = Size(FILE);
	ULONG OriginalPtr = _Offset;
	for (ULONG n = 0; n < _Filesize; n++, _Offset++)
	{
		if (feof(FILE)) { return OriginalPtr; }
		Read(FILE, _Offset, &Buffer, _ElementSize);
		if (memcmp(&Buffer, _SrcBuf, _ElementSize) == 0) { delete[]Buffer; return _Offset; }
	}

	// Terminate
	delete[]Buffer;
	return OriginalPtr;
}
// Print
ULONG System_File::Print(_iobuf * FILE, ULONG _Offset, CONST CHAR * _Format, ...) {

	// Error
	if (!IsOpen(FILE)) { return NULL; }

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	UCHAR * FileName = new UCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s((CHAR *)FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// write
	Write(FILE, _Offset, FileName, (_StrLen - 2));

	// terminate
	delete[] FileName;
	return (_StrLen - 2);
}
ULONG System_File::Print(_iobuf * FILE, ULONG _Offset, CONST WCHAR * _Format, ...) {

	// Error
	if (!IsOpen(FILE)) { return NULL; }

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	UCHAR * FileName = new UCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s((WCHAR *)FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// 
	Write(FILE, _Offset, FileName, ((_StrLen * 2) - 4));

	// terminate
	delete[] FileName;
	return ((_StrLen * 2) - 4);
}
ULONG System_File::Print(_iobuf * FILE, CONST CHAR * _Format, ...) {
	if (!IsOpen(FILE)) { return NULL; }

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	UCHAR * FileName = new UCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s((CHAR *)FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	fseek(FILE, 0x00, SEEK_END);
	fwrite(FileName, (_StrLen - 2), 1, FILE);
	delete[] FileName;
	return (_StrLen - 2);
}
ULONG System_File::Print(_iobuf * FILE, CONST WCHAR * _Format, ...) {
	if (!IsOpen(FILE)) { return NULL; }

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	UCHAR * FileName = new UCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s((WCHAR *)FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	fseek(FILE, 0x00, SEEK_END);
	fwrite(FileName, ((_StrLen * 2) - 4), 1, FILE);
	delete[] FileName;
	return ((_StrLen * 2) - 4);
}
// Disk
ULONG System_File::Align(ULONG nAlign, ULONG Value) {
	return Value = (Value + nAlign - 1) / nAlign * nAlign;
}
VOID System_File::Align(ULONG nAlign, CONST CHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * FileName = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vsprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// Open
	if (!Exists(FileName)) { delete[] FileName; return; }
	UCHAR * Source = Buffer(FileName);
	ULONG Filesize = Size(FileName);
	ULONG Size = Filesize;
	if (Filesize) {
		Filesize = (Filesize + nAlign - 1) / nAlign * nAlign;

		// buffer
		UCHAR * Buffer = new UCHAR[Filesize];
		RtlSecureZeroMemory(Buffer, Filesize);

		// write
		memcpy_s(&Buffer[0x00], Size, &Source[0x00], Size);
		CHAR * Dir = GetDirectory(FileName);
		CHAR * Namebase = GetNamebase(FileName);
		CHAR * Extension = GetExtension(FileName);
		CreateFromSource(Buffer, Filesize, "%s%s%s", Dir, Namebase, Extension);

		// cleanup
		delete[] Dir;
		delete[] Namebase;
		delete[] Extension;
		delete[] Buffer;
		delete[] Source;
	}

	delete[] FileName;
}
VOID System_File::Align(ULONG nAlign, CONST WCHAR * _Format, ...) {

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscwprintf(_Format, _ArgList) + 2);
	WCHAR * FileName = new WCHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(FileName, (_StrLen * 2));
	vswprintf_s(FileName, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// Open
	if (!Exists(FileName)) { delete[] FileName; return; }
	UCHAR * Source = Buffer(FileName);
	ULONG Filesize = Size(FileName);
	ULONG Size = Filesize;
	if (Filesize) {
		Filesize = (Filesize + nAlign - 1) / nAlign * nAlign;

		// buffer
		UCHAR * Buffer = new UCHAR[Filesize];
		RtlSecureZeroMemory(Buffer, Filesize);

		// write
		memcpy_s(&Buffer[0x00], Size, &Source[0x00], Size);
		WCHAR * Dir = GetDirectory(FileName);
		WCHAR * Namebase = GetNamebase(FileName);
		WCHAR * Extension = GetExtension(FileName);
		CreateFromSource(Buffer, Filesize, L"%ws%ws%ws", Dir, Namebase, Extension);

		// cleanup
		delete[] Dir;
		delete[] Namebase;
		delete[] Extension;
		delete[] Buffer;
		delete[] Source;
	}

	delete[] FileName;

}