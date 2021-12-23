# Put cmake minimum version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LIB_DIR libs)



# set the project name
project(hw1 VERSION 0.1)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
# add the executable. 
#add_executable(${PROJECT_NAME} src/main.cpp)

# Cmake discrourages this:
# You can do a recursive search for all cpp files in a dir
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

# add library
add_subdirectory(${LIB_DIR}/point)
# link library
target_link_libraries(${PROJECT_NAME} point Threads::Threads)

# Add subdirectory for the header files
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

