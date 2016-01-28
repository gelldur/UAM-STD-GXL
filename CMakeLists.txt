CMAKE_MINIMUM_REQUIRED(VERSION 3.3)
PROJECT(STD)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(EXECUTABLE_OUTPUT_PATH "bin/")

INCLUDE_DIRECTORIES(pugixml/src)

SET(HEADER_FILES
		pugixml/src/pugiconfig.hpp
		pugixml/src/pugixml.hpp)

SET(SOURCE_FILES
		src/main.cpp
		pugixml/src/pugixml.cpp
		src/Graph.cpp src/Graph.h
		)


ADD_EXECUTABLE(STD ${SOURCE_FILES} ${HEADER_FILES})