#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
    Node(int dat, Node* nex)
    {
        data = dat;
        next = nex;
    }
};
Node* arrayToList(int arr[],int n)
{
    if(n==0)
    {
        return nullptr;
    }
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<n;i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover  =temp;
    }
    return head;
}
void printList(Node* head)
{
    if(head==nullptr)
        cout<<head<<endl;
    while(head!=nullptr)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}
Node* insertAtTail(Node* head,int value)
{
    if(head==nullptr) //if linked list empty,add new value
    {
        Node* n = new Node(value);
        return n;
    }
    Node* temp = head;
    while(temp->next!=nullptr)
    {
        temp = temp->next;
    }
    Node* newNode  = new Node(value);
    temp->next = newNode;
return head;
}
int main()
{
    int arr[] ={};
    int sizee = sizeof(arr)/sizeof(arr[0]);

    int k;
    cin>>k;
    Node* head = arrayToList(arr,sizee);
    head=insertAtTail(head,k);
    printList(head);
}
