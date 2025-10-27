#include<iostream>
#include<stack>
#include<math.h>
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
    //base case-->
    if(root==nullptr)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
bool balancedTree(Node* root)//brute force  0(n square)-->
{
    if(root==nullptr)
    {
        return false;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int res = abs(leftHeight-rightHeight);
    if(res>1)
    {
        return false;
    }

    return true;
}
int Balancedtree(Node* root)//optimized-->0(n)
{
    if(root==nullptr)
    {
        return 0;
    }
    int left = Balancedtree(root->left);
    int right = Balancedtree(root->right);
    if(left==-1 || right ==-1) //if left or right not balanced
    {
        return -1;
    }
    if(abs(left-right)>1)
    {
        return -1;
    }
    //if balanced, return height of tree-->
return max(left,right) +1;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->right->right = new Node(6);
    //root->right->left = new Node(7);

    //cout<<height(root);
    if(Balancedtree(root)!=-1)
    {
         cout<<"Balanced";
    }
    else
        cout<<" not balanced";
}

