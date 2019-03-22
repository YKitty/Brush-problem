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

}

Node* CreateSearchTree()
{
  int node_array[] = {};
  int start = 0;
  return PrevCreateTree(node_array, start);
}

int main()
{
  Node* root = CreateSearchTree();
  return 0;
}
