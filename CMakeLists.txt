cmake_minimum_required(VERSION 3.0.0)
project(bowling_kata)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(FetchContent)
FetchContent_Declare(DocTest 
GIT_REPOSITORY "https://github.com/onqtam/doctest"         
GIT_TAG "v2.4.11")
FetchContent_MakeAvailable(DocTest)

add_subdirectory(libs)
add_subdirectory(app)