#include <iostream>

long double exp_recur(long double x, int a)
{
  int res = 1;
  if(a == 1)
    {
      return x;
    }

  return res*exp_recur(x, a-1);
}

int main()
{
  long double base;
  int pow;
  
  std::cout << "Enter base: ";
  std::cin >> base;
  std::cout << "Enter power: ";
  std::cin >> pow;

  std::cout << "Result of exponential: " << exp_recur(base, pow) << std::endl;

  return 0;
}
