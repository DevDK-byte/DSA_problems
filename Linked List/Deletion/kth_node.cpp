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
Node* deleteKNode(Node* head,int k)
{
    if(head==nullptr)
    {
        return head;
    }
    if(k==1)
    {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int counter=0; Node* temp = head;
    Node* prev = nullptr;

    while(temp!=nullptr)
    {
        counter++;
        if(counter==k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
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

int main()
{
    int arr[] ={5,6,7,8,9};
    int sizee = sizeof(arr)/sizeof(arr[0]);

    int k;
    cin>>k;
    Node* head = arrayToList(arr,sizee);
    deleteKNode(head,k);
    printList(head);
}
