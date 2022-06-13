#pragma once

#include <string>
#include <vector>

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

    enum ValueType
    {
        NONE,
        STR
    };

    union Value
    {
        std::string str;
    };

    class Literal
    {
    public:
        Value val;
        ValueType type;

        ~Literal();
        Literal();
        Literal(std::string value);
    };

    class Token
    {
    public:
        TokenType type;
        std::string lexeme;
        int line;
        Literal literal;

        ~Token();
        Token(TokenType type, std::string lexeme, int line, Literal literal);
        std::string toString();
    };

    class Scanner
    {
    private:
        std::string source;
        std::vector<Token> tokens;
        std::string error = "";
        int line = 1;
        int start = 0;
        int current = 0;

        void addToken(TokenType type);
        void addToken(TokenType type, Literal literal);
        void scanToken();

        char advance();
        char peek();

        bool isAtEnd();
        bool match(char expected);
        void string();

    public:
        Scanner(std::string source);

        int scanTokens();

        std::vector<Token> getTokens();
        std::string getError();
    };
}