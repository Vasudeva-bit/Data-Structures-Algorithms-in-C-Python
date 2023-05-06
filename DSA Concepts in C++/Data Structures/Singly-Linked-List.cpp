#include <bits/stdc++.h>
class node
{
public:
  int val;
  node *next;
  node(int data)
  {
    val = data;
    node *next = NULL;
  }
};
void insert_at_tail(node *&head, int val)
{
  node *n = new node(val);
  if (head == NULL)
  {
    head = n;
    return;
  }
  node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = n;
}
// Function to traverse along the elements of linked
void display(node *head)
{
  node *temp = head;
  while (temp != NULL)
  { // point to be noted (different from one that is in insert_at_tail function above this function)
    std::cout << temp->val << "->";
    temp = temp->next;
  }
}
// Function to insert element before head in linked list
void insert_at_head(node *&head, int val)
{
  node *n = new node(val);
  n->next = head;
  head = n;
}
// Function to search linked list(singly)
bool search_list(node *head, int key)
{
  node *temp = head;
  while (temp != NULL)
  {
    if (key == temp->val)
      return true;
    temp = temp->next;
  }
  return false;
}
int main()
{
  node *head = NULL;
  insert_at_tail(head, 1);
  insert_at_tail(head, 2);
  insert_at_tail(head, 3);
  insert_at_head(head, 0);
  std::cout << search_list(head, 25) << std::endl;
  display(head);
}
