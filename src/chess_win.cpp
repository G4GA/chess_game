#include "../include/chess_win.hpp"

ChessWindow::ChessWindow(size_t height, size_t width, std::string window_title):
    window(sf::VideoMode(height, width), window_title, sf::Style::Titlebar | sf::Style::Close),
    height(height),
    width(width),
    h_lines(sf::Lines, VERTEX_COUNT),
    v_lines(sf::Lines, VERTEX_COUNT)
{
    init_lines();
    init_squares();
}

void ChessWindow::init_squares()
{
    size_t counter = 0;
    for (size_t y = 0;y < ROW_COUNT; y++) {
        for (size_t x = 0;x < ROW_COUNT; x += 2) {
            size_t dark_sqr_pos = (y % 2) == 1 ? getPosition(x) : getPosition(x + 1);
            size_t light_sqr_pos = (y % 2) == 0 ? getPosition(x) : getPosition(x + 1);

            dark_squares[counter].setPosition(sf::Vector2f(dark_sqr_pos, getPosition(y)));
            dark_squares[counter].setFillColor(sf::Color(187, 190, 100));
            dark_squares[counter].setSize(sf::Vector2f(SQUARE_SIDE, SQUARE_SIDE));

            light_squares[counter].setPosition(sf::Vector2f(light_sqr_pos, getPosition(y)));
            light_squares[counter].setFillColor(sf::Color(234, 240, 206));
            light_squares[counter].setSize(sf::Vector2f(SQUARE_SIDE, SQUARE_SIDE));

            counter ++;
        }
    }
}

size_t ChessWindow::getPosition(size_t index)
{
    return index * (DIMENSION / 8);
}

void ChessWindow::init_lines()
{
    size_t line_count = 1;
    for (size_t i = 0;i < VERTEX_COUNT; i += 2) {
        h_lines[i].position = sf::Vector2f(0, getPosition(line_count));
        h_lines[i].color = sf::Color::Black;
        h_lines[i + 1].position = sf::Vector2f(width, getPosition(line_count));
        h_lines[i + 1].color = sf::Color::Black;

        v_lines[i].position = sf::Vector2f(getPosition(line_count), 0);
        v_lines[i].color = sf::Color::Black;
        v_lines[i + 1].position = sf::Vector2f(getPosition(line_count), height);
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
    for (size_t i = 0;i < SQUARE_AMOUNT; i ++) {
        window.draw(dark_squares[i]);
        window.draw(light_squares[i]);
    }
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
        window.clear(sf::Color::White);
        drawShapes();
        window.display();
    }

    return result;
}