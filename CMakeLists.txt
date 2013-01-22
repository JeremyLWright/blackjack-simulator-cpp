cmake_minimum_required(VERSION 2.6)


SET(CMAKE_CXX_FLAGS "-std=gnu++11 -g3 -ggdb") #Turn on C++11 and advanced debugging support

file(GLOB UNIT_TESTS tests/*.cpp)
set(MAIN_FILE main.cpp)
set(APPLICATION_CODE_FILES  
    Application/Card.cpp 
    Application/DeckFactory.cpp 
    Application/Shoe.cpp 
    Application/Hand.cpp 
    Application/Bet.cpp 
    Application/Odds.cpp 
    Application/Table.cpp 
    Application/BlackjackPlayer.cpp 
    Application/BlackjackGame.cpp)
##############################################################################
###### YOU ARE NOT REQUIRED TO EDIT BELOW THIS LINE               ############
##############################################################################

include_directories(gmock/gtest/include)
add_subdirectory(gmock) #Build all the gtest stuff
include_directories(gmock/include)
include_directories(.)
include_directories(Application)

add_executable(blackjack ${MAIN_FILE})
target_link_libraries(blackjack application_code)

add_library(application_code ${APPLICATION_CODE_FILES})

add_executable(unit-test ${UNIT_TESTS} )
target_link_libraries(unit-test gtest gtest_main rt pthread application_code)

