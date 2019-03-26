#include <iostream>

int GetLessKNum(int array[], int len, int K)
{
  if (array == NULL || K <= 0)
  {
    return -1;
  }
  
  int count = 0;
  int index = 0;
  int sub = 1;
  for (int i = 0; i < len; i++)
  {
    sub *= array[i];
    while (sub >= K)
    {
      sub /= array[index];
      index++;
    }
    count += i - index + 1;
  }

  return count;
}

int main()
{
  int array[] = {1,2,3,4,5,6};
  int len = sizeof(array) / sizeof(array[0]);
  int K = 0;
  std::cin >> K;
  std::cout << GetLessKNum(array, len, K) << std::endl;
  return 0;
}
