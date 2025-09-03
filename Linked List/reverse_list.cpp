#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int dat, Node* nex = nullptr)
    {
        data = dat;
        next = nex;
    }
};
//brute force-->
Node* reverseList(Node* head)
{
    Node* temp = head;
    stack<int>s;

    while(temp!=nullptr)//take all data and put to stack
    {
        s.push(temp->data);
        temp = temp->next;
    }
    //reassign to linked list in reverse order
    temp = head;
    while(temp!=nullptr)
    {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
return head;
}
//optimized-->
Node* reverselist(Node* head)
{
    Node* temp = head;
    Node* prev = nullptr;
    Node* frnt;
    while(temp!=nullptr)
    {
            frnt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = frnt;
    }
return prev;//new head
}
printList(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main()
{

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(6);
   // head->next->next->next->next->next = new Node(10);
   printList(head);
   head = reverselist(head);
   printList(head);
    return 0;
}
