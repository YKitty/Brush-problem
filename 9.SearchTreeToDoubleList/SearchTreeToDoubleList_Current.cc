#include <iostream>
#include <vector>

typedef struct Node
{
  int _data;
  struct Node* _left;
  struct Node* _right;
  Node(int data = 0):_data(data),_left(NULL),_right(NULL)
  {}
}Node;

Node* PrevCreateTree(int array[], int& start)
{
  if (array[start] == 0)
  {
    return NULL;
  }

  Node* root = new Node();
  root->_data = array[start];
  //对于左子树结点和右子树结点必须每次都要进行下标++操作
  start++;
  root->_left = PrevCreateTree(array, start);
  start++;
  root->_right = PrevCreateTree(array, start);

  return root;
}

Node* CreateSearchTree()
{
  int node_array[] = { 5, 3, 2, 0, 0, 4, 0, 0, 7, 6, 0, 0, 8, 0, 0 };
  int start = 0;
  return PrevCreateTree(node_array, start);
}

void PrevOrder(Node* root)
{
  if (root == NULL)
  {
    return ;
  }

  std::cout << root->_data;
  PrevOrder(root->_left);
  PrevOrder(root->_right);
}

void Convert(Node* root, Node** tail_node)
{
  if (root == NULL)
  {
    return;
  }
  Node* cur_node = root;

  if (cur_node->_left != NULL)
  {
    Convert(cur_node->_left, tail_node);
  }

  //让一个结点的左指针指向前一个节点
  cur_node->_left = *tail_node;
  if (*tail_node != NULL)
  {
    (*tail_node)->_right = cur_node;
  }

  *tail_node = cur_node;

  if (cur_node->_right != NULL)
  {
    Convert(cur_node->_right, tail_node);
  }


}

void SearchTreeToDoubleList(Node** root)
{
  if (root == NULL)
  {
    return ;
  }

  Node* tail_node = NULL;
  Convert(*root, &tail_node);
  
  Node* head_node = tail_node;
  while (head_node != NULL && head_node->_left != NULL)
  {
    head_node = head_node->_left;
  }

  *root = head_node;
}

int main()
{
  Node* root = CreateSearchTree();
  PrevOrder(root);
  std::cout << "\n*********************\n";
  
  SearchTreeToDoubleList(&root);
  while (root)
  {
    std::cout << root->_data << std::endl;
    root = root->_right;
  }
  return 0;
}
