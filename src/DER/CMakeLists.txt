project(der2json)

cmake_minimum_required(VERSION 3.22)

find_package(jsoncpp REQUIRED)

set(SOURCES
    der_reader.cpp
    der2json.cpp
    ../mpz.cpp
)

# BUILD_SHARED_LIBS
add_library(der2json ${SOURCES})

target_link_libraries(der2json PRIVATE jsoncpp gmp)
target_link_directories(der2json PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../)