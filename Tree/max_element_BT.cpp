#include<iostream>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;

    Node(int d, Node* l, Node* r)
    {
        data = d;
        left = l;
        right = r;
    }
    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
int maxElement(Node* root)
{
    queue<Node*>qu;
    Node* temp;
    int maxElement = INT_MIN;

    qu.push(root);
    while(!qu.empty())
    {
        temp = qu.front();
        qu.pop();

        if(maxElement<temp->data)
        {
            maxElement = temp->data;
        }
        if(temp->left)
        {
            qu.push(temp->left);
        }
        if(temp->right)
        {
            qu.push(temp->right);
        }
    }
    return maxElement;
}
int minElement(Node* root)
{
    queue<Node*>qu;
    Node* temp;
    int minElement = INT_MAX;

    qu.push(root);
    while(!qu.empty())
    {
        temp = qu.front();
        qu.pop();

        if(minElement>temp->data)
        {
            minElement = temp->data;
        }
        if(temp->left)
        {
            qu.push(temp->left);
        }
        if(temp->right)
        {
            qu.push(temp->right);
        }
    }
    return minElement;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<minElement(root);
    return 0;
}
