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
void printList(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
bool detectLoop(Node* head)//T.C = 0(n) and S.C = 0(1)
{
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=nullptr && fast!=nullptr)//for odd and even linear lists
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    //printList(head);
    if(detectLoop(head))
    {
        cout<<"Loop found"<<endl;
    }
    else
        cout<<"No loop "<<endl;
}
