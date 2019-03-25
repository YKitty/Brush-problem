#include <iostream>
#include <stdlib.h>

int Order(int array[], int index1, int index2)
{
  int result = array[index1];
  for (int i = index1 + 1; i <= index2; i++)
  {
    if (result > array[i])
    {
      result = array[i];
    }
  }

  return result;
}

int GetRotateArrayMinNum(int array[], const int len)
{
  if (array == NULL || len <= 0)
  {
    std::cerr << "INvaild parameters" << std::endl;
    exit(1);
  }

  int index1 = 0;
  int index2 = len - 1;
  int index_mid = index1;
  
  while (array[index1] >= array[index2])
  {
    if (index2 - index1 == 1)
    {
      return array[index2];
    }
    
    index_mid = index1 + ((index2 - index1) >> 1);
    
    if (array[index1] == array[index2] == array[index_mid])
    {
      return Order(array, index1, index2);
    }

    if (array[index_mid] >= array[index1])
    {
      index1 = index_mid;
    }
    else 
    {
      index2 = index_mid;
    }
    

  }

  return array[index_mid];
}

int main()
{
  //int array[] = { 3, 4, 5, 1, 2 };
  //int array[] = { 0, 1, 1, 1, 1 };
  int array[] = { 1,2,3,4,5 };
  std::cout << GetRotateArrayMinNum(array, sizeof(array) / sizeof(array[0])) << std::endl;
  return 0;
}
