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
int ceil(Node* root, int value)
{
    int ceil = -1; //put answer here
    while(root)
    {
         if(root->data==value)//edge case-->
         {
             ceil = root->data;
             return ceil;
         }
         if(value>root->data)
         {
             root = root->right;
         }
         else//if value is lesser....
         {
             ceil = root->data;
             root = root->left;
         }
    }
    return ceil;
}
int floor(Node* root, int key)
{
    int f = -1;
    while(root)
    {
        if(root->data==key)
        {
            f = root->data;
            return f;
        }
        if(key<root->data)
        {
            root = root->left;
        }
        else{
            f = root->data;
            root = root->right;
        }
    }
    return f;
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

    //cout<<ceil(root,12)<<endl;
    cout<<floor(root,6)<<endl;
}
