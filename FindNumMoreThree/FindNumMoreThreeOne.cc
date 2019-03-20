#include <iostream>
#include <vector>

void FindMoreThreeOne(std::vector<int>& result, const std::vector<int>& v)
{
  int m , n;
  int m_count = 0, n_count = 0;
  for (auto e : v)
  {
    if ((m == e) || (m_count == 0))
    {
      m = e;
      m_count++;
    }
    else if ((n == e) || (n_count == 0))
    {
      n = e;
      n_count++;
    }
    else 
    {
      m_count--;
      n_count--;
    }
  }
  result.push_back(m);
  result.push_back(n);
}

int main()
{
  int array_num[] = { 1, 2, 3, 2, 3, 2, 3 };
  std::vector<int> v(array_num, array_num + sizeof(array_num) / sizeof(array_num[0]));
  for (auto e : v)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  std::vector<int> result;
  FindMoreThreeOne(result, v);

  for (auto e : result)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
