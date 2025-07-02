#include <windows.h>
#include "cef_app.h"
#include "Renderer.h"
#include "UIBridge.h"

// Win32 主程序入口
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    // 初始化 CEF
    CefMainArgs main_args(hInstance);
    CefRefPtr<UIBridge> ui_bridge = new UIBridge();

    CefSettings settings;
    CefInitialize(main_args, settings, ui_bridge, nullptr);

    // 创建渲染窗口并启动 CEF
    HWND hwnd = CreateMainWindow();
    RunRenderingLoop(hwnd);

    // 清理
    CefShutdown();
    return 0;
}

// 创建主窗口函数
HWND CreateMainWindow() {
    // 创建 Win32 窗口
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"GeoPlayWindow";

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, L"GeoPlayWindow", L"GeoPlay", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, nullptr, nullptr, wc.hInstance, nullptr);

    ShowWindow(hwnd, SW_SHOW);
    return hwnd;
}

// 渲染循环
void RunRenderingLoop(HWND hwnd) {
    // 初始化 bgfx 或 OpenGL 渲染系统
    Renderer::Init(hwnd);

    // 进入渲染循环
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        // 渲染更新
        Renderer::RenderFrame();
    }
}
