cmake_minimum_required(VERSION 3.5)

project(Phonebook)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Werror)

set(SOURCE_FILES
    Phonebook.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
