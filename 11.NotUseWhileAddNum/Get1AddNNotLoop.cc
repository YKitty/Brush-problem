#include <iostream>

class Add
{
public:
  Add()
  {
    _num++;
    _sum += _num;
  }
  static int GetNum()
  {
    return _sum;
  }
private:
  static int _num;
  static int _sum;
};

int Add::_num = 0;
int Add::_sum = 0;


int main()
{
  Add a[100];
  std::cout << Add::GetNum() << std::endl;
  return 0;
}
