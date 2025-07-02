# 创建前端构建目标
add_custom_target(react-ui ALL
    COMMAND npm install
    COMMAND npm run build
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building React UI"
)

# 设置前端输出目录
set(UI_BUILD_DIR ${BUILD_DIR}/ui)

# 复制前端构建结果到输出目录
add_custom_command(TARGET react-ui POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${UI_BUILD_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/build
        ${UI_BUILD_DIR}
    COMMENT "Copying UI build to ${UI_BUILD_DIR}"
)
