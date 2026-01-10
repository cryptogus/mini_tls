cmake_minimum_required(VERSION 3.14)
project(tests)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(jsoncpp REQUIRED)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../DER/der_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../DER/der2json.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../PEM/get_info.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../base64/base64.cpp
    ../mpz.cpp
)

set(TEST_SOURCES
    pem2json_test.cpp
)

add_executable(pem2json_test ${TEST_SOURCES} ${SOURCES})

enable_testing()
target_link_libraries(pem2json_test PRIVATE jsoncpp gmp GTest::gtest_main)
target_include_directories(pem2json_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../DER
                                              ${CMAKE_CURRENT_SOURCE_DIR}/../PEM
                                              ${CMAKE_CURRENT_SOURCE_DIR}/../base64
                                              ../)

include(GoogleTest)
gtest_discover_tests(pem2json_test)