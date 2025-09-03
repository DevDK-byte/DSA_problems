#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right =NULL;
    }
};

Node* postorder_recursive(Node* root)
{
    if(root==nullptr)
        return root;

    postorder_recursive(root->left);
    postorder_recursive(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout<<"postorder traversal = ";
    postorder_recursive(root);
    return 0;
}
