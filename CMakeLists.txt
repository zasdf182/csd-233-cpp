# Dependency: OpenCV
find_package(OpenCV REQUIRED)

# Dependency: GoogleTest
enable_testing()
include(GoogleTest)
include(FetchContent)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/24a9e940d481f992ba852599c78bb2217362847b.zip
)
FetchContent_MakeAvailable(googletest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set default build directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib/)

                                                            ##################
                                                            #### MODULE 1 ####
                                                            ##################

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/1_assgShowPicture/main.cpp)
# target_link_libraries(currCppFile ${OpenCV_LIBS})

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/1_projWhoAmI/main.cpp)
# target_link_libraries(currCppFile ${OpenCV_LIBS})

                                                            ##################
                                                            #### MODULE 2 ####
                                                            ##################

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/2_assgPtrPractice1/problem2.cpp)

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/2_assgReqRead/main.cpp)

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/2_assgYourTurn/main.cpp)

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/2_projPointerMishMash/main.cpp)

                                                            ##################
                                                            #### MODULE 3 ####
                                                            ##################

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/3_assgCmdLineArgs/main.cpp)

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/3_assgshapesPart1/main.cpp)
# target_link_libraries(currCppFile ${OpenCV_LIBS})

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/3_projShapesPart2/main.cpp)
# target_link_libraries(currCppFile ${OpenCV_LIBS})

                                                            ##################
                                                            #### MODULE 4 ####
                                                            ##################

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/4_assgItemClass/main.cpp)

                                                            ##################
                                                            #### MODULE 5 ####
                                                            ##################

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/5_assgYourTurn/main.cpp)

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/5_projOptimalClassTime/main.cpp)

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/5c_projSearchTree/main.cpp)

cmake_minimum_required(VERSION 3.31.3) 
project(currCppTests)
add_executable(currCppTests src/5c_projSearchTreeTests/strTests.cpp)
target_include_directories(currCppTests PRIVATE src/5c_projSearchTree/)
target_link_libraries(currCppTests gtest gtest_main)
gtest_discover_tests(currCppTests)

                                                            ##################
                                                            #### MODULE 6 ####
                                                            ##################

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/6_assgYourTurn/main.cpp)

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/6_assgWarmUp/ShapeFunStart.cpp)
# target_link_libraries(currCppFile ${OpenCV_LIBS})

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/6_assgDerivedClasses/main.cpp)

                                                            #################
                                                            #### MIDTERM ####
                                                            #################

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/6_midterm/cayson_midterm_q1.cpp)

# cmake_minimum_required(VERSION 3.31.3)
# project(currCppFile)
# add_executable(currCppFile src/6_midterm/cayson_midterm_q2.cpp)
