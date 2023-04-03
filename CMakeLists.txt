cmake_minimum_required(VERSION 3.0.0)
project(Gobang VERSION 0.1.0)
aux_source_directory("./" SRC_LIST)
add_executable(Gobang ${SRC_LIST})
