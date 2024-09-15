cmake_minimum_required(VERSION 3.27)
project(App)

add_executable(${PROJECT_NAME} src/main.cpp src/App.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE RayApp)

# Apply common target properties
set_common_target_properties(${PROJECT_NAME})

message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
