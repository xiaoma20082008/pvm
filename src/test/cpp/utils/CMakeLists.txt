add_executable(testArrayList testArrayList.cc)
target_link_libraries(testArrayList gtest gmock gtest_main pvm)
add_test(testArrayList testArrayList)