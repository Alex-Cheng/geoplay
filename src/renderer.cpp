#include "Renderer.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

namespace Renderer {

    // 渲染引擎初始化
    void Init(HWND hwnd) {
        bgfx::Init init;
        init.type = bgfx::RendererType::OpenGL;  // 可以替换为你选择的图形 API，如 Vulkan 或 D3D
        init.platformData.nwh = hwnd;           // 将窗口句柄传递给 bgfx
        bgfx::init(init);
    }

    // 渲染一帧
    void RenderFrame() {
        bgfx::touch(0);  // 清空帧缓存
        bgfx::frame();   // 提交渲染命令并更新帧缓冲
    }

}
