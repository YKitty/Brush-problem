#include <iostream>
#include <unistd.h>
#include <stdlib.h>

typedef struct Node
{
  int _data;
  struct Node* _left;
  struct Node* _right;
  Node(int data):_data(data),_left(NULL),_right(NULL)
  {
  }
}Node;

void CreateTree(Node** root, int prev_array[], int prev_len, int in_array[], int in_len)
{
  if (prev_len == 0 || in_len == 0)
  {
    return ;
  }
  
  //记录根节点
  int prev_data = prev_array[0];
  *root = new Node(prev_array[0]);

  //找出在中序中的位置，将其分成两个部分
  int in_pos = 0;
  int i  = 0;
  for (i = 0; i < in_len; i++)
  {
    if (prev_data == in_array[i])
    {
      in_pos = i;
      break;
    }
  }

  if (i == in_len)
  {
    std::cerr << "data error..." << std::endl;
    exit(1);
  }

  //说明有左子树
  if (i > 0)
  {
    int left_len = i;
    CreateTree(&(*root)->_left, prev_array + 1, left_len, in_array, left_len);
  }

  //说明有右子树
  if (in_len - i - 1 > 0)
  {
    int right_len = in_len - i - 1;
    int len = prev_len - right_len;
    CreateTree(&(*root)->_right, prev_array + len, right_len, in_array + len, right_len);
  }

}

void InPrint(Node* root)
{
  if (root == NULL)
  {
    return ;
  }

  std::cout << root->_data << std::endl;
  InPrint(root->_left);
  InPrint(root->_right);
}

int main()
{
  int prev_array[] = { 2, 1, 4, 5, 3, 6 };
  int in_array[] = { 4, 1, 5, 2, 6, 3 };
  int prev_len = sizeof(prev_array) / sizeof(prev_array[0]);
  int in_len = sizeof(in_array) / sizeof(in_array[0]);
  Node* root = NULL;
  CreateTree(&root, prev_array, prev_len, in_array, in_len);
  InPrint(root);
  return 0;
}
