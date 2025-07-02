# GeoPlay 项目

**GeoPlay** 是一个基于 **C++** 和 **React** 的几何建模实验平台，旨在为研究和开发几何建模和渲染技术提供一个跨平台的高效环境。该项目支持 **C++ 后端渲染**（如 **OpenGL/bgfx**），并且通过 **React** 提供现代化的 **HTML UI**。项目可支持将 **CEF**（Chromium Embedded Framework）嵌入到 C++ 窗口中，提供现代的、响应式的用户界面。

---

## 🎯 项目目标

* **C++ 后端**：基于 **C++** 进行几何建模、渲染及相关计算。
* **跨平台支持**：当前在 Windows 上运行，未来支持 macOS 和 Linux。
* **UI 与渲染交互**：通过 **React** 提供交互式 UI，用户可通过界面创建几何体、调整参数、控制渲染等。
* **高效渲染**：支持高效的几何图形渲染，使用 **bgfx** 或 **OpenGL**。
* **现代 UI**：使用 **Fluent UI** 进行 Windows 风格的界面设计。

---

## 📋 主要功能

* **几何建模**：支持创建基本几何体（如立方体、球体、圆锥等）。
* **实时渲染**：通过 **OpenGL/bgfx** 渲染创建的几何体。
* **UI 控制**：用户可以通过 **React** UI 进行几何体的控制（例如旋转、缩放、平移）。
* **文件操作**：支持导入和导出模型（例如：STL, OBJ, GLTF）。

---

## 🛠️ 技术栈

* **前端**：

  * **React**（组件化开发）
  * **Fluent UI**（Windows 风格组件）
  * **CEF**（Chromium Embedded Framework）嵌入
  * **Vite**（用于构建和开发 React 应用）
* **后端**：

  * **C++23**（核心几何建模与渲染逻辑）
  * **bgfx** 或 **OpenGL**（图形渲染引擎）
  * **Win32 API**（用于创建窗口和与 React UI 的交互）

---

## 🚀 安装与运行

### 1. **克隆项目**

```bash
git clone https://github.com/yourusername/GeoPlay.git
cd GeoPlay
```

### 2. **构建 C++ 部分**

1. **安装依赖**：

   * 确保安装了 **CMake** 和 **Visual Studio** 或 **Ninja**（Windows 环境）。
   * 安装 **CEF** 和 **bgfx** 子模块：

     ```bash
     git submodule update --init --recursive
     ```

2. **配置和生成构建文件**：

   * 在项目根目录运行以下命令来配置项目：

     ```bash
     cmake -S . -B build
     ```

3. **构建项目**：

   * 使用 CMake 构建项目：

     ```bash
     cmake --build build --config Release
     ```

### 3. **构建 React UI 部分**

1. **进入 `ui/` 目录**：

   ```bash
   cd ui
   ```

2. **安装 Node.js 依赖**：

   * 确保已经安装了 **Node.js** 和 **npm**。
   * 安装项目依赖：

     ```bash
     npm install
     ```

3. **启动开发服务器**：

   ```bash
   npm run start
   ```

4. **构建静态文件**：

   * 使用 **Vite** 构建生产版本的 UI 文件：

     ```bash
     npm run build
     ```

   * 将构建后的文件部署到 C++ 项目中（可通过 `src/` 文件夹中适当的路径进行配置）。

### 4. **运行项目**

* 启动 C++ 可执行文件，UI 将通过 **CEF** 嵌入并与后端渲染交互。

---

## 📂 项目结构

```
GeoPlay/
├── CMakeLists.txt          # CMake 配置文件
├── external/               # 子模块（如 CEF, bgfx, GLFW）
├── src/                    # C++ 源码（渲染与 CEF 通信）
│   ├── main.cpp            # 主程序入口
│   ├── Renderer/           # 渲染逻辑（bgfx 或 OpenGL）
│   └── UIBridge/           # C++ 与 React UI 通信
├── ui/                     # React UI 部分
│   ├── package.json        # React 项目配置文件
│   └── src/                # React 组件与页面
├── build/                  # 构建目录
└── README.md               # 项目文档
```

---

## 📝 如何贡献

1. **Fork 本仓库**，并将更改提交到自己的仓库。
2. 创建一个新的分支（`feature-xxx`）。
3. 提交你的更改并发起 **Pull Request**。

---

## ⚙️ 依赖

* **CMake**：用于跨平台构建管理。
* **CEF (Chromium Embedded Framework)**：用于将 React UI 嵌入到 C++ 项目中。
* **bgfx/OpenGL**：图形渲染引擎，用于高效渲染几何体。
* **React**：用于构建现代化的 UI 界面。
* **Fluent UI**：Windows 风格的 UI 组件库。
* **Vite**：快速构建工具，用于开发和构建 React 应用。

---

## 📄 许可证

本项目采用 [MIT 许可证](https://opensource.org/licenses/MIT)。您可以自由使用、修改、分发该代码。

---

## 📧 联系方式

如果您有任何问题或建议，欢迎通过以下方式联系我：

* GitHub：[Alex Cheng](https://github.com/Alex-Cheng)
* 邮箱：[chengxinalexcheng@qq.com](mailto:your.email@example.com)
