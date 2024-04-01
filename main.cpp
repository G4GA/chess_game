#include <SFML/Graphics.hpp>
#include <chess_win.hpp>

int main()
{
    ChessWindow g_interface(512, 512, "Chess Game");
    int result;

    result = g_interface.run();

    return result;
}