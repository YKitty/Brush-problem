#include <iostream>

int main()
{
    double n, r;
    while (std::cin >> n >> r)
    {
        if(n > (2 * r * 3.14))
        {
            std::cout << "No" << std::endl;
        }
        else 
        {
            std::cout << "Yes" << std::endl;
        }
    }
    return 0;
}
