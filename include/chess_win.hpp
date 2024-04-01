#include <SFML/Graphics.hpp>
#include <string>

/*
    This class will handle everything related to the window configuration
*/
class ChessWindow {
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
    //Private methods
        int eventLoop();
        void drawShapes();
};
