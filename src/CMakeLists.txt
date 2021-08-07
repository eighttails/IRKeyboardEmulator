cmake_minimum_required(VERSION 3.5)

project(IRKeyboardEmulator LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

option(IR_STUB "Build without pigpio (for prototype)" OFF)
if(IR_STUB)
    add_definitions(-DIR_STUB)
else()
    set(CMAKE_EXE_LINKER_FLAGS "-lpigpiod_if2")
endif()

add_executable(IRKeyboardEmulator handle_input.cpp p6_keycodes.cpp send_ir.cpp main.cpp)
install (TARGETS IRKeyboardEmulator DESTINATION bin)
