cmake_minimum_required(VERSION 3.6)
project(cppchallenges)

set(CMAKE_CXX_STANDARD 14)
set(BUILD_SHARED_LIBS OFF)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif ()

add_subdirectory(libs/googletest)
include_directories(libs/googletest/googletest/include)

set(SOURCE_FILES
        async/AsyncLogger.h /
        async/AsyncLogger.cpp /

        async/tests/AsyncLoggerTest.cpp /

        effectivecpp/ArraySize.h
        effectivecpp/UnivRefOverload.h /

        effectivecpp/tests/UnivRefOverloadTest.cpp /
        effectivecpp/tests/ArraySizeTest.cpp /

        ostd/Vector.h /
        ostd/UniquePtr.h /
        ostd/SharedPtr.h /
        ostd/IsBaseOf.h /
        ostd/IsSame.h /
        ostd/Distance.h /

        ostd/tests/VectorTest.cpp /
        ostd/tests/UniquePtrTest.cpp /
        ostd/tests/SharedPtrTest.cpp /
        ostd/tests/IsBaseOfTest.cpp /
        ostd/tests/IsSameTest.cpp /
        ostd/tests/DistanceTest.cpp /)

add_executable(cppchallenges ${SOURCE_FILES})
target_link_libraries(cppchallenges gtest gtest_main)