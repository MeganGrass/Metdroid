// Metdroid.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "main.h"

// System Includes
#include SYSTEM
System_File ISystem_File, * File;

// Metroid
enum METROID_GAME {
    SUPER,
    FUSION,
    ZERO
};
#include "..\..\Metroid\super\sram.h"
#include "..\..\Metroid\fusion\fsram.h"
#include "..\..\Metroid\zero\zsram.h"
SMetroid ISMetroid, * SMet;
Fusion IFusion, * MFusion;
ZeroMission IZeroMission, * MZero;
UINT GameTitle = SUPER;

// System Initialization
VOID InitFramework(VOID) {
    File = &ISystem_File;

	// Super Metroid
    SMet = &ISMetroid;
    SMet->File = &ISystem_File;

    // Metroid Fusion
    MFusion = &IFusion;
    MFusion->File = &ISystem_File;

    // Metroid Zero Mission
    MZero = &IZeroMission;
    MZero->File = &ISystem_File;
}

// Windows
VOID CommandLine(CONST CHAR* Command) {

    CHAR* szFileName;

    // Parse
    UINT nArg = File->GetArgCount((CHAR*)Command);
    for (UINT n = 0; n < nArg; n++)
    {
        // Command
        CHAR* _Str1 = File->ToUpper(File->GetArg(n, (CHAR*)Command));

        // GAME
        if (!strcmp((CONST CHAR*)_Str1, "SUPER")) { GameTitle = SUPER; }
        if (!strcmp((CONST CHAR*)_Str1, "FUSION")) { GameTitle = FUSION; }
        if (!strcmp((CONST CHAR*)_Str1, "ZERO")) { GameTitle = ZERO; }

        // UPDATE
        if (!strcmp((CONST CHAR*)_Str1, "UPDATE")) {
            switch (GameTitle)
            {
            case SUPER:
                szFileName = File->GetFilename("SRM", "Super Metroid SRAM (*.SRM)\0*.SRM\0\0");
                SMet->Update(szFileName);
                break;
            case FUSION:
                szFileName = File->GetFilename("SAV", "Metroid Fusion SRAM (*.SAV)\0*.SAV\0\0");
                MFusion->Update(szFileName);
                break;
            case ZERO:
                szFileName = File->GetFilename("SAV", "Metroid Zero Mission SRAM (*.SAV)\0*.SAV\0\0");
                MZero->Update(szFileName);
                break;
            }
        }

        // IMPORT
        if (!strcmp((CONST CHAR*)_Str1, "IMPORT")) {
            switch (GameTitle)
            {
            case SUPER:
                szFileName = File->GetFilename("SRM", "Super Metroid SRAM (*.SRM)\0*.SRM\0\0");
                SMet->Import(File->ToIntU(File->GetArg(n + 1, (CHAR*)Command)), szFileName);
                break;
            case FUSION:
                szFileName = File->GetFilename("SAV", "Metroid Fusion SRAM (*.SAV)\0*.SAV\0\0");
                MFusion->Import(File->ToIntU(File->GetArg(n + 1, (CHAR*)Command)), szFileName);
                break;
            case ZERO:
                szFileName = File->GetFilename("SAV", "Metroid Zero Mission SRAM (*.SAV)\0*.SAV\0\0");
                MZero->Import(File->ToIntU(File->GetArg(n + 1, (CHAR*)Command)), szFileName);
                break;
            }
        }

        // EXPORT
        if (!strcmp((CONST CHAR*)_Str1, "EXPORT")) {
            switch (GameTitle)
            {
            case SUPER:
                szFileName = File->GetFilename("SRM", "Super Metroid SRAM (*.SRM)\0*.SRM\0\0");
                SMet->Export(File->ToIntU(File->GetArg(n + 1, (CHAR*)Command)), szFileName);
                break;
            case FUSION:
                szFileName = File->GetFilename("SAV", "Metroid Fusion SRAM (*.SAV)\0*.SAV\0\0");
                MFusion->Export(File->ToIntU(File->GetArg(n + 1, (CHAR*)Command)), szFileName);
                break;
            case ZERO:
                szFileName = File->GetFilename("SAV", "Metroid Zero Mission SRAM (*.SAV)\0*.SAV\0\0");
                MZero->Export(File->ToIntU(File->GetArg(n + 1, (CHAR*)Command)), szFileName);
                break;
            }
        }

        // CLEAR
        if (!strcmp((CONST CHAR*)_Str1, "CLEAR")) {
            switch (GameTitle)
            {
            case SUPER:
                szFileName = File->GetFilename("SRM", "Super Metroid SRAM (*.SRM)\0*.SRM\0\0");
                SMet->Clear(File->ToIntU(File->GetArg(n + 1, (CHAR*)Command)), szFileName);
                break;
            case FUSION:
                szFileName = File->GetFilename("SAV", "Metroid Fusion SRAM (*.SAV)\0*.SAV\0\0");
                MFusion->Clear(File->ToIntU(File->GetArg(n + 1, (CHAR*)Command)), szFileName);
                break;
            case ZERO:
                szFileName = File->GetFilename("SAV", "Metroid Zero Mission SRAM (*.SAV)\0*.SAV\0\0");
                MZero->Clear(File->ToIntU(File->GetArg(n + 1, (CHAR*)Command)), szFileName);
                break;
            }
        }

        // COPY (WIP)
        if (!strcmp((CONST CHAR*)_Str1, "COPY")) {
            switch (GameTitle)
            {
            case SUPER:
                break;
            case FUSION:
                break;
            case ZERO:
                break;
            }
        }

        // DISASSEMBLE (WIP)
        if (!strcmp((CONST CHAR*)_Str1, "DIS")) {
            switch (GameTitle)
            {
            case SUPER:
                break;
            case FUSION:
                break;
            case ZERO:
                szFileName = File->GetFilename("SAV", "Metroid Zero Mission SRAM (*.SAV)\0*.SAV\0\0");
                MZero->Disassemble(szFileName);
                break;
            }
        }
    }

}
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

    // Commandline
    if (strlen(lpCmdLine)) {
        InitFramework();
        CommandLine(lpCmdLine);
    }

    // Terminate
    return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) { return 0; }
