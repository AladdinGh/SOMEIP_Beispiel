cmake_minimum_required (VERSION 2.8)

set (CMAKE_CXX_FLAGS "-g -std=c++11")

find_package (vsomeip 2.6.0 REQUIRED)
find_package( Boost 1.55 COMPONENTS system thread log REQUIRED )

include_directories (
    ${Boost_INCLUDE_DIR}
    ${VSOMEIP_INCLUDE_DIRS}
)

add_executable(server ./server.cpp ./server.h)
add_executable(vehicle ./vehicle.h ./vehicle.cpp)
target_link_libraries(server vsomeip ${Boost_LIBRARIES})
target_link_libraries(vehicle vsomeip ${Boost_LIBRARIES})
