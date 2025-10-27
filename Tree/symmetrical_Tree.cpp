#include<iostream>
#include<stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
//time and space complexity at worst case = 0(n)-->
bool symmetricalTree(Node* leftroot, Node* rightroot)
{
    if(leftroot==nullptr || rightroot==nullptr)
        return (leftroot==rightroot);
    if(leftroot->data!=rightroot->data)
        return false;
return symmetricalTree(leftroot->left, rightroot->right) && symmetricalTree(leftroot->right, rightroot->left); //traversing simultaneously left and right subtree
}
bool isSymmetric(Node* root)
{
    return (root==nullptr) || symmetricalTree(root->left, root->right);
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
root->right = new Node(2);
root->left->left = new Node(3);
root->left->right = new Node(4);
root->right->left = new Node(4);
root->right->right = new Node(3);


    if(isSymmetric(root))
    {
        cout<<"Yes";
    }
    else
        cout<<"No";

    return 0;
}
