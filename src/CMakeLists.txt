
cmake_minimum_required (VERSION 3.5)
project (shapes)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 -pthread ${CMAKE_CXX_FLAGS}")
endif()

find_package(Catch2 REQUIRED)

add_executable(
	tests 
	tests/tester.cpp
	tests/ShapeGroupTest.cpp
	tests/PointTest.cpp
	tests/LineTest.cpp
	tests/CircleTest.cpp
	tests/RectangleTest.cpp
	tests/TriangleTest.cpp
	)

target_link_libraries(tests Catch2::Catch2)

include(Ctest)
include(Catch)

catch_discover_tests(tests)

add_executable(
	shapes 
	Main.cpp
	Image.hpp
	Image.cpp
	Point.hpp
	Point.cpp
	Line.hpp
	Line.cpp
	Circle.hpp
	Circle.cpp
	Triangle.hpp
	Triangle.cpp
	Rectangle.hpp
	Rectangle.cpp
	ShapeGroup.hpp
	ShapeGroup.cpp
	)

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  )

target_link_libraries(shapes ${OPENGL_LIBRARIES} )

