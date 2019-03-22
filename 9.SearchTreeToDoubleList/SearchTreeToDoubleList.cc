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

void SearchToVector(std::vector<Node*>& v_node, Node* root)
{
  if (root == NULL)
  {
    return ;
  }
  SearchToVector(v_node, root->_left);
  v_node.push_back(root);
  SearchToVector(v_node, root->_right);
}

void VectorToDoubleList(Node* root, std::vector<Node*>& v_node)
{
  root = v_node[0];
  v_node[0]->_right = v_node[1];
  v_node[0]->_left = NULL;
  for (auto i = 1; i < v_node.size() - 1; i++)
  {
    v_node[i]->_right = v_node[i + 1];
    v_node[i]->_left = v_node[i - 1];
  }

  v_node[v_node.size() - 1]->_left = v_node[v_node.size() - 2];
  v_node[v_node.size() - 1]->_right = NULL;
}

int main()
{
  Node* root = CreateSearchTree();
  PrevOrder(root);
  std::cout << "\n*********************\n";

  std::vector<Node*> v_node;
  SearchToVector(v_node, root);
  for (auto i = 0; i < v_node.size(); i++)
  {
    std::cout << v_node[i]->_data;
  }
  std::cout << "\n*********************\n";

  VectorToDoubleList(root, v_node);  
  while (root)
  { 
    std::cout << root->_data;
    root = root->_right;
  }
  std::cout << "\n*********************\n";
  return 0;
}
