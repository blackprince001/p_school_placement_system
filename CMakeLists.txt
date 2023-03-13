cmake_minimum_required(VERSION 3.13.4)

project(SchoolPlacementSystem)

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(SchoolSystem)
add_subdirectory(PlacementSystem)

add_executable(main main.cpp)

target_link_libraries(schoolsystem)