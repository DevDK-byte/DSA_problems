#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
int main()
{
    Node* root = new Node(1);//creating the root of tree
    root->left = new Node(2);//left subtree
    root->right = new Node(3);//right subtree
    root->left->left = new Node(4);//expanding left tree

    return 0;
}
