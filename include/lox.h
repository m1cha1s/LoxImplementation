#pragma once

#include <string>
#include <list>

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
        GREATER_EQUAL,
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

    class Scanner
    {
    private:
        std::string source;
        std::list<Token> tokens;
        std::string error = "";
        int line = 1;
        int start = 0;
        int current = 0;

    public:
        Scanner(std::string source);
        void addToken(TokenType type);
        void scanToken();
        int scanTokens();
        char advance();
        bool match(char expected);
        void string();
        std::list<Token> getTokens();
    };
}