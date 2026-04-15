#include "calc_v2.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

Token_Stream ts;
double expression();
double term();
double primary();
void clean_up_mess();

std::vector<Token> tok;
std::vector<Variable> var_table;

double get_value(std::string s)
{

    for (const Variable &v : var_table)
    {
        if (v.name == s)
        {
            return v.value;
        }
    }

    std::cout << "get: undefined variable -- " << s << std::endl;
    throw std::exception();
}

void set_value(std::string s, double d)
{
    for (Variable &v : var_table)
    {
        if (v.name == s)
        {
            v.value = d;
            return;
        }
    }

    std::cout << "set: undefined variable -- " << s << std::endl;
    throw std::exception();
}

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
        case '%':
        {
            double d = primary();
            if (d == 0)
            {
                std::cout << "Error: Divide by 0" << std::endl;
                std::exit(5);
            }
            left = fmod(left, d);
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

        return d;
        break;
    }
    case number:
        return t.value;
        break;
    case '+':
        return +primary();
        break;
    case '-':
        return -primary();
        break;
    default:
        std::cout << "Error: primary expected." << std::endl;
        std::exit(-3);
        break;
    }
}

void calculate()
{
    while (std::cin)
    {
        try
        {
            std::cout << prompt; // Standard prompt
            Token t = ts.get();  // Grab token for evaluation

            while (t.kind == print)
            {
                t = ts.get();
            }
            if (t.kind == quit)
            {
                std::cout << "User exit" << std::endl;
                std::exit(0);
            }

            ts.putback(t);
            std::cout << result << expression() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            clean_up_mess();
        }
    }
}

void clean_up_mess()
{
    ts.ignore_until(print);
}

int main()
{
    try
    {
        calculate();
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