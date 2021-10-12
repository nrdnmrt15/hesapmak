cmake_minimum_required(VERSION 3.20)
project(hesapmak)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(hesapmak main.cpp hesap.cpp hesap.h hesap.ui)
target_link_libraries(hesapmak
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

