cmake_minimum_required(VERSION 3.16)
project(batterymonitor)

set_target_properties(PROPERTIES DEBUG_POSTFIX "${CMAKE_DEBUG_POSTFIX}")

link_directories(${CMAKE_BINARY_DIR}/$<CONFIG>/lib)

set(CMAKE_INCLUDE_CURRENT_DIR "YES")
set(CMAKE_AUTOMOC "YES")
set(CMAKE_AUTOUIC "YES")

find_package(Qt6 COMPONENTS WebSockets REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Gui REQUIRED)
find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS HttpServer REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)

qt_standard_project_setup()

qt_add_executable(batterymonitor
    main.cpp
    app.h
    app.cpp

    batteryindicator.h
    batteryindicator.cpp
    systemtrayicon.h
    systemtrayicon.cpp

    resources.qrc
)


target_link_libraries(batterymonitor PRIVATE Qt6::WebSockets
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
    Qt6::Network)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug mode")
    target_link_libraries(batterymonitor PRIVATE tagsystemd)
else()
    message("Release mode")
    target_link_libraries(batterymonitor PRIVATE tagsystem)
endif()

target_include_directories(batterymonitor INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


set_target_properties(batterymonitor
    PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/bin
)


