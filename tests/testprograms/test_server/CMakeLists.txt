# (Using cmake instead of qmake for this test program 
# since it has no Qt content)

cmake_minimum_required (VERSION 2.8)

set (CMAKE_CXX_FLAGS "-g -std=c++0x -Werror")

find_package (vsomeip 2.10.21 REQUIRED)
find_package( Boost 1.55 COMPONENTS system thread log REQUIRED )

include_directories (
   ${Boost_INCLUDE_DIR}
   ${VSOMEIP_INCLUDE_DIRS}
   )

add_executable(server server.cpp)
add_executable(client client.cpp)
target_link_libraries(server vsomeip ${Boost_LIBRARIES})
target_link_libraries(client vsomeip ${Boost_LIBRARIES})

