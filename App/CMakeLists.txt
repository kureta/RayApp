cmake_minimum_required(VERSION 3.28)
set(NAME "App")

add_executable(${NAME} src/main.cpp src/App.cpp)

target_include_directories(${NAME} PRIVATE include)
target_link_libraries(${NAME} PRIVATE RayApp)

# Apply common target properties
set_common_target_properties(${NAME})

message(STATUS "Project: ${NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
