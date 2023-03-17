cmake_minimum_required(VERSION 3.24)
project(projet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.4.2/mingw_64/lib/cmake")
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(projet main.cpp Windows.h Windows.cpp Board.h Board.cpp Param.h Param.h Param.cpp)
target_link_libraries(projet
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

