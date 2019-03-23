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

bool GetNodeList(Node* root, Node* node, std::vector<Node*>& node_list)
{
  if (root == NULL)
  {
    return false;
  }
  if (root == node)
  {
    //如果找到了结点之后，要将这个结点插入到vector中
    node_list.push_back(root);
    return true;
  }

  node_list.push_back(root);
  bool first_result = GetNodeList(root->_left, node, node_list);
  if (first_result)
  {
    return true;;
  }
  bool second_result = GetNodeList(root->_right, node, node_list);
  if (second_result)
  {
    return true;;
  }
  if (!first_result && !second_result)
  {
    node_list.pop_back();
  }
  return false;
}

Node* GetLatelyCommonNode(Node* root, Node* first, Node* second)
{
  if (root == NULL)
  {
    return NULL;
  }
  
  //如果两个节点中有一个是根节点，那么直接返回根节点就可以了
  if (first == root || second == root)
  {
    return root;
  }

  std::vector<Node*> first_node_list;
  GetNodeList(root, first, first_node_list);
  std::vector<Node*> second_node_list;
  GetNodeList(root, second, second_node_list);
  
  std::cout << "first_node_list size:" << first_node_list.size() << std::endl;
  std::cout << "second_node_list size:" << second_node_list.size() << std::endl;
  if ((first_node_list.size() == 0) || (second_node_list.size() == 0))
  {
    return NULL;
  }

  //这里是对于查找的两个节点没有一个是根节点的查找
  for (auto i = 0; i < first_node_list.size(); i++)
  {
    if (first_node_list[i] != second_node_list[i])
    {
      return first_node_list[i - 1];
    }
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
