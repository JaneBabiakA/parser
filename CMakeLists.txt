cmake_minimum_required(VERSION 3.28)
project(parser)

set(CMAKE_CXX_STANDARD 17)

add_executable(parser main.cpp
        lexer.h
        parser.h)
