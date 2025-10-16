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
int findStartingPoint(Node* head)//T.C = 0(n) and S.C = 0(1)
{
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr &&  fast->next!=nullptr)//for odd and even linear lists
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            slow = head;
            while(slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow->data;// we can return fast too as both are standing at same node
        }
    }

    return 0;//no loop
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    //create a loop by connecting last node with 2
    head->next->next->next->next->next = head->next->next;
    //printList(head);
    cout<<findStartingPoint(head)<<endl;
}
