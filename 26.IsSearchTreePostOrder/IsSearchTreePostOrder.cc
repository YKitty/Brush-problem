#include <iostream>

bool IsSearchTreePostOrder(int array[], int len)
{
  if ((array == NULL) || (len <= 0))
  {
    return false;
  }

  int end = array[len - 1];
  int left = 0;//计算下来也是记录的左子树的长度
  for (; left < len - 1; left++)
  {
    if (array[left] > end)
    {
      break;
    }
  }
  
  int right = left;//用来计算最后右子树，最后一个元素的下一个元素的下标
  for (;right < len - 1; right++)
  {
    //如果右子树中有小于end的值，直接错误
    if (array[right] < end)
    {
      return false;
    }
  }

  bool result_left = true;
  if (left > 0)//有左子树
  {
    result_left = IsSearchTreePostOrder(array, left);
  }

  bool result_right = true;
  //left右子树开始的下标，len - 1最后的下标
  if (left < len - 1)//有右子树,len - 1是数组的最后一个下标
  {
    result_right = IsSearchTreePostOrder(array + left, len - left - 1);
  }

  //如果判断到最后的时候，left == 0，就直接下来    
  //result_left和result_right都是true
  return result_left && result_right;
}

int main()
{
  //int array[] = {1,7,6,9,11,10,8};
  int array[] = { 2 };
  std::cout << IsSearchTreePostOrder(array,sizeof(array)/sizeof(array[0])) << std::endl;
  return 0;
}
