project(tests)

cmake_minimum_required(VERSION 3.22)

find_package(jsoncpp REQUIRED)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../DER/der_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../DER/der2json.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../PEM/get_info.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../base64/base64.cpp
)

set(TEST_SOURCES
    pem2json_test.cpp
)

add_executable(pem2json_test ${TEST_SOURCES} ${SOURCES})
target_link_libraries(pem2json_test PRIVATE jsoncpp)
target_include_directories(pem2json_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../DER
                                              ${CMAKE_CURRENT_SOURCE_DIR}/../PEM
                                              ${CMAKE_CURRENT_SOURCE_DIR}/../base64)
