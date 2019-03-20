#include <iostream>

class A
{
public:
  void f()
  {
    std::cout << "A" << std::endl;
  }
};

class B : public A
{
public:
  virtual void f()
  {
    std::cout << "B" << std::endl;
  }
};

int main()
{
  B* b = new B();
  b->f();
  b->A::f();
  return 0;
}
