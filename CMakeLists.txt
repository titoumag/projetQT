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
        network
        REQUIRED)
#find_package(Qt5 COMPONENTS
#        Core
#        Gui
#        Widgets
#        Network
#        REQUIRED)

add_executable(projet main.cpp Windows.h Windows.cpp Board.h Board.cpp Param.h Param.h Param.cpp reseau/ServeurTcp.cpp reseau/ServeurTcp.h reseau/ClientTcp.h reseau/ClientTcp.cpp reseau/Reseau.h reseau/Reseau.h reseau/Reseau.cpp)
target_link_libraries(projet
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        )

