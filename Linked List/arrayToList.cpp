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
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* arrayToList(int arr[],int n)
{
    Node *head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
//Length of a linked list
int length(Node* head)
{
    int count_len = 0;
    Node* temp = head;

    while(temp!=nullptr)
    {
        temp = temp->next;
        count_len++;
    }
    return count_len;
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int sizee = sizeof(arr)/sizeof(arr[0]);
    Node* head = arrayToList(arr,sizee);
    cout<<head->data<<endl;
    cout<<head->next<<endl;
    cout<<endl;
    //traversing and printing all elements;
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<endl;
        temp = temp->next; //moves to next node
    }
    //length
    int len = length(head);
    cout<<"Length = "<<len<<endl;
}
