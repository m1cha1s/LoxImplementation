#pragma once

#include <string>

namespace Lox
{
    enum TokenType
    {
        LEFT_PAREN,
        RIGHT_PAREN,
        LEFT_BRACE,
        RIGHT_BRACE,
        COMMA,
        DOT,
        MINUS,
        PLUS,
        SEMICOLON,
        SLASH,
        STAR,

        BANG,
        BANG_EQUAL,
        EQUAL,
        EQUAL_EQUAL,
        GREATER,
        GRATER_EQUAL,
        LESS,
        LESS_EQUAL,

        IDENTIFIERM,
        STRING,
        NUMBER,

        AND,
        CLASS,
        ELSE,
        FALSE,
        FUN,
        FOR,
        IF,
        NIL,
        OR,
        PRINT,
        RETURN,
        SUPER,
        THIS,
        TRUE,
        VAR,
        WHILE,

        EOFile
    };

    class Token
    {
    public:
        TokenType type;
        std::string lexeme;
        int line;

        Token(TokenType type, std::string lexeme, int line);
        std::string toString();
    };
}