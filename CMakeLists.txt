set(CMAKE_AUTOMOC ON)
cmake_minimum_required(VERSION 3.7)
project(JuegoDeLaDavi)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp View/Window.cpp View/Window.h View/Canvas.cpp View/Canvas.h Utils/Matrix.cpp Utils/Matrix.h Examples/GosperGliderGun.cpp Examples/GosperGliderGun.h Examples/Example.cpp Examples/Example.h Implementations/CPU/cpu.cpp Implementations/CPU/cpu.h Examples/Replicator.cpp Examples/Replicator.h Examples/Lines.cpp Examples/Lines.h Examples/Waifu.cpp Examples/Waifu.h Implementations/OpenCL/parallelOpenCL.cpp Implementations/OpenCL/parallelOpenCL.h Implementations/implementations.h)

find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})
link_directories(${OpenCL_LIBRARY})

add_executable(JuegoDeLaDavi ${SOURCE_FILES})

target_link_libraries (JuegoDeLaDavi ${OpenCL_LIBRARY})
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
qt5_use_modules( JuegoDeLaDavi Core Widgets Gui )