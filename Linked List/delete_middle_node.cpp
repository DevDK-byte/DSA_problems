#include<iostream>
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
Node* deletemiddle(Node* head)
{
    Node* temp = head;
    int counter= 0;

    if(head==nullptr || head->next==nullptr)//if list empty or has single node
    {
        return nullptr;
    }
    while(temp!= nullptr)
    {
        counter++;
        temp = temp->next;
    }
    int mid_node  = (counter/2);
    temp = head;
    while(temp!=nullptr)
    {
        mid_node--;
        if(mid_node==0)
        {
            break;
        }
        temp = temp->next;
    }
    temp->next = temp->next->next;
return head;
}
//optimized->
Node* deleteMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next; //move fast one time ,skipping slow 1 time
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
return head;
}
void printList(Node* head)
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
    head = deleteMiddle(head);
    printList(head);
    return 0;
}
