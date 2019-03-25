#include <iostream>
#include <stdlib.h>
#include <math.h>

static int count(const int& num)
{
  if (num < 0)
  {
    std::cerr << "Prarament error!" << std::endl;
    exit(1);
  }

  int count = 0;
  for (int i = 2; i <= num; i++)
  {
    int sqrt_num = sqrt(i);
    int sum = 0;
    for (int j = 2; j <= sqrt_num; j++)
    {
      if (i % j == 0)
      {
        if (i / j == j)
        {
          sum += j;
        }
        else 
        {
          sum += j + (i / j);
        }
      }
    }
    if (sum + 1 == i)
    {
      std::cout << "Prefect num: " << i << "\n";
      count++;
    }
  }
  return count;
}

int main()
{
  int num = 0;
  std::cout << "Please input num# ";
  while (std::cin >> num)
  {
    std::cout << "Please input num# ";
    std::cout << count(num) << std::endl;
  }
  return 0;
}
