#include <lox.h>

using namespace Lox;

// Token

Token::Token(TokenType type, std::string lexeme, int line, Literal literal)
{
    this->type = type;
    this->lexeme = lexeme;
    this->line = line;
    this->literal = literal;
}

std::string Token::toString()
{
    return std::to_string(type) + " " + lexeme;
}

// Literal

Literal::Literal()
{
    type = NONE;
}

Literal::Literal(std::string value)
{
    type = STR;
    val.str = value;
}

// Scanner

Scanner::Scanner(std::string source)
{
    this->source = source;
}

void Scanner::addToken(TokenType type)
{
    std::string text = source.substr(start, current);
    tokens.push_back(Token(type, text, line));
}

void Scanner::addToken(TokenType type, Literal literal)
{
    std::string text = source.substr(start, current);
    tokens.push_back(Token(type, text, line, literal));
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
            while (peek() != '\n' && !isAtEnd())
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
    while (!isAtEnd())
    {
        start = current;
        scanToken();

        if (error != "")
        {
            return -1;
        }
    }

    tokens.push_back(Token(EOFile, "", line, NULL));

    return 0;
}

bool Scanner::match(char expected)
{
    if (isAtEnd())
        return false;
    if (peek() != expected)
        return false;

    current++;
    return true;
}

bool Scanner::isAtEnd()
{
    return current >= source.length();
}

char Scanner::advance()
{
    return source.at(current++);
}

char Scanner::peek()
{
    if (isAtEnd())
        return '\0';
    return source.at(current);
}

std::vector<Token> Scanner::getTokens()
{
    return tokens;
}

std::string Scanner::getError()
{
    return error;
}

void Scanner::string()
{
    while (peek() != '"' && !isAtEnd())
    {
        if (peek() == '\n')
            line++;
        advance();
    }

    if (isAtEnd())
    {
        error = line + " Unterminated string.";
        return;
    }

    advance();

    Literal val(source.substr(start + 1, current - 1));
    addToken(STRING, val);
}