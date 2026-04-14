#include "calc.h"
#include <iostream>
#include <vector>
#include <cstdlib>

Token_Stream ts;
double expression();
double term();
double primary();
std::vector<Token> tok;

double expression()
{
    double left = term();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
            break;
        }
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
            {
                std::cerr << "Error: Divide by 0." << std::endl;
                std::exit(-1);
            }
            left /= primary();
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
            break;
        }
    }
}

double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
        {
            std::cerr << "Error: ) expected." << std::endl;
            std::exit(-2);
        }
    }
    case '8':
        return t.value;
        break;
    default:
        std::cout << "Error: primary expected." << std::endl;
        std::exit(-3);
        break;
    }
}

int main()
{
    try
    {
        double val = 0;

        while (std::cin)
        {
            Token t = ts.get();

            if (t.kind == 'q')
            {
                break;
            }
            if (t.kind == ';')
            {
                std::cout << "= " << val << std::endl;
            }
            else
            {
                ts.putback(t);
                val = expression();
            }
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "exception" << std::endl;
        return 2;
    }

    return 0;
}