#include <iostream>

//方法一：使用右移运算符
void FindNumberOf1(int num)
{
  int count = 0;
  while (num)
  {
    if ((num & 1))
    {
      count++;
    }
    num >>= 1;
  }
  std::cout << count << std::endl;
}

//方法二：使用num&num-1
//void FindNumberOf1(int num)
//{
//  int count = 0;
//  while (num)
//  {
//    num &= num - 1;
//    count++;
//  }
//
//  std::cout << count << std::endl;
//}

int main()
{
  int num;
  while (std::cin >> num)
  {
    FindNumberOf1(num);
  }
  return 0;
}
