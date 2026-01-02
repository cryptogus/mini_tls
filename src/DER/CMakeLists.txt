project(der2json)

cmake_minimum_required(VERSION 3.22)

find_package(jsoncpp REQUIRED)


set(SOURCES
    der_reader.cpp
)

#option(SHARED "Build shared library" OFF)

#[[if(SHARED)
    add_library(der2json SHARED ${SOURCES})
else()
    add_library(der2json STATIC ${SOURCES})
endif()
]]

# BUILD_SHARED_LIBS
add_library(der2json ${SOURCES})

target_link_libraries(der2json PRIVATE jsoncpp)