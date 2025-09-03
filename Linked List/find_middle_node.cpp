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
//brute force-->0(2n) and S.C = 0(1)
Node* findMiddle(Node* head)
{
    Node* temp = head;
    int counter = 0;

    while(temp!=nullptr)//counts number of nodes
    {
        counter++;
        temp = temp->next;
    }
    int middleNode = (counter/2)+1;
    temp= head;
    while(temp!=nullptr)
    {
        middleNode--;
        if(middleNode==0)
        {
            break;
        }
        temp = temp->next;
    }
return temp;
}
//optimized--> T.C= 0(n) and S.C = 0(1)
Node* FindMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next!=nullptr)//until fast is at null or at the last node(because list can be odd or even numbered)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
return slow; //slow will always be the middle node
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
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(6);
    //head->next->next->next->next->next = new Node(7);

    printList(head);
    head = FindMiddle(head);
    cout<<head->data<<endl;

    return 0;
}
