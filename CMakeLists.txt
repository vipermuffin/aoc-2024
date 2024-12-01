#cmake 3.1 required for set_source_files_properties
cmake_minimum_required (VERSION 3.1)

#define variables and project name
set (YEAR_PREFIX 20xx)
set (NAMESPACE "Aoc${YEAR_PREFIX}")
set (PROJECT_NAME "${YEAR_PREFIX}_AoC_VM")
set (CMAKE_CXX_STANDARD 11)
set (MASTER_PROJECT TRUE)
project (${PROJECT_NAME})
# Add days
add_subdirectory("${PROJECT_SOURCE_DIR}/lib/gtest" ./gtest)
enable_testing()
add_subdirectory("${PROJECT_SOURCE_DIR}/Day*/")
add_subdirectory("${PROJECT_SOURCE_DIR}/Day01/")
