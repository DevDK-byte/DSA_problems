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
void preorder_iterative(Node* root)
{
    stack<Node*>s;
    s.push(root);

    if(root==nullptr)
        return;
    while(!s.empty())
    {
        Node* curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        //insert right node first as stack is lifo(last one will be left)
        if(curr->right!=nullptr)
        {
            s.push(curr->right);
        }
        //insert left after inserting right to process left first
        if(curr->left!=nullptr)
        {
            s.push(curr->left);
        }
    }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    preorder_iterative(root);
    return 0;
}
