#include<iostream>
using namespace std;

class Node
{
  public:
      int data;
      Node* next;
      Node* Back;

      Node(int d)
      {
          data = d;
          next = nullptr;
          Back  = nullptr;
      }
      Node(int d, Node* f, Node* b)
      {
          data =d;
          next = f;
          Back  = b;
      }
};
Node* insertBeforeHead(Node* head, int val)
{
    Node* newNode = new Node(val,head,nullptr);
    head->Back = newNode;

    return newNode;
}
Node* insertBeforeTail(Node* head,int val)
{
    Node* tail = head;
    while(tail->next!=nullptr)
    {
        tail = tail->next;
    }
    Node* prev  = tail->Back;//identify previous node
    Node* newNode = new Node(val,tail,prev);
    prev->next = newNode;
    tail->Back = newNode;
return head;
}
Node* insertBeforeK(Node* head, int k,int val)
{
    if(k==1)//edge case
    {
        //insert before head
    }

    Node* temp = head;
    int count = 0;
    while(temp!=nullptr)
    {
        count++;
        if(count==k)
            break;
        temp = temp->next;
    }
    Node* prev = temp->Back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->Back = newNode;
return head;
}
void printf(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}
Node* convertToDLL(int arr[], int n)
{
    Node* head  = new Node(arr[0]);
    Node* prev = head;

    for(int i=1; i<n;i++)
    {
        Node* newNode = new Node(arr[i],nullptr,prev);
        prev->next = newNode;
        prev = prev->next;
    }
    return head;
}
int main()
{
    int arr[] = {0,1,4,5,6};
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    int sizee = sizeof(arr)/sizeof(arr[0]);
    head = convertToDLL(arr,sizee);
   // head = insertBeforeHead(head,23);
   //head = insertBeforeTail(head,23);
   head = insertBeforeK(head,4,23);
   printf(head);
}
