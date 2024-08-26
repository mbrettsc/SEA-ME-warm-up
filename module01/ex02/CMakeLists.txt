cmake_minimum_required(VERSION 3.10)

project(ex02)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Werror)

set(SOURCE_FILES
    main.cpp
    ACar.cpp
    SportsCar.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

