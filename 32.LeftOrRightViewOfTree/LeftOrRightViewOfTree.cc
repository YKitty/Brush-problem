#include <iostream>
#include <vector>
#include <stack>

typedef struct Node 
{
  int _val;
  struct Node* _left;
  struct Node* _right;
  Node(int val):_val(val),_left(nullptr),_right(nullptr)
  {}
}Node;

Node* InCreateTree(int array[], int len, int& index)
{
  if ((array == NULL) || (len <= 0))
  {
    return nullptr;
  }

  if (array[index] == -1)
  {
    return nullptr;
  }

  if (index == len)
  {
    return nullptr;
  }

  Node* root = new Node(array[index]);
  index++;
  root->_left = InCreateTree(array, len, index); 
  index++;
  root->_right = InCreateTree(array, len, index);

  return root;
}

void InShowTree(Node* root)
{
  if (root == nullptr)
  {
    return ;
  }

  std::cout << root->_val << " ";
  InShowTree(root->_left);
  InShowTree(root->_right);
}

void LeftView(Node* root, std::vector<int>& v, int level)
{
  if (root == nullptr)
  {
    return ;
  }

  //如果当前结点层数大于结点个数，说明该层还没有结点入队列，将该节点入队
  if (level > v.size())
  {
    v.push_back(root->_val);
  }

  LeftView(root->_left, v, level + 1);
  LeftView(root->_right, v, level + 1);
}

void RightView(Node* root, std::vector<int>& v, int level)
{
  if (root == nullptr)
  {
    return ;
  }

  if (level > v.size())
  {
    v.push_back(root->_val);
  }

  RightView(root->_right, v, level + 1);
  RightView(root->_left, v, level + 1);
}

int main()
{
  int array[] = {2,1,-1,-1,3,4,-1,-1,5,-1,-1};
  int len = sizeof(array) / sizeof(array[0]);
  int index = 0;
  Node* root = InCreateTree(array, len, index);
  InShowTree(root);
  std::cout << std::endl;
  std::vector<int> v_left;
  std::vector<int> v_right;
  LeftView(root, v_left, 1);
  std::cout << "Left View:" << std::endl;
  for (auto e : v_left)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  RightView(root, v_right, 1);
  std::cout << "Right View:" << std::endl;
  for (auto e : v_right)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  return 0;
}
