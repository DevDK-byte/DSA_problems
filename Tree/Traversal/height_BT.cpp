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
        data= d;
        left = NULL;
        right = NULL;
    }
};
int height(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    int left_height,right_height;
    //compute depth of each subtree-->
    left_height = height(root->left);
    right_height = height(root->right);

    if(left_height>right_height)
        return left_height+1;
    else
        return right_height+1;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);

    cout<<height(root)<<endl;
}
