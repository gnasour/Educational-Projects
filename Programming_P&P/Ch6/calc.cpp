#include "calc.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

Token get_token();
double expression();
double term();
double primary();
vector<Token> tok;

double expression()
{
    double left = term();
    Token t = get_token();
    while (true)
    {
        switch (t.kind)
        {
        case '+':
            left += term();
            t = get_token();
            break;
        case '-':
            left -= term();
            t = get_token();
            break;
        default:
            return left;
        }
    }
}

double term()
{
    double left = primary();
    Token t = get_token();
    while (true)
    {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
            {
                std::cout << "Error: Divide by 0." << std::endl;
                std::exit(-1);
            }
            left /= primary();
            t = get_token();
            break;
        }
        default:
            return left;
        }
    }
}

double primary()
{
    Token t = get_token();
    switch (t.kind)
    {
    case '(':
    {
        double d = expression();
        t = get_token();
        if (t.kind != ')')
        {
            std::cout << "Error: ) expected." << std::endl;
            std::exit(-2);
        }
    }

    case '8':
        return t.value;

    default:
        std::cout << "Error: primary expected." << std::endl;
        std::exit(-3);
    }
}

int main()
{
    try
    {
        while (cin)
        {
            std::cout << "=" << expression() << std::endl;
        }
        catch (exception &e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
        catch (...)
        {
            std::cerr << "exception" << std::endl;
            return 2;
        }
    }

    return 0;
}