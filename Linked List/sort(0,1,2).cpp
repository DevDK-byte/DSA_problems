#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
    Node(int d,Node* n)
    {
        data = d;
        next = n;
    }
};
//brute force--> T.C = 0(2n)
Node* sortList(Node* head)
{
    Node* temp = head;
    int count0=0, count1=0, count2= 0;
    while(temp!=nullptr)
    {
        if(temp->data==0)
        {
            count0++;
        }
        else if(temp->data==1)
        {
            count1++;
        }
        else
            count2++;
        temp = temp->next;
    }

    temp = head;
    while(temp!=nullptr)
    {
        if(count0)
        {
            temp->data = 0;
            count0--;
        }
        else if(count1)
        {
            temp->data = 1;
            count1--;
        }
        else{
            temp->data = 2;
            count2--;
        }
        temp =temp->next;
    }
    return head;
}
//optimized-->
Node* sortL(Node* head)
{
    Node* temp = head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    //Three extra pointers used for traversal
    Node*  zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    if(head==NULL  || head->next == nullptr)
    {
        return head;
    }
    //seggregating
    while(temp!=nullptr)
    {
        if(temp->data==0)
        {
            zero->next = temp;
            zero = temp;//zero goes to next node from dummy node
        }
        else if(temp->data==1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    //linking L1,L2,L3
    /*if(oneHead->next!=nullptr)
    {
        zero->next = oneHead->next;
    }
    else
    {
        zero->next =twoHead->next;
    }
    one->next = twoHead->next;
    two->next = nullptr;*/

    //or simply the linkings doing in reverse order-->
    two->next = nullptr;
    one->next = twoHead->next;
    zero->next = oneHead->next;
    Node* newHead = zeroHead->next;
    return newHead;
}

void printList(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head = sortL(head);
    printList(head);
}
