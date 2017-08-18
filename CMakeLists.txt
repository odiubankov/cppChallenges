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

        effectivecpp/ArraySize.h /
        effectivecpp/UnivRefOverload.h /

        ostd/tests/Vector.cpp /
        ostd/Vector.h /
        ostd/UniquePtr.h /
        ostd/SharedPtr.h /
        ostd/IsBaseOf.h /
        ostd/IsSame.h /
        ostd/Distance.h /

        effectivecpp/tests/UnivRefOverload.cpp /
        effectivecpp/tests/ArraySize.cpp /
        ostd/tests/UniquePtr.cpp /
        ostd/tests/SharedPtr.cpp /
        ostd/tests/IsBaseOf.cpp /
        ostd/tests/IsSame.cpp /
        ostd/tests/Distance.cpp /)

add_executable(cppchallenges ${SOURCE_FILES})
target_link_libraries(cppchallenges gtest gtest_main)