#include <iostream>

int GetNum(int n)
{
    if (n <= 0)
    {
        return -1;
    }

    return 1 << (n - 1);
}

int main()
{
    int n;
    while (std::cin >> n)
    {
        int result = GetNum(n);
        std::cout << result << std::endl;
    }
    return 0;
}
