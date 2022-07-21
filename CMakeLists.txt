cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        58d77fa8070e8cec2dc1ed015d66b454c8d78850	# Release 1.12.1
)
# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

project(PersonBase)
enable_testing()

add_executable(${PROJECT_NAME} main.c Person.c)
add_executable(${PROJECT_NAME}-ut test.cpp Person.c)

target_compile_options(${PROJECT_NAME} PUBLIC -g -O0 -Wall -Wextra -Wconversion -Wpedantic)

target_link_libraries(${PROJECT_NAME}-ut gtest_main)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)

