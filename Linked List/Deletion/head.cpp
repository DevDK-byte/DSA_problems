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
Node* deleteHead(Node* head)
{
    Node* temp =head;
    head = head->next;
    free(temp); //deallocates the head memory

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
int main()
{
    int arr[] ={5,6,7,8,9};
    int sizee = sizeof(arr)/sizeof(arr[0]);

    Node* head = arrayToList(arr,sizee);
    //printList(head);

    head = deleteHead(head);
    Node* temp = head;
    printList(temp);

}
