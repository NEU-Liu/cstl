cmake_minimum_required(VERSION 3.10)
project(Libcstl C)

set(CMAKE_C_STANDARD 99)

file(GLOB cstlh "./cstl/*.h")
file(GLOB cstlc "./cstlsrc/*.c")
add_executable(Libcstl main.c ${cstlh} ${cstlc})
