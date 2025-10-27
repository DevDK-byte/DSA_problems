#include<iostream>
#include<stack>
#include<queue>
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
bool searchElement(Node* root,int element) //iterative version--> time and space both 0(n)
{
    queue<Node*>qu;
    Node* temp;
    qu.push(root);

    while(!qu.empty())
    {
        temp = qu.front();
        qu.pop();

        if(temp->data==element)
        {
            return true;
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
    return false;
}
bool searchEl(Node* root,int element)//recursive version-->
{
    bool temp;
    //base case--> if tree empty, data not found;
    if(root==nullptr)
        return false;
    else
    {
        if(root->data==element)
        {
            return true;
        }
        else
        {
            temp = searchEl(root->left,element);
            if(temp)
            {
                return true;
            }
            else
            {
                return searchEl(root->right,element);
            }
        }
    }
    return false;
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

    int el;
    cin>>el;

    if(searchEl(root,el))
    {
        cout<<"found"<<endl;
    }
    else
        cout<<"Not found"<<endl;
    return 0;
}
