cmake_minimum_required(VERSION 2.8)
project( oj3I )

# 寻找目录下的所有源文件
aux_source_directory( . SRC_LIST )

# 添加头文件目录
add_executable( ${PROJECT_NAME} ${SRC_LIST} )