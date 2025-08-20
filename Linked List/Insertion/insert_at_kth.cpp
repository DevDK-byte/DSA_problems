#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int dat,Node* n)
    {
        data = dat;
        next = n;
    }
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};
Node* arrayToList(int arr[],int n)
{
    if(n==0)
        return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<n;i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* insertAtK(Node* head,int value,int k)
{
    if(head==nullptr) //if list is empty
    {
        if(k==1)
        {
            Node* n = new Node(value);
            return n;
        }
        else
            return nullptr;
    }
    if(k==1) //if list not empty and position=1(head)
    {
        Node* newNode = new Node(value,head);
        return newNode;
    }
    int counter = 0;
    Node* temp = head;
    while(temp!=nullptr)
    {
        counter++;
        if(counter==k-1)
        {
            Node* newNode = new Node(value,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
return head;
}

void printLL(Node*head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}
Node* insertBefore(Node* head,int value,int position)
{
    if(head==nullptr)
    {
        return nullptr;
    }
    if(head->data == position)
    {
        Node* newNode = new Node(value,head);
        return newNode;
    }
    Node* temp = head;
    bool found = false;
    while(temp->next!=nullptr) //traverse before last element(because we are checking next)
    {
        if(temp->next->data==position){
        Node* newNode = new Node(value,temp->next);
        temp->next = newNode;
        found = true;
        break;}
        temp = temp->next;
    }
    if(!found)
    {
        cout<<"position not found"<<endl;
    }
return head;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int s = sizeof(arr)/sizeof(arr[0]);
    int value,k;
    cout<<"Enter a value to insert = ";
    cin>>value;
    cout<<"Enter position any = ";
    cin>>k;

    Node* head = arrayToList(arr,s);
    //head = insertAtK(head,value,k);
    head = insertBefore(head,value,k);
    printLL(head);

    return 0;
}
