#include <iostream>
#include <string>

std::string RemoveCharDuplicate(std::string s)
{
  if (s.size() <= 1)
  {
    return s;
  }
  std::string s_tmp;
  int bit_set[32] = { 0 };
  for (auto i = 0; i < s.size(); i++)
  {
    int offset = s[i] / 8;
    int index = s[i] % 8;
    if (bit_set[offset] & (1 << index))
    {
      s[i] = '\0';
    }
    //表示没有,将这一位设置为1
    bit_set[offset] |= (1 << index); 
  }

  //将s中的字符都拿出来
  for (auto e : s)
  {
    if (e != '\0')
    {
      s_tmp += e; 
    }
  }
  return s_tmp;
}

int main()
{
  std::string s;
  std::cin >> s;
  std::cout << s << std::endl;
  s = RemoveCharDuplicate(s);
  std::cout << s << std::endl;
  return 0;
}
