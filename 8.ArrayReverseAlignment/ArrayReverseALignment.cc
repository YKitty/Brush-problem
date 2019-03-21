#include <iostream>
#include <vector>

int GetCount(std::vector<int> v, std::vector<int>& tmp, int left, int right)
{
  if (left == right)
  {
    return 0;
  }
  //mid只是左右之间数据个数的一半
  int mid = (right - left) >> 1;

  int left_num = GetCount(v, tmp, left, left + mid);
  int right_num = GetCount(v, tmp, left + mid + 1, right);

  int l_end = left + mid;
  int r_end = right;
  int end = right;//合并的数组的最后的下标
  int count = 0;
  bool flag = true;
  while (l_end >= left && r_end >= left + mid + 1)
  {
    if (flag)
    {
      v = tmp;
      flag = false;
    }

    if (v[l_end] > v[r_end])
    {
      tmp[end--] = v[l_end--];
      count += r_end - left- mid;
    }
    else 
    {
      tmp[end--] = v[r_end--];
    }
  }

  for (; l_end >= left; l_end--)
  {
    tmp[end--] = v[l_end--];
  }
  for (; r_end >= left + mid + 1; r_end--)
  {
    tmp[end--] = v[r_end--];
  }

  return left_num + right_num + count;
}

int GetReverseAlignmentNum(std::vector<int>& v)
{
  std::vector<int> tmp(v.begin(), v.end());
  
  return GetCount(v, tmp, 0, v.size() - 1);
}

int main()
{
  int array[] = { 7, 6, 8, 5 }; //4
  std::vector<int> v(array, array + sizeof(array) / sizeof(array[0]));
  int num = GetReverseAlignmentNum(v);
  std::cout << num << std::endl;
  return 0;
}
