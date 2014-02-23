cmake_minimum_required(VERSION 2.8.9)

project(Icecream)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if(APPLE)
        message(STATUS "Using APPLE CMAKE_CXX_FLAGS")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
elseif(UNIX)
        # assume GCC, add C++0x/C++11 stuff
	message(STATUS "Using UNIX CMAKE_CXX_FLAGS")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
elseif(MINGW)
	message(STATUS "Using MINGW CMAKE_CXX_FLAGS")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wall")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG_BUILD=1)
    message(STATUS "This is a debug build")
endif()

add_subdirectory(IcecreamClient)
add_subdirectory(IcecreamServer)
add_subdirectory(VanillaIcecream)
add_subdirectory(JGF)
add_subdirectory(JGFC)
