cmake_minimum_required(VERSION 2.6)


SET(CMAKE_CXX_FLAGS "-std=gnu++11") #Turn on C++11 Support

set(UNIT_TESTS tests/test1.cpp)
set(MAIN_FILE main.cpp)

##############################################################################
###### YOU ARE NOT REQUIRED TO EDIT BELOW THIS LINE FOR PROJECT 2 ############
##############################################################################

#add_subdirectory(gtest) #Build all the gtest stuff
include_directories(gtest/include)
add_subdirectory(gmock) #Build all the gtest stuff
include_directories(gmock/include)
include_directories(.)

add_executable(blackjack ${MAIN_FILE})

add_executable(unit-test ${UNIT_TESTS})
target_link_libraries(unit-test gtest gtest_main rt pthread )

