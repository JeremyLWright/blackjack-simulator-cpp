cmake_minimum_required(VERSION 2.6)

IF(CMAKE_COMPILER_IS_GNUCXX)
SET(CMAKE_CXX_FLAGS "-std=gnu++11 -g3 -ggdb") #Turn on C++11 and advanced debugging support
ENDIF()

if( MSVC ) 
     	    add_definitions( /D _VARIADIC_MAX=10 ) # VS2012 doesn't support correctly the tuples yet
			 MESSAGE ( STATUS "Setting MSVC MT switches")
   foreach (flag_var
             CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
             CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
      if (NOT BUILD_SHARED_LIBS AND NOT gtest_force_shared_crt)
        # When Google Test is built as a shared library, it should also use
        # shared runtime libraries.  Otherwise, it may end up with multiple
        # copies of runtime library data in different modules, resulting in
        # hard-to-find crashes. When it is built as a static library, it is
        # preferable to use CRT as static libraries, as we don't have to rely
        # on CRT DLLs being available. CMake always defaults to using shared
        # CRT libraries, so we override that default here.
        string(REPLACE "/MD" "-MT" ${flag_var} "${${flag_var}}")
      endif()

      # We prefer more strict warning checking for building Google Test.
      # Replaces /W3 with /W4 in defaults.
      string(REPLACE "/W3" "-W4" ${flag_var} "${${flag_var}}")
    endforeach()
			
 endif()

file(GLOB ASSIGN_01_TESTS testsuite/01/*.cpp)
file(GLOB ASSIGN_02_TESTS testsuite/02/*.cpp)
file(GLOB ASSIGN_03_TESTS testsuite/03/*.cpp)
file(GLOB ASSIGN_04_TESTS testsuite/04/*.cpp)
file(GLOB ASSIGN_05_TESTS testsuite/05/*.cpp)
file(GLOB ASSIGN_06_TESTS testsuite/06/*.cpp)
file(GLOB ASSIGN_07_TESTS testsuite/07/*.cpp)

set(UNIT_TESTS ${ASSIGN_01_TESTS} ${ASSIGN_02_TESTS} ${ASSIGN_03_TESTS}
    ${ASSIGN_04_TESTS} ${ASSIGN_05_TESTS} ${ASSIGN_06_TESTS} ${ASSIGN_07_TESTS})

set(MAIN_FILE src/main.cpp)
set(APPLICATION_CODE_FILES  
    src/Card.cpp 
    src/DeckFactory.cpp 
    src/Shoe.cpp 
    src/Hand.cpp 
    src/Bet.cpp 
    src/Odds.cpp 
    src/Table.cpp 
    src/BlackjackPlayer.cpp 
    src/BettingStragety.cpp
    src/PlayerView.cpp
    src/BlackjackGame.cpp)
##############################################################################
###### YOU ARE NOT REQUIRED TO EDIT BELOW THIS LINE               ############
##############################################################################

include_directories(util/gmock/gtest/include)
add_subdirectory(util/gmock) #Build all the gtest stuff
include_directories(util/gmock/include)
include_directories(src)

add_executable(blackjack ${MAIN_FILE})
target_link_libraries(blackjack application_code)

add_library(application_code ${APPLICATION_CODE_FILES})

add_executable(unit-test ${UNIT_TESTS} )
if( MSVC )
target_link_libraries(unit-test gtest gtest_main gmock application_code)
else()
target_link_libraries(unit-test gtest gtest_main gmock rt pthread application_code)
endif()


