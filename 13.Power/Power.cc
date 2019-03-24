#include <iostream>

bool equal(double num, double benchmark)
{
  if ((num - benchmark > -0.0000001) && (num - benchmark < 0.0000001))
  {
    return true;
  }
  return false;
}

double PowerSubFunction(double base, int abs_exponent)
{
  double result = 1;
  for (auto i = 0; i < abs_exponent; i++)
  {
    result *= base;
  }

  return result;
}

double Power(double base, int exponent)
{
  if (equal(base, 0.0) || exponent == 0)
  {
    return 1;
  }
  int abs_exponent = exponent > 0 ? exponent : -exponent;
  double result = PowerSubFunction(base, abs_exponent);
  if (exponent < 0)
  {
    result = 1 / result;
  }

  return result;
}

int main()
{
  while (1)
  {
    double base = 0;
    int exponent = 0;
    std::cout << "base:";
    std::cin >> base;
    std::cout << "exponent:";
    std::cin >> exponent;
    std::cout << "result:" << Power(base, exponent) << std::endl;;
  }
  return 0;
}
