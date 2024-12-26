cmake_minimum_required(VERSION 3.29)
project(calculator C)

include_directories(/)

set(CMAKE_C_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(calculator
        cfiles/main.c
        cfiles/calculate.c
        cfiles/preCalculate.c
        cfiles/screenPrinting.c
        cfiles/change.c

        cfiles/calculator.h)