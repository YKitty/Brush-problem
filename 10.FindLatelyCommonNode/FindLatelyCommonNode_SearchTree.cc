#include <iostream>
#include <vector>

typedef struct Node 
{
  int _data;
  struct Node* _left;
  struct Node* _right;
  Node(int data):_data(data),_left(NULL),_right(NULL)
  {}
}Node;

Node* CreateSearchTree_SubFunction(int node_array[], int& index)
{
  if (node_array[index] == 0)
  {
    return NULL;
  }

  Node* root = new Node(node_array[index]);
  index++;
  root->_left = CreateSearchTree_SubFunction(node_array, index);
  index++;
  root->_right = CreateSearchTree_SubFunction(node_array, index);

  return root;
}

Node* CreateSearchTree()
{
  int node_array[] = {5, 3, 2, 0, 0, 4, 0, 0, 7, 6, 0, 0, 8, 0, 0};
  int index = 0;
  return CreateSearchTree_SubFunction(node_array, index);
}

Node* FindNodeData(const Node* root, const int data)
{
  if (root == NULL)
  {
    return NULL;
  }
  
  Node* cur = const_cast<Node*>(root);
  Node* result = NULL;
  while (1)
  {
    if (cur->_data == data)
    {
      result = cur;
      break;
    }
    else if (cur->_data < data)
    {
      result = FindNodeData(cur->_right, data);
      break;
    }
    else 
    {
      result = FindNodeData(cur->_left, data);
      break;
    }

  }

  return result;
}

Node* GetLatelyCommonNode(const Node* root, const Node* first, const Node* second)
{
  if (root == NULL)
  {
    return NULL;
  }

  if (((first->_data > root->_data) && (second->_data < root->_data)) ||\
    ((first->_data < root->_data) && (second->_data > root->_data)) ||\
      (first->_data == root->_data) || (second->_data == root->_data))
  {
    return const_cast<Node*>(root);
  }
  else if ((first->_data < root->_data) && (second->_data < root->_data))
  {
    return GetLatelyCommonNode(root->_left, first, second);
  }
  else 
  {
    return GetLatelyCommonNode(root->_right, first, second);
  }
}

int main()
{
  Node* root = CreateSearchTree();
  int data = 0;
  std::cout << "Please input first Node data:";
  std::cin >> data;
  Node* First = FindNodeData(root, data);
  std::cout << "Please input second Node data:";
  std::cin >> data;
  Node* Second = FindNodeData(root, data);
  Node* common_node = GetLatelyCommonNode(root, First, Second);
  if (common_node == NULL)
  {
    std::cout << "hava node not in SeatchTree!" << std::endl;
  }
  else 
  {
    std::cout << "Find Success!" << std::endl;
    std::cout << "Node Data:" << common_node->_data << std::endl;
  }
  return 0;
}
