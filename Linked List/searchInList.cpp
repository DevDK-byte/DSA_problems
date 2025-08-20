#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next  = nullptr;
    }
};

Node* arrayToList(int arr[],int n)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
bool searchInList(Node* head, int value)
{
    Node* temp = head;

    while(temp!=nullptr)
    {
        if(temp->data == value)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int sizee = sizeof(arr)/sizeof(arr[0]);

    Node* head = arrayToList(arr,sizee);
    int value;
    cin>>value;
    if(searchInList(head,value)==true)
    {
        cout<<"Element found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    return 0;
}
