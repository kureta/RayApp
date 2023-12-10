cmake_minimum_required(VERSION 3.27)
project(App)

set(CMAKE_CXX_STANDARD 20)

add_executable(App src/main.cpp src/App.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(App PRIVATE RayApp)