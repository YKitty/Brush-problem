#include <iostream> 
#include <vector>
#include <stack>

typedef struct Node
{
  int _data;
  struct Node* _next;
  Node(int data = 0):_data(data),_next(NULL)
  {}
}Node;

Node FindFristPublicNode(const Node* head1, const Node* head2)
{
  int len1 = 0;
  int len2 = 0;
  Node* head_frist = const_cast<Node*>(head1);
  Node* head_second = const_cast<Node*>(head2);
  while (head_frist)
  {
    len1++;
    head_frist = head_frist->_next;
  }

  while (head_second)
  {
    len2++;
    head_second = head_second->_next;
  }

  head_frist = const_cast<Node*>(head1);
  head_second = const_cast<Node*>(head2);
  if (len1 > len2)
  {
    int tmp = len1 - len2;
    while (tmp--)
    {
      head_frist = head_frist->_next;
    }
  }
  else 
  {
    int tmp = len2 - len1;
    while (tmp--)
    {
      head_second = head_second->_next;
    }
  }

  while (head_frist != head_second)
  {
    head_frist = head_frist->_next;
    head_second = head_second->_next;
  }

  return *head_frist;
}

//方法一：使用栈，从尾向头开始寻找
//Node FindFristPublicNode(const Node* head1, const Node* head2)
//{
//  std::stack<Node*> s1;
//  std::stack<Node*> s2;
//  Node* head_frist = const_cast<Node*>(head1);
//  Node* head_second = const_cast<Node*>(head2);
//
//  while (head_frist)
//  {
//    s1.push(head_frist);
//    head_frist = head_frist->_next;
//  }
//
//  while (head_second)
//  {
//    s2.push(head_second);
//    head_second = head_second->_next;
//  }
//
//  Node* prev = NULL;
//  while (!s1.empty() && !s2.empty())
//  {
//    if (s1.top() == s2.top())
//    {
//      prev = s1.top();
//      s1.pop();
//      s2.pop();
//    }
//    else 
//    {
//      break;
//    }
//  }
//
//  return *prev;
//}
//
int main()
{
  //没有头结点的链表
  Node* head1 = NULL;
  Node* head2 = NULL;
  Node* tail2 = NULL;
  for (int i = 0; i < 5; i++)
  {
    Node* tmp = new Node(i);
    tmp->_next = head1;
    head1 = tmp; 
    if (i < 3)
    { 
      Node* tmp = new Node(i);
      tmp->_next = head2;
      head2 = tmp;
      if (i == 0)
      {
        tail2 = tmp;
      }
    }
  }

  tail2->_next = head1->_next->_next->_next;

  Node tmp = FindFristPublicNode(head1, head2);
  std::cout << tmp._data << std::endl;
  return 0;
}
