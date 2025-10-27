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
//check if a node is a leaf or not-->
bool isLeaf(Node* root)
{
    return (root!=nullptr) && (root->left==nullptr) && (root->right==nullptr);
}
void addLeftBoundary(Node* root, vector<int>& res) //passing vector by reference saves time and memory!
{
    Node* curr = root->left;
    while(curr) //go all the way left...
    {
        if(!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if(curr->left)
        {
            curr = curr->left;
        }
        else
            curr = curr->right; //if there's no left node, check for right
    }
}
void addLeaves(Node* root, vector<int>& res)
{
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if(root->left)
    {
        addLeaves(root->left, res);
    }
    if(root->right)
    {
        addLeaves(root->right,res);
    }
}
void addRightBoundary(Node* root, vector<int>& res)//passing vector by reference...
{
    stack<int>result;//taking temporary stack to store in reverse order
    Node* curr = root->right;
    while(curr)//go all the way right...
    {
        if(!isLeaf(curr))
        {
            result.push(curr->data);
        }
        if(curr->right)
        {
            curr = curr->right;
        }
        else
            curr = curr->left;//if right node not found, check for left...
    }
    for(int i=0;i<result.size(); i++)
    {
        res.push_back(result.top());
        result.pop();
    }
}
vector<int> printTree(Node* root) //vector type function returning vector of nodes...
{
    vector<int> res;
    if(root==nullptr)
        return res;
    if(!isLeaf(root))
    {
        res.push_back(root->data);
    }
    addLeftBoundary(root, res);
    addLeaves(root,res);
    addRightBoundary(root,res);
    return res;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int>res = printTree(root);
    for(auto x: res)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
