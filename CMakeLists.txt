cmake_minimum_required(VERSION 3.15)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}
    /opt/sfml2/include
)

add_executable(Minesweeper
    canvas.h
    classes.h
    game.cpp
    Menu.h
    savefile.h
    setmine.h
    main
)
target_link_libraries(Minesweeper
    sfml-system
    sfml-window
    sfml-graphics
)

file(COPY images DESTINATION ${CMAKE_BINARY_DIR})
file(COPY time DESTINATION ${CMAKE_BINARY_DIR})

if(WIN32)
    get_filename_component(SFML_DLL_DIR "${SFML_DIR}/../bin" ABSOLUTE)
    
    foreach(SFML_MODULE IN ITEMS system window graphics)
        add_custom_command(TARGET Minesweeper POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
                "${SFML_DLL_DIR}/sfml-${SFML_MODULE}-${SFML_VERSION_MAJOR}.dll"
                $<TARGET_FILE_DIR:Minesweeper>
        )
    endforeach()
endif()