include(ExternalProject)
cmake_minimum_required(VERSION 2.8)

IF(CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "-ggdb -g3 -std=c++0x -Wall")
ELSE()
    SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall") #Settings for clang
ENDIF()

#Build the Unit Tests
ExternalProject_Add(
    GTest-1.6
    URL http://googletest.googlecode.com/files/gtest-1.6.0.zip  
    URL_MD5 4577b49f2973c90bf9ba69aa8166b786
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(GTest-1.6 SOURCE_DIR)
include_directories(${SOURCE_DIR}/include ../)
ExternalProject_Get_Property(GTest-1.6 BINARY_DIR)
link_directories(${BINARY_DIR})

add_custom_target(test
    COMMAND unit-test
    DEPENDS unit-test)
add_executable(unit-test ${unit-test-sources})
target_link_libraries(unit-test gtest gtest_main pthread game_ns)
