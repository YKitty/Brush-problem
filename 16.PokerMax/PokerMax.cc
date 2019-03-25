#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

void GetPoker(const std::string& input)
{
  if (input.size() == 0)
  {
    std::cerr << "input error!" << std::endl;
    return ;
  }
  if (input.find("joker JOKER") != std::string::npos)
  {
    std::cout << "joker JOKER" << std::endl;
    return;
  }
  std::string poker1 = input.substr(0, input.find('-'));
  std::string poker2 = input.substr(input.find('-') + 1);
  int count1 = count(poker1.begin(), poker1.end(), ' ');
  int count2 = count(poker2.begin(), poker2.end(), ' ');
  std::string first_poker1 = poker1.substr(0, poker1.find(' '));
  std::string first_poker2 = poker2.substr(0, poker2.find(' '));
  std::string compare = "345678910JQKA2jokerJOKER";
  if (count1 == count2)
  {
    if (compare.find(first_poker1) > compare.find(first_poker2))
    {
      std::cout << poker1 << std::endl;
    }
    else if (compare.find(first_poker1) < compare.find(first_poker2))
    {
      std::cout << poker2 << std::endl;
    }
    else 
    {
      std::cout << "equal double poker!" << std::endl;
    }
  }
  else 
  {
    if (count1 == 3)
    {
      std::cout << poker1 << std::endl;
    }
    else if (count2 == 3)
    {
      std::cout << poker2 << std::endl;
    }
    else 
    {
      std::cout << "error input!" << std::endl;
    }
  }
}

int main()
{
  std::string input;
  while (getline(std::cin, input))
  {
    GetPoker(input);
    fflush(0);
  }

  return 0;
}
