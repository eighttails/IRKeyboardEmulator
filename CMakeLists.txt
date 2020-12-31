cmake_minimum_required(VERSION 3.5)

project(IRKeyboardEmulator LANGUAGES CXX)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(IRKeyboardEmulator handle_input.cpp p6_keycodes.cpp send_ir.cpp main.cpp)
target_link_libraries(IRKeyboardEmulator ${CURSES_LIBRARIES})
