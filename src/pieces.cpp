#include "../include/pieces.hpp"

Piece::Piece ()
{}

Piece::Piece (const std::string& file_name)
{
    loadFile(file_name);
}

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

sf::Vector2f Piece::getPosition() const
{
    return this -> i_sprite.getPosition();
}

void Piece::setPosition(const sf::Vector2f& new_position) {}

void Piece::setPosition(const float&, const float&) {}

void Piece::setSize (const sf::Vector2f&) {}

void Piece::setSize (const float&, const float&) {}

void Piece::setScaleFactor(const float&, const float&) {}

void Piece::setScaleFactor(const sf::Vector2f&) {}

sf::Vector2f Piece::getScaleFactor () const {
    return sf::Vector2f();
}

sf::Vector2f Piece::getSize() const
{
    return sf::Vector2f(this -> i_texture.getSize());
}