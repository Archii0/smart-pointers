# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(unique_ptr_test unique_ptr_test.cpp)
target_link_libraries(unique_ptr_test gtest_main)

# Add include path
target_include_directories(unique_ptr_test PRIVATE ${CMAKE_SOURCE_DIR})

# Enable test discovery
include(GoogleTest)
gtest_discover_tests(unique_ptr_test)
