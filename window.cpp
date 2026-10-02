#include <windows.h>
using namespace std;
void openurl(const wchar_t* url) {
    ShellExecuteW(nullptr, L"open",url,nullptr,nullptr,SW_SHOWNORMAL);
}
LRESULT CALLBACK  WndProc(
    HWND hwnd,
    UINT umsg,
    WPARAM wparam,
    LPARAM lparam
    ) {
    if (umsg ==WM_COMMAND) {
        if (LOWORD(wparam) == 1001) {
            openurl(L"https://google.com");
        }
    }
    else
    return DefWindowProc(hwnd, umsg, wparam, lparam);
}
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
    ) {
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"WinTool bradar";
    RegisterClassW(&wc);
    HWND hwnd = CreateWindowExW(
        0,
        L"WinTool bradar",
        L"WinTool bradar",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        900,
        600,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );
    ShowWindow(hwnd,nCmdShow);
    UpdateWindow(hwnd);
    HWND button = CreateWindowExW(
    0,
    L"BUTTON",
    L"SYSTEM INFO",
    WS_VISIBLE | WS_CHILD,
    30,
    30,
    220,
    50,
    hwnd,
    HMENU(1001),
    hInstance,
    nullptr
    );
    MSG Msg;
    while (GetMessage(&Msg,nullptr, 0 ,0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}
