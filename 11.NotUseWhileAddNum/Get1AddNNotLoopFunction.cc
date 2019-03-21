#include <stdio.h>

typedef int (*fun) (int num);

int EndAdd(int num)
{
  return 0;
}

int GetAddNum(int num)
{
  static fun f[2] = {EndAdd, GetAddNum};
  return num + f[!!num](num - 1);
}

int main()
{
  int num;
  while (scanf("%d", &num))
    printf("%d\n", GetAddNum(num));
  return 0;
}
