// code dynamic array in cpp with additions and //deletions from the tail allowed, also manage space
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
  int data;
  node *left;
  node *right;
  node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

void insert_left(node *&root, int val)
{
  node *temp = root;
  node *n = new node(val);
  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  temp->left = n;
}

void insert_right(node *&root, int val)
{
  node *temp = root;
  node *n = new node(val);
  while (temp->right != NULL)
  {
    temp = temp->right;
  }
  temp->right = n;
}

void display(node *root)
{
  node *temp = root;
  cout << temp->data << endl;
  while (temp->left != NULL)
  {
    cout << temp->left->data << endl;
    temp = temp->left;
  }
  if (temp->left != NULL)
    cout << temp->left->data << endl;
  // if(temp->right != NULL)
  //   cout<<temp->right->data;
}

int main()
{
  node *root = new node(1);
  insert_left(root, 2);
  insert_left(root, 3);
  // insert_right(root, 4);
  // insert_right(root, 5);
  display(root);
}
