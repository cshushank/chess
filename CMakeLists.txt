cmake_minimum_required(VERSION 3.23)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp Board.cpp Board.h Piece.cpp Piece.h)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Chess sfml-system sfml-window sfml-graphics sfml-audio sfml-network)