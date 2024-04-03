#include <iostream>
#include <pieces.hpp>
#include <UT_format.hpp>
#include <SFML/Graphics.hpp>

class UT_pieces {
    public:
        Piece testPiece;
        void run();
    private:
        void testObj();
        template <typename T>
        bool assertion(const T&, const T&);
        void printResult(bool, const std::string &);
};

void UT_pieces::printResult (bool result, const std::string &message)
{
	std::string result_str = result ? color::output("OK!", color::GREEN):  color::output("FAILED!", color::RED);
	std::cout << "=> Test [" << color::BOLD << message << color::ENDC << "] " << result_str << " \n";
}

template <typename T>
bool UT_pieces::assertion(const T &result, const T &expected_result)
{
    return result == expected_result;
}

void UT_pieces::run()
{
    testObj();
}

void UT_pieces::testObj ()
{
    /*Testing getters and setters*/
    testPiece = Piece("./unit_tests/dark_bishop.png");
    printResult(assertion(sf::Vector2f(60, 60), testPiece.getSize()),
                          "Size Getter");

    testPiece.setPosition(10, 10);
    printResult(assertion(sf::Vector2f(10, 10), testPiece.getPosition()),
                          "Position Getter");

}

int main () {
    UT_pieces unit_test;
    unit_test.run();

    return 0;
}