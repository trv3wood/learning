cmake_minimum_required(VERSION 2.8)
project( oj3I )
aux_source_directory( . SRC_LIST )
add_executable( ${PROJECT_NAME} ${SRC_LIST} )