#pragma once
#include <SFML/Graphics.hpp>


/*
An abstract class for pieces
*/
class Piece
{
    public:
        Piece();
        Piece(const std::string&);
        Piece(const std::string&, const sf::Vector2f&);
        Piece(const Piece&);
        sf::Vector2f getPosition() const;
        void setPosition(const sf::Vector2f&);
        void setPosition(const float&, const float&);
        void setSize (const float&, const float&);
        void setScaleFactor(const float&, const float&);
        void setScaleFactor(const sf::Vector2f&);
        sf::Vector2f getScaleFactor () const;
        sf::Vector2f getSize() const;
        sf::Sprite getStripe() const;
        bool loadFile(const std::string&);
    private:
        sf::Image i_piece;
        sf::Texture i_texture;
        sf::Sprite i_sprite;
        sf::Vector2f position;
        sf::Vector2f size;
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