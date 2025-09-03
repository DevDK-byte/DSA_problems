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

void inorder_iterative(Node* root) {
    stack<Node*> st;
    Node* curr = root;//store root

    while (curr != nullptr || !st.empty()) {
        // Go all the way left
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        // Process the top node
        curr = st.top();
        st.pop();

        cout << curr->data << " ";  // print the data

        // Move to right subtree
        curr = curr->right;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Inorder Traversal (Iterative): ";
    inorder_iterative(root);
    return 0;
}
