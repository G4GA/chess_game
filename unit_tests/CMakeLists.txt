add_executable(UT_pieces UT_pieces.cpp
                         ../src/pieces.cpp
)

function (link RUN_NAME)
    link_directories(${RUN_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../SFML/build/lib)

    include_directories(${RUN_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../SFML/include)
    include_directories(${RUN_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
    include_directories(${RUN_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

    target_link_libraries(${RUN_NAME}
                          PRIVATE
                          sfml-audio
                          sfml-graphics
                          sfml-network
                          sfml-system
                          sfml-window )

    set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
endfunction()

link(UT_pieces)