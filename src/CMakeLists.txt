cmake_minimum_required(VERSION 3.5.1)
include_directories(${LD_LIBRARY_PATH}/headers)
set(SRC_LIST main.c)
add_executable(main ${SRC_LIST})
