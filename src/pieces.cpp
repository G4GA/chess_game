#include "../include/pieces.hpp"

Piece::Piece ()
{}

Piece::Piece (const std::string& file_name)
{}

Piece::Piece (const Piece& piece)
{}

bool Piece::loadFile (const std::string& file_name)
{
    bool result;
    result = i_piece.loadFromFile(file_name);

    if (result) {
        result = i_texture.loadFromImage(i_piece);
    }
    sf::RectangleShape foo;

    if (result) {
        i_sprite.setTexture(i_texture);
    }

    return result;
}