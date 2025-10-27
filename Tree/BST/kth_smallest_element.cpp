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

int kSmallest(Node* root, int k)
{
    int count = 0;
    int answer= -1;

    Node* current = root;
    while(current!=NULL)
    {
        if(current->left==nullptr)
        {
            count++;
            if(count==k) //node once visited and went left
            {
                answer = current->data;
            }
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
                //Node visited second and and for real
                prev->right = nullptr; // remove the thread,visit node and then visit right subtree
                count++;
                if(count==k)
                {
                    answer = current->data;
                }
                current = current->right;
            }
        }
    }
    return answer;
}
int kLargest(Node* root, int k)
{
    int count = 0;
    int answer= -1;

    Node* current = root;
    while(current!=NULL)
    {
        if(current->left==nullptr)
        {
            count++;
            if(count==k) //node once visited and went left
            {
                answer = current->data;
            }
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
                //Node visited second and and for real
                prev->right = nullptr; // remove the thread,visit node and then visit right subtree
                count++;
                if(count==k)
                {
                    answer = current->data;
                }
                current = current->right;
            }
        }
    }
    int largest= count- answer;
    return largest;
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

    //int result = kSmallest(root,2);
cout<<kLargest(root,2);
    //cout<<result<<endl;
}
