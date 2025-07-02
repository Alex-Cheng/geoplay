# 设置 C++ 标准（仅影响 C++ 代码）
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含 CEF 头文件
include_directories(${CEF_PATH}/include)
link_directories(${CEF_PATH}/lib)

# 收集所有 C++ 源文件
#file(GLOB_RECURSE SOURCES "*.cpp" "*.h")
# 创建可执行文件
#add_executable(GeoPlay ${SOURCES})

# 手动管理源文件
add_executable(GeoPlay
    main.cpp            # 主程序入口
    renderer.cpp        # 渲染引擎实现
    uibridge.cpp        # UI 与 C++ 通信实现
)

# 将头文件路径添加到目标的包含目录
target_include_directories(GeoPlay 
    PRIVATE
    ${CMAKE_SOURCE_DIR}/external/cef/include
    ${CMAKE_SOURCE_DIR}/external/bgfx/include
)

# 你可以在此处添加更多的静态资源路径
# target_include_directories(GeoPlay PRIVATE ${CMAKE_SOURCE_DIR}/resources)


# 设置目标链接的库
target_link_libraries(GeoPlay 
    PRIVATE
    bgfx                # 渲染库
    CEF                 # CEF 嵌入
)

# 依赖前端构建（确保前端先构建）
add_dependencies(GeoPlay react-ui)
