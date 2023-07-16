cmake_minimum_required(VERSION 3.10)

#set the project name
project(Music_Compresssion)

#set variables
set(SOURCES src/fileManagement.cc src/audioCompression.cc src/readWavFile.cc)
set(HEADERS includes/fileManagement.hpp includes/audioCompression.hpp includes/readWavFile.hpp)

set(TEST_INCLUDE_FILES catch/catch.hpp ${HEADERS})
set(TEST_SOURCE_FILES catch/catchmain.cpp  tests/tests.cc ${SOURCES})

#define variable to use from cmake
configure_file(config.h.in ${CMAKE_BINARY_DIR}/config.h)
include_directories(${CMAKE_BINARY_DIR})

#build directories as libraries, might need for later
file (GLOB LIB_SOURCES src/*.cc)
file(GLOB LIB_HEADERS includes/*.hpp)
add_library(Lib ${LIB_SOURCES} ${LIB_HEADERS})
#set c++ version
set(CMAKE_CXX_STANDARD 20)

#set the target include directory
include_directories(includes)
include_directories(${CMAKE_BINARY_DIR})

#set dependencies
add_subdirectory(JUCE)
#set the compile options

#Testing executable
add_executable(test ${TEST_INCLUDE_FILES} ${TEST_SOURCE_FILES})

#Normal executable
add_executable(mc src/main.cc ${SOURCES} ${HEADERS})
#target_link_libraries(mc $Lib)