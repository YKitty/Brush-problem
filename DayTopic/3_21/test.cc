#include <stdio.h>
#include <iostream>


int main()
{
  const int i = 10;
  int* p = (int*)&i;
  *p = 20;
  std::cout << "i:" << i << "\n" << "*p:" << *p << std::endl;
  //int i = 3;
  //printf("%d %d", ++i, ++i);
  return 0;
}
