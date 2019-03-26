#include <iostream>

typedef struct Node 
{
  int _val;
  struct Node* _next;
  Node(int val):_val(val),_next(NULL)
  {}

}Node;

Node* Create(int array[], int len)
{
  if ((array == NULL) || (len <= 0))
  {
    return NULL;
  }

  Node* head = NULL;
  Node* tail = NULL;
  for (int i = 0; i < len; i++)
  {
    Node* tmp = new Node(array[i]);
    if (head == NULL)
    {
      head = tmp;
      tail = head;
    }
    else 
    {
      tail->_next = tmp;
      tail = tmp;
    }
  }

  return head;
}

void PrintList(const Node* head)
{
  if (head == NULL)
  {
    return ;
  }
  
  Node* cur = const_cast<Node*>(head);
  while (cur)
  {
    std::cout << cur->_val << " ";
    cur = cur->_next;
  }

  std::cout << std::endl;
}

Node* MergeOrderList_R(Node* head1,Node* head2)
{
  if (head1 == NULL) 
  {
    return head2;
  }
  else if (head2 == NULL)
  {
    return head1;
  }

  Node* merge = NULL;
  if (head1->_val < head2->_val)
  {
    merge = head1;
    merge->_next = MergeOrderList_R(head1->_next, head2);
  }
  else 
  {
    merge = head2;
    merge->_next = MergeOrderList_R(head1, head2->_next);
  }
  
  return merge;
}

int main()
{
  int array1[] = {1,3,5,6,8};
  int array2[] = {2,4,5,7,9};
  Node* head1 = Create(array1, 5);
  PrintList(head1);
  Node* head2 = Create(array2, 5);
  PrintList(head2);
  Node* merge = MergeOrderList_R(head1, head2);
  PrintList(merge);
  return 0;
}
