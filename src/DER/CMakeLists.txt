project(der2json)

cmake_minimum_required(VERSION 3.22)

find_package(jsoncpp REQUIRED)

option(SHARED "Build shared library" OFF)

set(SOURCES
    der_reader.cpp
)

# SHARED=ON to build shared library
if(SHARED)
    add_library(der2json SHARED ${SOURCES})
else()
    add_library(der2json STATIC ${SOURCES})
endif()

target_link_libraries(der2json PRIVATE jsoncpp)