//求两个数组的交集
#include <iostream>
#include <vector>

//方法二：对于a数组中的每个数字到b数组中，采用二分查找去看有没有
//时间复杂度：O(NlogM)
bool BindarySearch(int arr[], const int& len, const int& aim_num)
{
  int left = 0;
  int right = len - 1;
  //对于二分查找必须要有等于这是因为，有可能在left==right的时候，还没有进行判断
  while (left <= right)
  {
    int mid = left + ((right - left)>>1);
    if (arr[mid] == aim_num)
    {
      return true;
    }
    else if (arr[mid] < aim_num)
    {
      left = mid + 1;
    }
    else 
    {
      right = mid - 1;
    }
  }

  return false;
}

int main()
{
  int arr1[5] = { 1, 3, 4, 7, 9 };
  int arr2[5] = { 2, 4, 6, 7, 8 };
  std::vector<int> v;
  int len = sizeof(arr1) / sizeof(arr1[0]);
  for (auto i = 0; i < len; i++)
  {
    if (BindarySearch(arr2, sizeof(arr2) / sizeof(arr2[0]), arr1[i]))
    {
      v.push_back(arr1[i]);
    }
  }

  for (auto e : v)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}

//方法一：使用两个指针来进行遍历查看
//时间复杂度：O(M+N)
//int main()
//{
//  int arr1[5] = { 1, 3, 4, 7, 9 };
//  int arr2[5] = { 2, 4, 6, 7, 8 };
//  std::vector<int> v;
//  int len1 = sizeof(arr1) / sizeof(arr1[0]);
//  int len2 = sizeof(arr2) / sizeof(arr2[0]);
//  for (auto i = 0, j = 0; i < len1 && j < len2;)
//  {
//    if (arr1[i] == arr2[j])
//    {
//      v.push_back(arr1[i]);
//      i++;
//      j++;
//    }
//    else if (arr1[i] < arr2[j])
//    {
//      i++;
//    }
//    else 
//    {
//      j++;
//    }
//  }
//  
//  for (auto e : v)
//  {
//    std::cout << e << " ";
//  }
//  std::cout << std::endl;
//  return 0;
//}
