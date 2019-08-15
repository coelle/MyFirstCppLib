cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_VERSION "1.0")
project(firstCppLib VERSION ${PROJECT_VERSION})

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(src ${Boost_INCLUDE_DIR})

enable_testing()

#I like to keep test files in a separate source directory called test
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} test/*.cpp)

#Run through each source
foreach (testSrc ${TEST_SRCS})
    #Extract the filename without an extension (NAME_WE)
    get_filename_component(testName ${testSrc} NAME_WE)

    #Add compile target
    add_executable(${testName} ${testSrc})

    #link to Boost libraries AND your targets and dependencies
    target_link_libraries(${testName} ${Boost_LIBRARIES} firstCppLib)

    #I like to move testing binaries into a testBin directory
    set_target_properties(${testName} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin)

    #Finally add it to test execution -
    #Notice the WORKING_DIRECTORY and COMMAND
    add_test(NAME ${testName}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin
            COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/testBin/${testName})
endforeach (testSrc)

add_library(firstCppLib src/library.cpp src/library.h)

# Note: a target should be already defined using 'add_executable' or 'add_library'
target_link_libraries(firstCppLib ${Boost_LIBRARIES})

# This will name your output .so files "libsomething.1.0" which is pretty useful
set_target_properties(firstCppLib
        PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION}
        )
