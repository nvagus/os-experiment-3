cmake_minimum_required(VERSION 3.5.1)
add_executable(pipe pipe.c utils.c)
add_executable(fifo fifo.c utils.c)
add_executable(msg msg.c utils.c)
