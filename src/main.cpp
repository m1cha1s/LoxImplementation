#include <main.h>

int main()
{

    Lox::Token tok(Lox::TokenType::COMMA, ",", 12);

    std::cout << tok.toString() << "\n";

    return 0;
}