include(ExternalProject)
cmake_minimum_required(VERSION 2.8)

IF(CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "-ggdb -g3 -std=c++0x -Wall")
ELSE()
    SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall") #Settings for clang
ENDIF()
S:x
T(game_namespace_sources Card.cpp DeckFactory.cpp Shoe.cpp 
    Hand.cpp Bet.cpp Outcome.cpp Table.cpp BlackjackPlayer.cpp BlackjackGame.cpp)
add_subdirectory(Test)

add_library(game_ns ${game_namespace_sources})
