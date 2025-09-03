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
//using two stack-->
void postorder_iterative(Node* root)
{
    stack<Node*>s1;
    stack<Node*>s2;
    if(root==nullptr)
        return;
    s1.push(root);//push root each time
    while(!s1.empty())
    {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left!=nullptr)
        {
            s1.push(temp->left);
        }
        if(temp->right!=nullptr)
        {
            s1.push(temp->right);
        }
    }
    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";//S2 TOP HAS NODE , WHOSE DATA WE NEED
        s2.pop();
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
    root->right->right->right = new Node(7);

    postorder_iterative(root);
}
