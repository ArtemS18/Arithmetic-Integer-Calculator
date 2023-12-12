cmake_minimum_required(VERSION 3.27)

set(PROJECT_NAME Arithmetic-Integer-Calculator)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

set(SOURCE Source/Main.cpp Source/Source.cpp)

set(HEADERS 
      Source/Headers.h 
      Source/Tools/Tools.hpp 
      Source/Stack/Stack.hpp 
      Source/CheckLine/CheckLine.hpp
)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})
