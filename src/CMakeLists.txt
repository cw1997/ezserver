# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (ezserver)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加子目录
#add_subdirectory(core)
add_subdirectory(log)

# 指定生成目标 
add_executable(run main.c)

# 生成链接库
add_library (main ${DIR_SRCS})

# 添加链接库
target_link_libraries(run main)
#target_link_libraries(run core)
target_link_libraries(run log)


# set(CMAKE_EXE_LINKER_FLAGS "-lpthread -fno-builtin")
