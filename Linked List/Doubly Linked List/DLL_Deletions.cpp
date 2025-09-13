#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* Back;

    Node(int d,Node* n, Node* b)
    {
        data = d;
        next = n;
        Back = b;
    }
    Node(int d)
    {
        data = d;
        next = nullptr;
        Back = NULL;
    }

};
Node* deleteHead(Node* head)
    {
        Node* prev = head;
        if(prev==nullptr || prev->next==nullptr)
            return head;
        prev = head;
        head = head->next;
        head->Back = nullptr;
        prev->next = nullptr;
        delete prev;
        return head;
    }
Node* deleteTail(Node* head)
{
    Node* tail = head;
    if(head==nullptr|| head->next==nullptr)
        return NULL;
    while(tail->next!=nullptr)
    {
        tail = tail->next;
    }
    Node* prev = tail->Back;
        tail->Back = nullptr;
        prev->next=nullptr;
        delete tail;
    return head;
}
Node* deleteK(Node* head,int k)
{
    Node* temp = head;
    int counter=0;
    while(temp!=nullptr)
    {
        counter++;
        if(counter==k)
            break;
        temp = temp->next;//temp now is now the kth node!
    }
    Node* Front = temp->next;
    Node* prev = temp->Back;

    if(Front==nullptr && prev == nullptr)
    {
        delete(temp);
    }
    if(prev==nullptr)//standing at head
    {
        Node* pre = head;
        head = head->next;
        head->Back=nullptr;
        pre->next = nullptr;
        delete pre;
        return head;
    }
    if(Front==nullptr)//standing at tail
    {

    }
    prev->next = Front;
    Front->Back = prev;
}
void deleteByNode(Node* head)
{
     Node* prev = head->Back;
     Node* Front = head->next;

     if(Front==nullptr)//last node
     {
         prev->next = nullptr;
         head ->Back = nullptr;
         delete head;
         return;
     }
     prev->next = Front;
     Front->Back = prev;

     head->next=nullptr;
     head->Back = nullptr;
     delete head;
}

Node* array_DLL(int arr[],int n)
{
    Node* head = new Node(arr[0]);//build the head;
    Node* prev = head; //store head as prev

    for(int i=1;i<n;i++)
    {
        Node* temp = new Node(arr[i],nullptr,prev); //after inserting new node,next points to null and back points to previous
        prev->next = temp;//previous node's head points to new node
        prev = prev->next;//prev moves to next node
    }
    return head;
}
void printDLL(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}

int main()
{
    int arr[] = {1,2,3,4};
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    int sizee = sizeof(arr)/sizeof(arr[0]);
    head = array_DLL(arr,sizee);
    printDLL(head);
    cout<<endl;
    //head = deleteHead(head);
    //head=  deleteTail(head);
    //int k;
    //cin>>k;
    deleteByNode(head);
    printDLL(head);

    return 0;
}
