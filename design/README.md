# 🧩 GeoPlay 项目方案文档（原型阶段）

## 📌 项目目标

构建一个基于 C++ 的跨平台几何建模实验平台，具备如下特性：

* 脱离 Visual Studio，使用 CMake + 子模块组织结构；
* 基于 HTML/JS 的 UI，支持未来跨平台嵌入（如 macOS、Linux）；
* 高性能 2D/3D 几何渲染（如 bgfx/OpenGL）；
* 支持前端 UI 与后端建模逻辑的实时交互；
* 初期运行于 Windows，未来具备可移植性。

---

## 🏗️ 项目结构设计

```
GeoPlay/
├── CMakeLists.txt
├── external/               # 子模块（如 bgfx、CEF、glfw）
├── src/
│   ├── main.cpp            # Win32 主程序入口
│   ├── Renderer/           # 渲染模块（如 bgfx 封装）
│   ├── UIBridge/           # CEF 通信与调度模块
├── ui/                     # React UI 工程（HTML/JS/CSS）
├── resources/              # 静态资源
└── build/
```

---

## 🔧 构建系统

* **使用工具**：CMake + Ninja/VS/Mingw（支持多平台）；
* **依赖管理**：

  * 使用 `git submodule` 管理 CEF、bgfx、GLFW；
  * 或使用 CMake `FetchContent` 拉取外部库；
* **构建 UI**：`ui/` 目录为 React 工程，使用 Vite 构建为静态文件嵌入。

---

## 🖥️ UI 框架（React + Fluent UI）

| 框架            | 说明                             |
| ------------- | ------------------------------ |
| React         | 主界面框架，支持组件化、状态管理等              |
| Fluent UI     | 微软官方 UI 库，完美仿 Windows 10/11 风格 |
| WinBox.js（可选） | 模拟子窗口效果（例如工具属性窗）               |
| Vite          | 前端打包工具，构建静态 HTML/CSS/JS 资源     |

**UI组件结构建议：**

```tsx
<App>
  <RibbonBar />     // Fluent UI CommandBar
  <SidePanel />     // 功能菜单/对象列表
  <RendererPanel /> // 渲染输出区域（C++嵌入窗口）
</App>
```

---

## 🎮 渲染系统（C++）

| 引擎     | 说明                             |
| ------ | ------------------------------ |
| bgfx   | 高性能跨平台图形库，支持 D3D/OpenGL/Vulkan |
| OpenGL | 简洁易上手，可先用于原型阶段快速迭代             |
| GLFW   | 创建跨平台渲染窗口，托管 OpenGL 上下文        |

**窗口布局建议：**

* 主窗口为 Win32 创建；
* React UI 使用 CEF 嵌入左侧功能区；
* 渲染窗口右侧独立绘图区域（OpenGL/bgfx）；

---

## 🔗 JS 与 C++ 通信机制（基于 CEF）

| 通信方向     | 技术方法                         | 示例                                 |
| -------- | ---------------------------- | ---------------------------------- |
| JS → C++ | `cefQuery` / `window.cefAPI` | `sendMessage("createCube", {...})` |
| C++ → JS | `ExecuteJavaScript()`        | `onRenderComplete("frame done")`   |

**数据格式建议（JSON）**：

```json
{
  "type": "create",
  "shape": "cube",
  "params": { "x": 0, "y": 0, "z": 0, "size": 1 }
}
```

---

## 📦 示例工作流

1. 用户在 React UI 中点击 “创建立方体”；
2. JS 通过 `window.cefAPI.sendMessage(...)` 发送消息；
3. C++ 拦截消息并添加渲染命令；
4. 渲染引擎（OpenGL/bgfx）刷新画面；
5. 渲染完成后通过 `ExecuteJavaScript(...)` 通知 React 更新 UI 状态。

---

## ✅ 下一步开发建议

| 阶段      | 目标                                |
| ------- | --------------------------------- |
| ✅ 原型搭建  | Win32 + CEF + OpenGL + React 成功集成 |
| ⏳ 组件开发  | Ribbon、几何体控制、视图操作等 UI 模块          |
| ⏳ 渲染扩展  | 添加更多几何体类型、参数控制、动画支持               |
| ⏳ 文件支持  | 导入/导出 STL、OBJ、GLTF 等模型格式          |
| ⏳ 跨平台移植 | 使用 bgfx 替换 OpenGL，移植 macOS/Linux  |

---

如需，我可以：

* ✅ 帮你生成一个完整可编译的 C++ + CEF + React 原型工程；
* ✅ 提供前端和后端通信代码样板；
* ✅ 定义初期支持的几何体、参数控制列表。
