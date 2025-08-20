#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }
};
int main()
{
    int x = 10;
    int arr[] = {1,2,3,4,5};
    Node* n = new Node(x,nullptr); //use -> to access element and next for pointer
    Node* n1 = new Node(arr[0],nullptr);
   // Node y = Node(x,nullptr); //use (.) operator to access next and element for normal object
    cout<<n->data<<endl;
    cout<<n->next<<endl;
    return 0;
}
