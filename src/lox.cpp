#include <lox.h>

using namespace Lox;

Token::Token(TokenType type, std::string lexeme, int line)
{
    this->type = type;
    this->lexeme = lexeme;
    this->line = line;
}

std::string Token::toString()
{
    return std::to_string(type) + " " + lexeme;
}