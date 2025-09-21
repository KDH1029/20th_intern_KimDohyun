cmake_minimum_required(VERSION 3.16)
project(hw1 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 QUIET COMPONENTS Core Gui Widgets Network)
if(Qt6_FOUND)
    set(QT_VERSION_MAJOR 6)
    message(STATUS "Found Qt6: ${Qt6_VERSION}")
else()
    find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network)
    set(QT_VERSION_MAJOR 5)
    message(STATUS "Found Qt5: ${Qt5_VERSION}")
endif()

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
)

set(HEADERS
    include/hw1/mainwindow.h
)

set(UI_FILES
    ui/mainwindow.ui
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt6_wrap_cpp(MOC_SOURCES ${HEADERS})
    qt6_wrap_ui(UIC_SOURCES ${UI_FILES})
else()
    qt5_wrap_cpp(MOC_SOURCES ${HEADERS})
    qt5_wrap_ui(UIC_SOURCES ${UI_FILES})
endif()

add_executable(${PROJECT_NAME} ${SOURCES} ${MOC_SOURCES} ${UIC_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include/hw1 ${CMAKE_CURRENT_BINARY_DIR})

if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network)
endif()