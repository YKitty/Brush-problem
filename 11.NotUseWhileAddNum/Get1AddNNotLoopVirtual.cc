#include <iostream>

class Basic;
//必须使用指针，这样才可以调用对应的虚函数
//不能使用引用，这是因为，对于引用来说，不能作为数组的元素
Basic* add_array[2];

class Basic 
{
public:
  virtual int add(int num)
  {
    return 0;
  }
};

class Derive : public Basic
{
public:
  virtual int add(int num)
  {
    return num + add_array[!!num]->add(num - 1);
  }
};

int main()
{
  Basic b;
  Derive d;
  add_array[0] = &b;
  add_array[1] = &d;
  int num;
  while (std::cin >> num)
    std::cout << add_array[!!num]->add(num) << std::endl;

  return 0;
}

