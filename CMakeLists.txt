cmake_minimum_required(VERSION 2.8)

project( TLGame )

file( GLOB SOURCES "./src/Game/*.cpp"
	  	  "./src/headers/*.hpp"
	  	  "./src/headers/*.h" )

set( CMAKE_CXX_FLAGS "-g -std=c++0x -lIrrlicht -lGL -lGLU -lXrandr -lXext -lX11" )

add_executable( run ${SOURCES} )

