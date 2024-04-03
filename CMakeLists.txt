cmake_minimum_required(VERSION 3.27)

if (UNIX)
    set(CMAKE_CXX_COMPILER g++-13)
    set(CMAKE_C_COMPILER gcc)
endif ()

project(chess_game)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SFML/include/ ${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/SFML/build/lib)

add_executable(${PROJECT_NAME}
                    main.cpp
                    src/chess_win.cpp
                    src/pieces.cpp)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    sfml-audio
    sfml-graphics
    sfml-network
    sfml-system
    sfml-window
)
