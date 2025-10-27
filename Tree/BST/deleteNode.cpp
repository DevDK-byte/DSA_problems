#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

Node* findLastRight(Node* root) {
    if(root->right == nullptr)
        return root;
    return findLastRight(root->right);
}

Node* connector(Node* root) {
    if(root->left == nullptr)
        return root->right;
    if(root->right == nullptr)
        return root->left;

    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node* deleteNode(Node* root, int val) {
    if(root == nullptr)
        return nullptr;

    if(root->data == val)
        return connector(root);

    Node* temp = root;
    while(temp != nullptr) {
        if(val > temp->data) {
            if(temp->right != nullptr && temp->right->data == val) {
                temp->right = connector(temp->right);
                break;
            } else {
                temp = temp->right;
            }
        } else {
            if(temp->left != nullptr && temp->left->data == val) {
                temp->left = connector(temp->left);
                break;
            } else {
                temp = temp->left;
            }
        }
    }
    return root;
}

void printTree(Node* root) {
    if(root == nullptr)
        return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->right = new Node(14);
    root->right->left = new Node(10);

    root = deleteNode(root, 5);
    printTree(root);
}
