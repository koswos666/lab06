cmake_minimum_required(VERSION 3.14)  

project(lab05)


cmake_policy(SET CMP0135 NEW)

add_subdirectory(banking)

option(ENABLE_COVERAGE "Enable coverage reporting" ON)
if(ENABLE_COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

enable_testing()


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)


add_executable(tests
    banking/Account.cpp
    banking/Account.h
    banking/Transaction.cpp
    banking/Transaction.h
    test/test.cpp
)


target_link_libraries(tests PRIVATE
    banking
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
