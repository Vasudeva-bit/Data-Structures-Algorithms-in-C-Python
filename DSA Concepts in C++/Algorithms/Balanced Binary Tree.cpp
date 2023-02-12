#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int val;
    node* left = NULL;
    node* right = NULL;
    node(int n) {
        val = n;
    }
};

int height(node* root) {
    if(root == NULL)
    return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return max(leftH, rightH) + 1;
}

bool isBalanced(node* root) {
    if(root == NULL)
    return true;
    if(isBalanced(root->left) == false)
    return false;
    if(isBalanced(root->right) == false) 
    return false;
    int leftH = height(root->left);
    int rightH = height(root->right);
    if(abs(leftH - rightH) <= 1)
    return true;
}

int main() {
    // sample binary tree
    node* root = new node(2);
    node* left = new node(3);
    node* right = new node(4);
    root->left = left;
    root->right = right;
    left = new node(1);
    right = new node(0);
    root->left->left = left;
    root->left->right = right;
    if(isBalanced(root))
    cout<<"The binary tree is Balanced";
    else
    cout<<"Not the Balanced";
}