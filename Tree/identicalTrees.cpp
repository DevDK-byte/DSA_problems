#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

struct Node;
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
bool identicalTrees(Node* root1, Node* root2)
{
    if(root1==nullptr || root2==nullptr)
        return (root1==root2);
    return (root1->data == root2->data) && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right,root2->right);
}
