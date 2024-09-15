cmake_minimum_required(VERSION 3.28)
project(
  RayAppExample
  VERSION 0.1
  DESCRIPTION "Quick template for using raylib."
  LANGUAGES CXX
)

# Set global C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable exporting compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Define a function to apply common settings to all targets
function(set_common_target_properties target)
  target_compile_options(${target} PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Werror>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  )
  target_compile_options(${target} PRIVATE
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:Release>:-O3>
    $<$<CONFIG:RelWithDebInfo>:-O2 -g>
    $<$<CONFIG:MinSizeRel>:-Os>
  )
endfunction()

# Include dependencies and subdirectories
include(FetchContent)
add_subdirectory(RayApp)
add_subdirectory(App)
