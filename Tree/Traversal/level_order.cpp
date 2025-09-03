#include<iostream>
#include<queue>
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
void levelOrder(Node* root)
{
    queue<Node*>q;

    if(root==nullptr)
    {
        return;
    }
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        //process current node
        cout<<temp->data<<" ";

        //search on left
        if(temp->left!=nullptr)
        {
            q.push(temp->left);
        }
        //search on right
        if(temp->right!=nullptr)
        {
            q.push(temp->right);
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

    levelOrder(root);
}
