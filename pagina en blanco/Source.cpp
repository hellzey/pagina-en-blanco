#include <windows.h>
#include "resource.h"

HWND ghDlg = 0;

BOOL CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    ghDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC)WindowProc);
    ShowWindow(ghDlg, nCmdShow);
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));
    while (GetMessage(&msg, 0, 0, 0))
    {
        if (ghDlg == 0 || !IsDialogMessage(ghDlg, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}

BOOL CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

    case WM_INITDIALOG:
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
    
        }
        break;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    }

    return FALSE;
}