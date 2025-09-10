cmake_minimum_required(VERSION 3.10)
project(algo_trader)

set(CMAKE_CXX_STANDARD 17)

# Add include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/base/include
    ${CMAKE_CURRENT_SOURCE_DIR}/strategy/include
    ${CMAKE_CURRENT_SOURCE_DIR}/util/include
    /opt/homebrew/include
)

# Collect all source files
file(GLOB BASE_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/base/src/*.cpp
)
file(GLOB STRATEGY_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/strategy/src/*.cpp
)
file(GLOB UTIL_SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/util/src/*.cpp
)

# Main program
add_executable(algo_trader
    main.cpp
    ${BASE_SRC}
    ${STRATEGY_SRC}
    ${UTIL_SRC}
)

# If you use nlohmann/json (vendored header)
target_include_directories(algo_trader PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/util)
