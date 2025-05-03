cmake_minimum_required(VERSION 3.10)
project(smart_pointers)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# 🔽 Create the test executable first
add_executable(unique_ptr_test
  tests/unique_ptr_test.cpp
)

# 🔽 THEN add include directories
target_include_directories(unique_ptr_test PRIVATE src)

# 🔽 Link GoogleTest libraries
target_link_libraries(unique_ptr_test gtest_main)

# 🔽 Enable test discovery
include(GoogleTest)
gtest_discover_tests(unique_ptr_test)
