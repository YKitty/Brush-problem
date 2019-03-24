#include <iostream>

bool equal(double num, double benchmark)
{
  if ((num - benchmark > -0.0000001) && (num - benchmark < 0.0000001))
  {
    return true;
  }
  return false;
}

double Power(double base, int exponent)
{
  if (equal(base, 0.0) || exponent == 0)
  {
    return 1;
  }

  if (exponent == 1)
  {
    return base;
  }

  double result = Power(base, exponent >> 1);
  
  //这里就是将次方分解成连个次方相乘得到的
  result *= result;
  //对于这里一直判断是因为，对于exponent除以2的时候都是一个偶数，只有在最开始的时候这个exponent是一个奇数
  if ((exponent & 1) == 1)
  {
    result *= base;
  }

  return result;
}

double PowerParent(double base, int exponent)
{
  if (exponent < 0)
  {
    double result = Power(base, -exponent);
    return 1 / result;
  }

  return Power(base, exponent);
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
    std::cout << "result:" << PowerParent(base, exponent) << std::endl;;
  }
  return 0;
}
