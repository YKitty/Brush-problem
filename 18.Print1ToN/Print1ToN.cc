#include <iostream>
#include <string.h>


void PrintNum(char* arr)
{
  int i = 0;
  while (arr[i] == '0')
  {
    i++;
  }

  std::cout << arr + i << std::endl;
}

void Print1ToNSubFuction(char* arr, int len, int index)
{
  if ((len - 1) == index)
  {
    PrintNum(arr);//已经到最后一位数字了，直接打印
  }
  
  for (int i = 0; i < 10; i++)//次高位在划分为0-9
  {
    arr[index + 1] = i + '0';
    Print1ToNSubFuction(arr, len, index + 1);//一直递归到最低位
  }
}

void Print1ToN(int n)
{
  char* arr = new char[n + 1];
  memset(arr, 0, n + 1);
  arr[n] = '\0';

  for (int i = 0 ; i < 10; i++)
  {
    arr[0] = i + '0';//第一位数字依次设置为0到9
    Print1ToNSubFuction(arr, n, 0);
  }
}

int main()
{
  int n;
  std::cin >> n;
  Print1ToN(n);
  return 0;
}
