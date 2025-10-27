#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

int inorderSuccessor(Node* root, int value)
{
    Node* successor = 0;
    while(root!=nullptr)
    {
        if(root->data<=value)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor->data;
}
int inorderPredecessor(Node* root,int value)
{
    Node* predecessor = nullptr;
    while(root!=nullptr)
    {
        if(value<=root->data)
        {
            root = root->left;
        }
        else
        {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor->data;
}
int main()
{
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->right = new Node(14);
    root->right->left = new Node(10);

    //cout<<inorderSuccessor(root,10);
    cout<<inorderPredecessor(root,5);
}
