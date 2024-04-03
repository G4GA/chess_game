#include <iostream>
#include <pieces.hpp>
#include <UT_format.hpp>
#include <SFML/Graphics.hpp>

class UT_pieces {
    public:
        Piece testPiece;
        void run();
    private:
};

void UT_pieces::run() {
    testPiece = Piece();
}

int main () {
    UT_pieces unit_test;
    unit_test.run();

    return 0;
}