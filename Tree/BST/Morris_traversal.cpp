#include<iostream>
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

vector<int> inorderMorris(Node* root)
{
    vector<int>result;
    Node* current = root;
    while(current!=NULL)
    {
        if(current->left==nullptr)
        {
            result.push_back(current->data);
            current = current->right;
        }
        else
        {
            Node* prev = current->left;
            while(prev->right && prev->right != current)
            {
                prev = prev->right;
            }
            if(prev->right==nullptr)
            {
                prev->right = current; //connect the thread and then visit left subtree
                current = current->left;
            }
            else
            {
                prev->right = nullptr; // remove the thread and then visit right subtree
                result.push_back(current->data);
                current = current->right;
            }
        }
    }
    return result;
}

vector<int> preorderMorris(Node* root)
{
    //for preorder...after connecting thread..push curr value into vector and go left!(all rest same)
    vector<int>storage;
    Node* current = root;
    while(current!=nullptr)
    {
        if(current->left==nullptr)
        {
            storage.push_back(current->data);
            current = current->right;
        }
        else
        {
            Node* prev = current->left;
            while(prev->right && prev->right!=current)//no thread connected
            {
                prev = prev->right;
            }
            if(prev->right==nullptr)
            {
                storage.push_back(current->data);
                prev->right = current;
                current = current->left;
            }
            else
            {
                prev->right = nullptr; //disconnect thread and move to right
                current = current->right;
            }
        }
    }
    return storage;
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

    vector<int>res = preorderMorris(root);
    for(auto x: res)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
