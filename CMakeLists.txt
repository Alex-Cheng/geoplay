cmake_minimum_required(VERSION 3.18)

# 设置项目名和版本
project(GeoPlay VERSION 1.0)

# 设置 C++ 标准为 C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 配置构建目录
set(BUILD_DIR ${CMAKE_BINARY_DIR}/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/bin)

# 添加子模块路径
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# 添加子目录
add_subdirectory(src)
add_subdirectory(external/cef)
add_subdirectory(external/bgfx)

# 配置 CEF 和 bgfx 路径
set(CEF_PATH ${CMAKE_SOURCE_DIR}/external/cef)
include_directories(${CEF_PATH}/include)
link_directories(${CEF_PATH}/lib)

# 配置 bgfx
set(BGFX_DIR ${CMAKE_SOURCE_DIR}/external/bgfx)
include_directories(${BGFX_DIR}/include)
link_directories(${BGFX_DIR}/lib)

# 设置可执行文件
add_executable(GeoPlay src/main.cpp)

# 链接库
target_link_libraries(GeoPlay CEF bgfx)

# 添加 UI 构建设置
add_custom_target(react-ui ALL
    COMMAND npm install
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/ui
)
