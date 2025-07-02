cmake_minimum_required(VERSION 3.18)

# 设置项目名和版本
project(GeoPlay VERSION 1.0)

# 添加子模块路径
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# 配置构建目录
set(BUILD_DIR ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/bin)

# 设置 CEF 路径（全局变量，供子目录使用）
set(CEF_PATH ${CMAKE_SOURCE_DIR}/external/cef CACHE PATH "CEF library path")

# 添加子目录
add_subdirectory(src)
add_subdirectory(ui)
