include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Quick_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
add_definitions(${Qt5Core_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})

qt5_add_resources(QT_RESOURCES qml.qrc resources.qrc)

set(CMAKE_AUTOMOC ON)

set(PROJECT "franca-ara")

project(${PROJECT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11 -fstrict-aliasing -pedantic-errors -pedantic")

set(HEADERS "imageprovider.h" "imagesource.h")

set(SOURCES main.cpp imageprovider.cpp imagesource.cpp)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

add_executable(${PROJECT} ${HEADERS} ${SOURCES} ${QT_RESOURCES})

target_link_libraries(${PROJECT} Qt5::Core Qt5::Qml Qt5::Quick)
