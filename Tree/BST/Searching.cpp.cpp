#include<iostream>
#include<stack>
#include<vector>
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

bool searchingNode(Node* root, int target)
{
     Node* current = root;
     while(target!=current->data)
     {
         if(target>current->data)
         {
             current = current->right;
         }
         if(target<current->data)
         {
             current = current->left;
         }
         if(current->data==target)
            {return true;}
        return false;
        return false;
     }
    return false;
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

    int target;
    cin>>target;
    if(searchingNode(root,target))
    {
        cout<<"Found";
    }
    else
        cout<<"not found";
    return 0;
}
