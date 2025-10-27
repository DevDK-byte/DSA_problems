#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right =NULL;
    }
};

void zigzagSpiral(Node* root)
{
    queue<Node*>qu;

    qu.push(root);
    bool leftToRight = true;
    while(!qu.empty())
    {
        int s = qu.size();
        int arr[s];

        for(int i=0; i<s; i++)
        {
            Node* current = qu.front();
            qu.pop();

            int index;
            if(leftToRight==true)
            {
                index = i;
            }
            else
            {
                index = s-1-i;
            }
            arr[index] = current->data;

            if(current->left)
            {
                qu.push(current->left);
            }
            if(current->right)
            {
                qu.push(current->right);
            }
        }
        for(int i=0; i<s; i++)
            {
                cout<<arr[i]<<" ";
            }
        leftToRight = !leftToRight;
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

    zigzagSpiral(root);
    return 0;
}

