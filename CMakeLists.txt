project(nopassdb)
cmake_minimum_required(VERSION 2.8)

# If no build type is set (ex: Debug), default to 'Release'
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Set compiler mode to C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if(WIN32)
    # Staticly include
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif(WIN32)

#include_directories(src)

# Internal source files
    #aux_source_directory(. SRC_LIST)
set(SRC_LIST
    src/main.cpp
    src/nopassdb/nopassdb.cpp
    src/nopassdb/arghelp.cpp
    src/nopassdb/clipboard.cpp
    src/nopassdb/config.cpp
    src/nopassdb/hash.cpp
    src/nopassdb/password.cpp
)

# Seperate header files without a matching .cpp file
set(SRC_HEADERS
    src/main.h
)

# Libraries
set(LIB_LIST
    lib/getoptpp/getopt_pp.cpp
)

# Library header files
set(LIB_HEADERS
    lib/sha512.hh
    lib/base64.hh
)

# Link all files to executable
add_executable(${PROJECT_NAME}
                ${SRC_LIST}
                ${SRC_HEADERS}
                ${LIB_LIST}
                ${LIB_HEADERS})
