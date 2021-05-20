#include <stdio.h>
#include <windows.h>

int main()
{
    wchar_t gameCMD[] = L"\"RED\\Binaries\\Win64\\RED-Win64-Shipping.exe\" -eac-nop-loaded";
    DWORD errorCode = 0;

    STARTUPINFO s_info;
    PROCESS_INFORMATION p_info;
    ZeroMemory(&s_info, sizeof(s_info));
    s_info.cb = sizeof(s_info);
    ZeroMemory(&p_info, sizeof(p_info));

    printf("DRAGON BALL FighterZ - custom launcher by Erik JS\n\n");
    printf("Launching: %S\n\n", gameCMD);

    if (CreateProcess(NULL, gameCMD, NULL, NULL, FALSE, NULL, NULL, NULL, &s_info, &p_info))
    {
        printf("Starting game...\n");
        WaitForSingleObject(p_info.hProcess, INFINITE);
        CloseHandle(p_info.hProcess);
        CloseHandle(p_info.hThread);
    }
    else
    {
        errorCode = GetLastError();
        printf("CreateProcess failed. GetLastError = %d", errorCode);
        Sleep(3000);
    }

    return errorCode;
}
