#include <SFML/Graphics.hpp>
#include <string>

#define VERTEX_COUNT 14
#define SQUARE_AMOUNT 32
#define ROW_COUNT 8
#define DIMENSION 512
#define SQUARE_SIDE DIMENSION / 8

/*
    This class will handle everything related to the window configuration
*/
class ChessWindow
{
    public:
        ChessWindow(size_t, size_t, std::string);

        int run();
    private:
    //Private attributes
        sf::RenderWindow window;
        size_t height;
        size_t width;
        sf::VertexArray h_lines;
        sf::VertexArray v_lines;
        sf::RectangleShape dark_squares[SQUARE_AMOUNT];
        sf::RectangleShape light_squares[SQUARE_AMOUNT];
    //Private methods
        int eventLoop();
        void drawShapes();
        void initLines();
        void initSquares();
        size_t getPosition(size_t);
};
