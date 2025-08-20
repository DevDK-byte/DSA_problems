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

Node* insertAtHead(Node* head,int element)
{
    Node*temp = new Node(element,head);
    return temp;
}
void printList(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}
int main()
{
    int arr[] ={5,6,7,8,9};
    int sizee = sizeof(arr)/sizeof(arr[0]);
    Node* head = arrayToList(arr,sizee);
    int k;
    cin>>k;
    head = insertAtHead(head,k);
    printList(head);
}
