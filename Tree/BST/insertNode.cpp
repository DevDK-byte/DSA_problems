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
//recursive version-->
Node* insertIntoTree(Node* root, int value)
{
    //create a new Node-->
    Node* newNode = new Node(value);
    if(root==nullptr)
    {
        return newNode;
    }
    if(value>root->data)
    {
        root->right = insertIntoTree(root->right,value);
    }
    if(value<root->data)
    {
        root->left = insertIntoTree(root->left, value);
    }
return root;
}
//non-recursive-->
Node* insertion(Node* root, int val)
{
    Node* newNode = new Node(val);
    if(root==nullptr)
        return newNode;
    Node* temp = root;
    Node* parent = NULL;

    while(temp!=nullptr)
    {
        parent = temp;
        if(val<temp->data)
        {
            temp = temp->left;
        }
        else if(val>temp->data)
        {
            temp = temp->right;
        }
        else
            return root;
    }
    if(val<parent->data)
    {
        parent->left = newNode;
    }
    else
        parent->right = newNode;
return root;
}
void printTree(Node* root)
{
    if(root==nullptr)
    {
        return;
    }
    //inorder
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
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

    //root = insertIntoTree(root,9);
    root = insertion(root, 9);
    printTree(root);
}
