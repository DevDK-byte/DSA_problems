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
bool isLeaf(Node* root)
{
    return (root!=nullptr) && (root->left==nullptr) && (root->right==nullptr);
}
void addRightBoundary(Node* root, vector<int>& res)
{
    Node* curr = root->right;
    while(curr)
    {
        if(!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if(curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
}
void addLeaf(Node* root, vector<int>& res)
{
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;//used to stop unnecessary recursive calls...
    }
    if(root->right)
    {
        addLeaf(root->right,res);
    }
    if(root->left)
    {
        addLeaf(root->left,res);
    }
}
void addLeftBoundary(Node* root, vector<int>& res)
{
    stack<int>s;
    Node* current = root->left;
    while(current)
    {
        if(!isLeaf(current)) //excluding leaves...
        {
            s.push(current->data);
        }
        if(current->left)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    while(!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
}

vector<int> printClockwiseTree(Node* root)
{
    vector<int>result;
    if(root==nullptr)
        return result;
    result.push_back(root->data);
    addRightBoundary(root, result);
    addLeaf(root,result);
    addLeftBoundary(root,result);
return result;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int>res = printClockwiseTree(root);
    for(auto x: res)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
