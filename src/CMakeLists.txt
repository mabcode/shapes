
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
	Shape.hpp
	Shape.cpp
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


# All code below this line is for the OPENGL

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# Compile external dependencies 
add_subdirectory (external)

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)

include_directories(
	external/AntTweakBar-1.16/include/
	external/glfw-3.1.2/include/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	external/assimp-3.0.1270/include/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

target_link_libraries(shapes
	${ALL_LIBS}
)

target_link_libraries(tests
	${ALL_LIBS}
)
