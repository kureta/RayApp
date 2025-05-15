# lint_cmake: -readability/wonkycase
cmake_minimum_required(VERSION 3.28)
set(NAME "RayApp")

set(RAYLIB_VERSION 5.5)
set(RAYLIB_BASE_URL https://github.com/raysan5/raylib/archive/refs/tags)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if(NOT raylib_FOUND)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL ${RAYLIB_BASE_URL}/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if(NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_X11 OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_WAYLAND ON CACHE BOOL "" FORCE)
    unset(GLFW_USE_WAYLAND)

    FetchContent_Populate(raylib)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

add_library(${NAME} src/RayApp.cpp)

target_include_directories(${NAME} PUBLIC include)
target_link_libraries(${NAME} PUBLIC raylib)

# Apply common target properties
set_common_target_properties(${NAME})

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Raylib version: ${RAYLIB_VERSION}")
