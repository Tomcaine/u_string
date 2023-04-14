cmake_minimum_required(VERSION 3.25)
project(u_string)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(u_string src/main.cpp src/datenSatzVerwaltung.cpp inc/datenSatzVerwaltung.h inc/personalM.h)

target_include_directories(
        u_string
        PRIVATE inc
)