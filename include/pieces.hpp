#include <SFML/Graphics.hpp>


/*
An abstract class for pieces
*/
class Piece
{
    public:
        Piece();
        Piece(const std::string&);
        Piece(const Piece&);
        sf::Vector2f getPosition() const;
        void setPosition(const sf::Vector2f&);
        void setPosition(const float&, const float&);
        void loadFile(const std::string&);
        sf::Sprite getStripe() const;
    private:
        sf::Image i_piece;
        sf::Texture i_texture;
        sf::Sprite i_sprite;
        sf::Vector2f position;
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