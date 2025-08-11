cmake_minimum_required(VERSION 3.10)
project(DataProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(data_processor
    src/DataProcessor.cpp
    src/main.cpp
)

install(TARGETS data_processor DESTINATION bin)
