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

Scanner::Scanner(std::string source)
{
    this->source = source;
}

void Scanner::addToken(TokenType type)
{
    std::string text = source.substr(start, current);
    tokens.push_back(Token(type, text, line));
}

void Scanner::scanToken()
{
    char c = advance();
    switch (c)
    {
    case '(':
        addToken(LEFT_PAREN);
        break;
    case ')':
        addToken(RIGHT_PAREN);
        break;
    case '{':
        addToken(LEFT_BRACE);
        break;
    case '}':
        addToken(RIGHT_BRACE);
        break;
    case ',':
        addToken(COMMA);
        break;
    case '.':
        addToken(DOT);
        break;
    case '-':
        addToken(MINUS);
        break;
    case '+':
        addToken(PLUS);
        break;
    case ';':
        addToken(SEMICOLON);
        break;
    case '*':
        addToken(STAR);
        break;
    case '!':
        addToken(match('=') ? BANG_EQUAL : BANG);
        break;
    case '=':
        addToken(match('=') ? EQUAL_EQUAL : EQUAL);
        break;
    case '<':
        addToken(match('=') ? LESS_EQUAL : LESS);
        break;
    case '>':
        addToken(match('=') ? GREATER_EQUAL : GREATER);
        break;
    case '/':
        if (match('/'))
        {
            while (source.at(current) != '\n' && current < source.length())
                advance();
        }
        else
        {
            addToken(SLASH);
        }
        break;
    case ' ':
    case '\r':
    case '\t':
        break;

    case '\n':
        line++;
        break;

    case '"':
        string();
        break;

    default:
        error = "Unexpected character.";
        break;
    }
}

int Scanner::scanTokens()
{
    while (current < source.length())
    {
        start = current;
        scanToken();

        if (error != "")
        {
            return -1;
        }
    }

    tokens.push_back(Token(EOFile, "", line));

    return 0;
}

bool Scanner::match(char expected)
{
    if (current >= source.length())
        return false;
    if (source.at(current) != expected)
        return false;

    current++;
    return true;
}

char Scanner::advance()
{
    return source.at(current++);
}

std::list<Token> Scanner::getTokens()
{
    return tokens;
}

void Scanner::string()
{
}