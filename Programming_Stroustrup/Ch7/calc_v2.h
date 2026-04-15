#ifndef CALC_H
#define CALC_H

#include <iostream>

const char number = '8';
const char quit = 'q';
const char print = ';';
const std::string prompt = "> ";
const std::string result = "= ";

struct Token
{
    char kind;
    double value;
};

struct Variable
{
    std::string name;
    double value;
};

class Token_Stream
{
public:
    Token_Stream();
    Token get();
    void putback(Token t);
    void ignore_until(char c);

private:
    Token buffer;
    bool full{false};
};

Token_Stream::Token_Stream()
{
}

void Token_Stream::ignore_until(char c)
{
    full = false;

    if (c != buffer.kind)
    {
        char ch = 0;
        while (std::cin >> ch && ch != c)
        {
            ; // Remove all characters from the stdin buffer until matching char is read
        }
    }
}

void Token_Stream::putback(Token t)
{
    if (full)
    {
        std::cout << "Error: Token Stream buffer is full" << std::endl;
        std::exit(-3);
    }
    buffer = t;
    full = true;
}

Token Token_Stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;

    switch (ch)
    {
    case print:
    case quit:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return Token{ch};
        break;
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        std::cin.putback(ch);
        double val;
        std::cin >> val;
        return Token{number, val};
        break;
    }
    default:
        std::cerr << "Error: Bad Token" << std::endl;
        std::exit(-4);
        break;
    }

    // Should never happen
    return Token{' '};
}

#endif