# 1. Find the GTest package on the system
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 2. Define the test executable
# This creates a program called 'run_unit_tests'
add_executable(run_unit_tests test_fcw.cpp)

# 3. Link the necessary libraries
# We link:
# - fcw_lib: This is your ADAS logic from the src folder
# - GTest::GTest: The core Google Test library
# - GTest::Main: This provides a 'main()' function so you don't have to write one for tests
target_link_libraries(run_unit_tests 
    fcw_lib 
    GTest::GTest 
    GTest::Main
)

# 4. Register the test with CTest
# This allows you to run all tests by simply typing 'ctest' in the build folder
add_test(NAME FCW_Logic_Tests COMMAND run_unit_tests)