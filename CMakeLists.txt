cmake_minimum_required(VERSION 3.6)
project(meyersExamples)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ArraySize.h UnivRefOverload.h UnivRefOverload.cpp ArraySize.cpp InsertInMap.h InsertInMap.cpp PoorPigs.h)
add_executable(meyersExamples ${SOURCE_FILES})