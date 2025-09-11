cmake_minimum_required(VERSION 4.0)
project(schort)

add_executable(schort
        src/main.cpp
        src/tokenaries/token_type.hpp
        src/tokenaries/tokenizer.cpp
        src/tokenaries/tokenizer.hpp
        src/tokenaries/token.hpp
        src/tokenaries/token.cpp
)
