cmake_minimum_required(VERSION 2.6)

IF(CMAKE_COMPILER_IS_GNUCXX)
SET(CMAKE_CXX_FLAGS "-std=gnu++11 -g3 -ggdb") #Turn on C++11 and advanced debugging support
ENDIF()

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

#include_directories(util/gmock/gtest/include)
#add_subdirectory(util/gmock) #Build all the gtest stuff
#include_directories(util/gmock/include)
# Enable ExternalProject CMake module
include(ExternalProject)
# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty)
 
# Add gmock
ExternalProject_Add(
	googlemock
	GIT_REPOSITORY https://github.com/google/googletest.git
	TIMEOUT 30
	#PATCH_COMMAND svn patch ${CMAKE_SOURCE_DIR}/gtest.patch ${CMAKE_BINARY_DIR}/ThirdParty/src/googlemock/gtest
	# Force separate output paths for debug and release builds to allow easy
	# identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
	#CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
	#			-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
	#			-Dgtest_force_shared_crt=ON
	CMAKE_ARGS -Dgtest_force_shared_crt=ON -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
	# Disable install step
	INSTALL_COMMAND ""
	# Wrap download, configure and build steps in a script to log output
	LOG_DOWNLOAD ON
	LOG_CONFIGURE ON
	LOG_BUILD ON)

# Specify include dir for googlemock and googletest
ExternalProject_Get_Property(googlemock source_dir)
include_directories(${source_dir}/googlemock/include)
include_directories(${source_dir}/googletest/include)
include_directories(src)

add_executable(blackjack ${MAIN_FILE})
target_link_libraries(blackjack application_code)


add_library(application_code ${APPLICATION_CODE_FILES})

add_executable(unit-test ${UNIT_TESTS} )
add_dependencies(unit-test googlemock)

if( MSVC )
ExternalProject_Get_Property(googlemock binary_dir)
target_link_libraries(unit-test 
		${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${CMAKE_FIND_LIBRARY_SUFFIXES} 
		${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
		application_code)
else()
target_link_libraries(unit-test gtest gtest_main gmock rt pthread application_code)
endif()

enable_testing()
add_test(unit-test unit-test)


