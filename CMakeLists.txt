cmake_minimum_required(VERSION 3.10)

# 3rd party tools
find_package(Qt5 COMPONENTS Core Qml Quick REQUIRED)

# Directory with source code
add_subdirectory(src)
