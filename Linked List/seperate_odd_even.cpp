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
//brute force--T.C= 0(2n) and s.c = 0(n)
Node* oddEven(Node* head)
{
    int arr[50];//empty array
    int i=0;
    Node* temp = head;
    if(temp==nullptr || temp->next ==nullptr)//if its empty or a single node
    {
        return head;
    }
    while(temp!=nullptr && temp->next!=nullptr)
    {
        arr[i++] = temp->data;//put in array
        temp = temp->next->next;//jump by two indices
    }
    if(temp) //if list is odd and there was element at last node
    {
        arr[i++] = temp->data;//put the value in arrayist
    }
    //for putting all even indiced nodes
    temp = head->next;
    while(temp!=nullptr && temp->next!=nullptr)
    {
        arr[i++] = temp->data;//put in array
        temp = temp->next->next;
    }
    if(temp) //in case there is a last node
    {
        arr[i++]  =temp->data;//put in array;
    }
    i = 0; temp = head;//reassign temp to head after putting all odd and even
    while(temp!=nullptr)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
return head;
}
//optimized-> T.C = 0(n)
Node* oddeven(Node* head)
{
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    if(head==nullptr || head->next==nullptr)//if empty or has single node
    {
        return head;
    }
    while(even!=nullptr && even->next!=nullptr)//if even becomes null,odd auto becomes null
    {
        odd->next = odd->next->next;//link current odd to next odd
        even->next = even->next->next;//link current even to next even
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;//odd last linking to evenhead
return head;
}

void printList(Node* head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);

    head = oddeven(head);

    cout << "After Odd-Even Separation: ";
    printList(head);

    return 0;
}
