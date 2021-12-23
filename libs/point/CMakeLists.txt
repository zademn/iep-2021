# Add library
add_library(point STATIC include/point.hpp src/point.cpp)
target_include_directories(point PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# target_include_directories(point PRIVATE
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/point}>
#  $<INSTALL_INTERFACE:include/point>)

# target_include_directories(point PUBLIC
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include}>
#  $<INSTALL_INTERFACE:include>)

