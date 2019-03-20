#include <iostream>
#include <vector>

int FindLessMethod(int n, const std::vector<int>& left, const std::vector<int>& right)
{
  int left_sum = 0;
  int left_min = INT8_MAX;
  int right_sum = 0;
  int right_min = INT8_MAX;
  int num = 0;
  for (int i = 0; i < n; i++)
  {
    if (left[i] * right[i] == 0)
    {
      num += left[i] + right[i];
    }
    else 
    {
      left_sum += left[i];
      right_sum += right[i];
      left_min = std::min(left[i], left_min);
      right_min = std::min(right[i], right_min);
    }
  }

  //最后的加1，是为了拿出另外一个数组中的手套
  return num + std::min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> left;
  std::vector<int> right;
  left.reserve(n);
  right.reserve(n);
  for (int i = 0; i < n; i++)
  {
    int tmp = 0;
    std::cin >> tmp;
    left[i] = tmp;
  }

  for (int i = 0; i < n; i++)
  {
    int tmp = 0;
    std::cin >> tmp;
    right[i] = tmp;
  }

  int result = FindLessMethod(n, left, right);
  std::cout << result << std::endl;
  return 0;
}
