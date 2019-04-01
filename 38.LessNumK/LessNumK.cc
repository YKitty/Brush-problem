#include <iostream>

int partion(int array[], int start, int end)
{
    if (array == nullptr)
    {
        return -1;
    }

    int cur = start;
    int prev = cur - 1;
    while (cur != end)
    {
        if (array[cur] <= array[end] && ++prev != cur)
        {
            std::swap(array[prev], array[cur]);
        }
        cur++;
    }
    std::swap(array[++prev], array[end]);

    return prev;
}

bool LessNumK(int array[], int k, int len)
{
    if (array == nullptr || k <= 0)
    {
        return false;
    }
    
    int left = 0;
    int right = len - 1;
    int index = partion(array, left, right);
    while (index != k - 1)
    {
        //对于右边继续进行排序
        if (index < k - 1)
        {
            index = partion(array, index + 1, right);
        }
        //对于左边继续进行排序
        else 
        {
            index = partion(array, left, index - 1);
        }
    }
    return true;
}

int main()
{
    int array[] = {2, 4, 1, 5, 6};
    int k = 0;
    std::cout << "Please input num:";
    std::cin >> k;
    if (!LessNumK(array, k, sizeof(array) / sizeof(array[0])))
    {
        return -1;
    }
    for (int i = 0; i < k; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
