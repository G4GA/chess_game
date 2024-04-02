#include <SFML/Graphics.hpp>


/*
An abstract class for pieces
*/
class Piece
{
    public:
        Piece ();
    private:
        sf::Image i_piece;
};

class Pawn : Piece
{};

class Bishop : Piece
{};

class Knight : Piece
{};

class Rook : Piece
{};

class King : Piece
{};

class Queen : Piece
{};