
#include "system.h"

// Format
CHAR * System_Configuration_A::Format(CONST CHAR * _Format, ...) {

	// 
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _Format);
	_StrLen = (_vscprintf(_Format, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(_StrLen * 2)];
	RtlSecureZeroMemory(_Buffer, (_StrLen * 2));
	vsprintf_s(_Buffer, _StrLen, _Format, _ArgList);
	__crt_va_end(_ArgList);

	// complete
	return _Buffer;
}
WCHAR * System_Configuration_A::Format(CONST WCHAR * _Format, ...) {

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
// Open
pINI System_Configuration_A::Open(CHAR * _FileName, ...) {

	// parse
	CHAR * FileName = Format(_FileName);
	if (!File->Exists(FileName)) { delete[]FileName; return NULL; }

	// open
	_iobuf * _File = File->Open(READ_FILE, FileName);
	if (!_File) { delete[]FileName; return NULL; }
	ULONG _ElementSize = File->Size(_File);

	// Test
	USHORT _Unicode = NULL;
	File->Read(_File, 0x00, &_Unicode, 0x02);
	switch (_Unicode)
	{
	case 0xFEFF:
		Message((CHAR *)APPLICATION_NAME_A, "%s\r\n\r\nANSI text document was expected.", FileName);
		delete[]FileName;
		fclose(_File);
		return NULL;
	break;
	}

	// initialize
	pINI INI = Open(_File, 0x00, _ElementSize);

	// cleanup
	delete[]FileName;
	fclose(_File);

	// terminate
	return INI;
}
pINI System_Configuration_A::Open(_iobuf * FILE, ULONG _Offset, ULONG _ElementSize) {

	// framework
	pINI INI;
	INI = new tagConfigurationSettings;

	// buffer
	INI->_ElementSize = _ElementSize;
	INI->Data = new UCHAR[(INI->_ElementSize + 2)];
	RtlSecureZeroMemory(INI->Data, (INI->_ElementSize + 2));
	File->Read(FILE, _Offset, INI->Data, INI->_ElementSize);

	// buffer
	INI->nLine = 0;
	ULONG Pointer = 0x00;
	BOOL LineDone = FALSE;
	UCHAR Buffer[2];

	// count
	for (ULONG n = 0; n < INI->_ElementSize; n++, Pointer++)
	{
		// complete
		if (Pointer >= INI->_ElementSize) {
			INI->nLine++;
			break;
		}

		memcpy_s(Buffer, 2, &INI->Data[Pointer], 2);

		// test
		switch (Buffer[0])
		{
		case 0x0D:
			if (Buffer[1] != 0x0A) {}
			else { Pointer++; }
			Pointer++;
			LineDone = TRUE;
			break;
		case 0x0A:
			Pointer++;
			LineDone = TRUE;
			break;
		case 0x00:
			if (Buffer[1] != 0x00) {}
			else { Pointer++; }
			Pointer++;
			LineDone = TRUE;
			break;
		}

		// complete
		if (LineDone)
		{
			LineDone = FALSE;
			INI->nLine++;
		}
	}

	// buffer
	Pointer = 0x00;
	BOOL EndD = FALSE;
	BOOL EndA = FALSE;
	ULONG Length = 0x00;
	INI->Offset = new ULONG[INI->nLine];
	INI->Length = new ULONG[INI->nLine];
	INI->StrLen = new ULONG[INI->nLine];

	// data
	for (ULONG n = 0; n < INI->nLine; n++)
	{
		INI->Offset[n] = Pointer;

		Length = 0;
		LineDone = FALSE;
		RtlSecureZeroMemory(Buffer, 2);

		for (ULONG x = 0; x < INI->_ElementSize; x++, Pointer++, Length++)
		{
			// complete
			if (Pointer >= INI->_ElementSize)
			{
				INI->Length[n] = Length;
				INI->StrLen[n] = Length;
				break;
			}

			// end of line
			memcpy_s(&Buffer, 2, &INI->Data[Pointer], 2);
			switch (Buffer[0])
			{
			case 0x0D:
				if (Buffer[1] != 0x0A) {}
				else { EndA = TRUE; Length++; Pointer++; }
				Length++;
				Pointer++;
				EndD = TRUE;
				LineDone = TRUE;
				break;
			case 0x0A:
				Length++;
				Pointer++;
				EndA = TRUE;
				LineDone = TRUE;
				break;
			case 0x00:
				if (Buffer[1] != 0x00) {}
				else { EndA = TRUE; Length++; Pointer++; }
				Length++;
				Pointer++;
				EndD = TRUE;
				LineDone = TRUE;
				break;
			}

			// complete
			if (LineDone)
			{
				INI->Length[n] = Length;
				INI->StrLen[n] = Length;
				if (EndD) { INI->StrLen[n]--; }
				if (EndA) { INI->StrLen[n]--; }
				break;
			}
		}
	}

	// arguments
	INI->nArgs = new ULONG[INI->nLine];
	for (ULONG ID = 0; ID < INI->nLine; ID++)
	{
		INI->nArgs[ID] = GetArgCount(Line(INI, ID));
	}

	// terminate
	return INI;
}
// Read
CHAR * System_Configuration_A::Arg(pINI INI, ULONG iLine, ULONG iArg) {
	CHAR * _Line = Line(INI, iLine);
	ULONG NumArgs = GetArgCount(_Line);
	if (iArg >= NumArgs) {
		return (CHAR *)"\0\0\0\0";
	} else {
		CHAR * Arg = GetArg(iArg, _Line);
		return Arg;
	}
}
CHAR * System_Configuration_A::Line(pINI INI, ULONG iLine) {

	if (!INI->StrLen[iLine]) { return (CHAR *)"\0\0\0\0"; }
	else
	{
		// buffer
		CHAR * _Destination = new CHAR[INI->Length[iLine] + 2];
		RtlSecureZeroMemory(_Destination, (INI->Length[iLine] + 2));
		memcpy_s(&_Destination[0], INI->StrLen[iLine], &INI->Data[INI->Offset[iLine]], INI->StrLen[iLine]);

		// terminate
		return _Destination;
	}

}
CHAR * System_Configuration_A::Line(pINI INI, CHAR * Section, ULONG iLine) {

	iLine++;

	// section
	for (UINT n = 0; n < INI->nLine; n++)
	{
		if (!INI->StrLen[n]) {}
		else
		{
			// buffer
			CHAR * Buffer = new CHAR[INI->Length[n] + 2];
			RtlSecureZeroMemory(Buffer, (INI->Length[n] + 2));
			memcpy_s(&Buffer[0], INI->StrLen[n], &INI->Data[INI->Offset[n]], INI->StrLen[n]);

			// test
			if (strcmp((CONST CHAR *)Buffer, (CONST CHAR *)Section) == 0)
			{
				delete[] Buffer;
				n = (n + iLine);
				if (n >= INI->nLine) { return (CHAR *)"\0\0\0\0"; }
				if (!INI->Length[n]) { return (CHAR *)"\0\0\0\0"; }
				Buffer = new CHAR[INI->Length[n] + 2];
				RtlSecureZeroMemory(Buffer, (INI->Length[n] + 2));
				memcpy_s(&Buffer[0], INI->StrLen[n], &INI->Data[INI->Offset[n]], INI->StrLen[n]);
				return Buffer;
			}

			// cleanup
			delete[] Buffer;
		}
	}

	// terminate
	return (CHAR *)"\0\0\0\0";
}
CHAR * System_Configuration_A::Value(pINI INI, CHAR * Section, CHAR * Key) {

	// temp
	ULONG ID = (ULONG)-1;

	// Section
	for (ULONG n = 0; n < INI->nLine; n++)
	{
		if (!INI->StrLen[n]) { ID = (ULONG)-1; }
		else
		{
			// buffer
			CHAR * Buffer = new CHAR[INI->Length[n] + 2];
			RtlSecureZeroMemory(Buffer, (INI->Length[n] + 2));
			memcpy_s(&Buffer[0], INI->StrLen[n], &INI->Data[INI->Offset[n]], INI->StrLen[n]);

			// test
			if (strcmp((CONST CHAR *)Buffer, (CONST CHAR *)Section) == 0)
			{
				ID = n;
				break;
			}
		}
	}

	// key
	ULONG pNumArgs = 0;
	if (ID != -1)
	{
		for (ULONG n = (ID + 1); n < INI->nLine; n++)
		{
			if (!INI->StrLen[n]) { ID = (ULONG)-1; }
			else
			{
				// buffer
				CHAR * Buffer = new CHAR[INI->Length[n] + 2];
				RtlSecureZeroMemory(Buffer, (INI->Length[n] + 2));
				memcpy_s(&Buffer[0], INI->StrLen[n], &INI->Data[INI->Offset[n]], INI->StrLen[n]);

				// parse
				CHAR ** szArglist = CommandLine(pNumArgs, Buffer);
				Buffer = szArglist[0];

				// test
				if (strcmp((CONST CHAR *)Buffer, (CONST CHAR *)Key) == 0)
				{
					Buffer = szArglist[1];
					return Buffer;
				}
			}
		}
	}

	// terminate
	return (CHAR *)"\0\0\0\0";
}
CHAR * System_Configuration_A::Value(pINI INI, CHAR * Section, CHAR * Key, ULONG iArg) {

	// temp
	ULONG ID = (ULONG)-1;

	// section
	for (ULONG n = 0; n < INI->nLine; n++)
	{
		if (!INI->StrLen[n]) { ID = (ULONG)-1; }
		else
		{
			// buffer
			CHAR * Buffer = new CHAR[INI->Length[n] + 2];
			RtlSecureZeroMemory(Buffer, (INI->Length[n] + 2));
			memcpy_s(&Buffer[0], INI->StrLen[n], &INI->Data[INI->Offset[n]], INI->StrLen[n]);

			// test
			if (strcmp((CONST CHAR *)Buffer, (CONST CHAR *)Section) == 0)
			{
				ID = n;
				break;
			}
		}
	}

	// key
	ULONG pNumArgs = 0;
	if (ID != -1)
	{
		for (ULONG n = (ID + 1); n < INI->nLine; n++)
		{
			if (!INI->StrLen[n]) { ID = (ULONG)-1; }
			else
			{
				// buffer
				CHAR * Buffer = new CHAR[INI->Length[n] + 2];
				RtlSecureZeroMemory(Buffer, (INI->Length[n] + 2));
				memcpy_s(&Buffer[0], INI->StrLen[n], &INI->Data[INI->Offset[n]], INI->StrLen[n]);

				// parse
				CHAR ** szArglist = CommandLine(pNumArgs, Buffer);
				Buffer = szArglist[0];

				// test
				if (strcmp((CONST CHAR *)Buffer, (CONST CHAR *)Key) == 0)
				{
					Buffer = szArglist[iArg + 1];
					return Buffer;
				}
			}
		}
	}

	// terminate
	return (CHAR *)"\0\0\0\0";
}
CHAR * System_Configuration_A::Value(pINI INI, CHAR * Section, ULONG iLine, ULONG iArg) {
	return GetArg(iArg, Line(INI, Section, iLine));
}
ULONG System_Configuration_A::Find(pINI INI, ULONG iLine, CHAR * Key) {

	ULONG nArg = GetArgCount(Line(INI, iLine));
	if (!nArg) { return NULL; }

	for (ULONG iArg = 0; iArg < nArg; iArg++)
	{
		if (!StrCmpA(Key, Arg(INI, iLine, iArg))) {
			return iArg;
		}
	}

	// Terminate
	return NULL;
}
ULONG System_Configuration_A::SectionLine(pINI INI, CHAR * Section) {

	for (UINT n = 0; n < INI->nLine; n++)
	{
		if (!INI->StrLen[n]) {}
		else
		{
			// buffer
			CHAR * Str = new CHAR[INI->Length[n] + 2];
			RtlSecureZeroMemory(Str, (INI->Length[n] + 2));
			memcpy_s(&Str[0], INI->StrLen[n], &INI->Data[INI->Offset[n]], INI->StrLen[n]);

			// test
			if (strcmp((CONST CHAR *)Str, (CONST CHAR *)Section) == 0) {
				return (n + 1);
			}
		}
	}

	// Terminate
	return NULL;
}
// Write
BOOL System_Configuration_A::Extract(pINI INI, ULONG LineStart, ULONG LineFinish, CONST CHAR * _OutputFile, ...) {

	// Error
	if (!INI) { return FAIL; }
	if (LineStart >= INI->nLine) { return FAIL; }
	if (LineFinish >= INI->nLine + 1) { return FAIL; }

	// Format
	va_list _ArgList = { NULL };
	__crt_va_start(_ArgList, _OutputFile);
	size_t _BufferCount = (_vscprintf(_OutputFile, _ArgList) + 2);
	CHAR * _Buffer = new CHAR[(_BufferCount * 2)];
	RtlSecureZeroMemory(_Buffer, (_BufferCount * 2));
	vsprintf_s(_Buffer, _BufferCount, _OutputFile, _ArgList);
	__crt_va_end(_ArgList);

	// Error
	if (!strlen(_Buffer)) { delete[] _Buffer; return FAIL; }

	// Write
	ULONG _ElementSize = (INI->Offset[LineFinish] - INI->Offset[LineStart]);
	BOOL Result = File->CreateFromSource(&INI->Data[INI->Offset[LineStart]], _ElementSize, _Buffer);
	delete[] _Buffer;

	// Terminate
	return Result;
}
// Cleanup
VOID System_Configuration_A::Close(pINI INI) {

	delete[] INI->Offset;
	delete[] INI->Length;
	delete[] INI->StrLen;
	delete[] INI->Data;
	INI->nLine = 0;
	INI->_ElementSize = 0;

	delete[] INI;
}