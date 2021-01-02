cmake_minimum_required(VERSION 3.5)

project(IRKeyboardEmulator LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

#Build without pigpio (for prototype)
add_compile_definitions(IR_STUB)

add_executable(IRKeyboardEmulator handle_input.cpp p6_keycodes.cpp send_ir.cpp main.cpp)
