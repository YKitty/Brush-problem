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

Node* MergeOrderList(const Node* head1, const Node* head2)
{
  if (head1 == NULL)
  {
    return const_cast<Node*>(head2);
  }
  else if (head2 == NULL)
  {
    return const_cast<Node*>(head1);
  }

  Node* merge = NULL;
  Node* phead1 = const_cast<Node*>(head1);
  Node* phead2 = const_cast<Node*>(head2);
  if (phead1->_val < phead2->_val)
  {
    merge = phead1;
    phead1 = phead1->_next;
  }
  else 
  {
    merge = phead2;
    phead2 = phead2->_next;
  }
  Node* head = merge;
  while (phead1 && phead2)
  {
    if (phead1->_val < phead2->_val)
    {
      merge->_next = phead1;
      phead1 = phead1->_next;
      merge = merge->_next;
    }
    else 
    {
      merge->_next = phead2;
      phead2 = phead2->_next;
      merge = merge->_next;
    }
  }

  if (phead1)
  {
    merge->_next = phead1;
  }
  else 
  {
    merge->_next = phead2;
  }

  return head;
}

int main()
{
  int array1[] = {1,3,5,6,8};
  int array2[] = {2,4,5,7,9};
  Node* head1 = Create(array1, 5);
  PrintList(head1);
  Node* head2 = Create(array2, 5);
  PrintList(head2);
  //Node* merge = MergeOrderList(head1, head2);
  Node* merge = MergeOrderList(NULL, head2);
  PrintList(merge);
  return 0;
}
