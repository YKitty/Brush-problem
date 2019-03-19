//求两个数组的交集
#include <iostream>
#include <vector>

int main()
{
  int arr1[5] = { 1, 3, 4, 7, 9 };
  int arr2[5] = { 2, 4, 6, 7, 8 };
  std::vector<int> v;
  int len1 = sizeof(arr1) / sizeof(arr1[0]);
  int len2 = sizeof(arr2) / sizeof(arr2[0]);
  for (auto i = 0, j = 0; i < len1 && j < len2;)
  {
    if (arr1[i] == arr2[j])
    {
      v.push_back(arr1[i]);
      i++;
      j++;
    }
    else if (arr1[i] < arr2[j])
    {
      i++;
    }
    else 
    {
      j++;
    }
  }
  
  for (auto e : v)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
