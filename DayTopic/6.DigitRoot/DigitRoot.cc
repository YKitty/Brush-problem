#include <iostream>
#include <string>

int GetDigitRoot(int num)
{
    int result = 0;
    while (num > 0)
    {
        result += num % 10;
        num /= 10;
    }
    while (result > 9)
    {
        result = GetDigitRoot(result);
    }

    return result;
}

int main()
{   
    std::string input;
    while (std::cin >> input)
    {
        //记录第一次所有数字加一起的和
        int sum = 0;
        for (int i = 0; i < input.size(); i++)
        {
            sum += input[i] - '0';
        }
        std::cout << GetDigitRoot(sum) << std::endl;
    }
    return 0;
}
