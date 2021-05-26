# CMakeList.txt : CMake project for Rapid Json Lec 1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
find_package(RapidJSON CONFIG REQUIRED)
# Add source to this project's executable.
add_executable (CMakeTarget "Rapid Json Lec 1.cpp" "Rapid Json Lec 1.h")
target_include_directories(CMakeTarget PRIVATE ${RAPIDJSON_INCLUDE_DIRS})

# TODO: Add tests and install targets if needed.
