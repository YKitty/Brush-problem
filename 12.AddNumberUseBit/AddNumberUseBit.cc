#include <iostream>

int main()
{
  int num1, num2;
  while (1)
  {
    std::cin >> num1;
    std::cin >> num2;
    int dept1 = 0;
    int dept2 = 0;
    do 
    {
      dept1 = num1 ^ num2;
      dept2 = (num1 & num2) << 1;
      num1 = dept1;
      num2 = dept2;
      //是要判断还有没有进位
    }while(num2 != 0);
    std::cout << num1 << std::endl;
  }
  return 0;
}
