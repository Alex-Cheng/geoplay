#ifndef RENDERER_H
#define RENDERER_H

#include <windows.h>  // 如果你使用 Windows 环境，包含 Windows 头文件

namespace Renderer {
    // 渲染引擎初始化函数
    void Init(HWND hwnd);

    // 渲染帧函数
    void RenderFrame();
}

#endif // RENDERER_H
