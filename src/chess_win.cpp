#include "../include/chess_win.hpp"

#define VERTEX_COUNT 14

ChessWindow::ChessWindow(size_t height, size_t width, std::string window_title):
    window(sf::VideoMode(height, width), window_title),
    height(height),
    width(width),
    h_lines(sf::Lines, VERTEX_COUNT),
    v_lines(sf::Lines, VERTEX_COUNT)
{
    int line_count = 1;
    for (size_t i = 0;i < VERTEX_COUNT; i += 2) {
        h_lines[i].position = sf::Vector2f(0, line_count * (height / 8));
        h_lines[i].color = sf::Color::Black;

        h_lines[i + 1].position = sf::Vector2f(width, line_count * (height / 8));
        h_lines[i + 1].color = sf::Color::Black;

        v_lines[i].position = sf::Vector2f(line_count * (width / 8), 0);
        v_lines[i].color = sf::Color::Black;
        v_lines[i + 1].position = sf::Vector2f(line_count * (width / 8), height);
        v_lines[i + 1].color = sf::Color::Black;

        line_count ++;
    }
}

int ChessWindow::run()
{
    int result;
    result = eventLoop();

    return result;
}

void ChessWindow::drawShapes()
{
    window.draw(h_lines);
    window.draw(v_lines);
}

int ChessWindow::eventLoop()
{
    int result = 0;
    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(247, 218, 173));
        drawShapes();
        window.display();
    }

    return result;
}