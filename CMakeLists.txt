set(CMAKE_AUTOMOC ON)
cmake_minimum_required(VERSION 3.7)
project(JuegoDeLaDavi)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp View/Window.cpp View/Window.h View/Canvas.cpp View/Canvas.h)
add_executable(JuegoDeLaDavi ${SOURCE_FILES})
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
qt5_use_modules( JuegoDeLaDavi Core Widgets Gui )