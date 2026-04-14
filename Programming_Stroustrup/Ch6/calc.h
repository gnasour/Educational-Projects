#ifndef CALC_H
#define CALC_H

#include <iostream>

struct Token
{
    char kind;
    double value;
};

class Token_Stream
{
public:
    Token_Stream();
    Token get();
    void putback(Token t);

private:
    Token buffer;
    bool full{false};
};

Token_Stream::Token_Stream()
{
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
    case ';':
    case 'q':
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
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
        return Token{'8', val};
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