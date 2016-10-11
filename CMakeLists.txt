cmake_minimum_required(VERSION 2.8)

project( TLGame )

file( GLOB SOURCES "./src/Game/*.cpp"
	  	   "./src/Game/*.hpp"
	  	   "./src/*.cpp"
		   "./src/*.hpp")
		  
set( CMAKE_CXX_FLAGS "-std=c++0x" )

add_executable( run ${SOURCES} )

TARGET_LINK_LIBRARIES(run "/usr/lib/libIrrlicht.so.1.8.4")
