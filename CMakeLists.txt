cmake_minimum_required(VERSION 2.6)

IF(CMAKE_COMPILER_IS_GNUCXX)
SET(CMAKE_CXX_FLAGS "-std=gnu++11 -g3 -ggdb") #Turn on C++11 and advanced debugging support
ENDIF()

if( MSVC ) # VS2012 doesn't support correctly the tuples yet
     	    add_definitions( /D _VARIADIC_MAX=10 )
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
if( MSVC )
target_link_libraries(unit-test gtest gtest_main application_code)
else()
target_link_libraries(unit-test gtest gtest_main rt pthread application_code)
endif()


