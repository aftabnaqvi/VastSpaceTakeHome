cmake_minimum_required(VERSION 3.5)

# Set the project name
project(MiningSimulation)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the source files
set(SOURCES
    src/main.cpp
    src/mining_truck.cpp
    src/unload_station.cpp
    src/simulation.cpp
)

# Add the executable
add_executable(MiningSimulation ${SOURCES})
