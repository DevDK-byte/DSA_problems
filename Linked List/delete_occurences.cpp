#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
    Node(int d,Node* n,Node* p)
    {
        data = d;
        next = n;
        prev = p;
    }
};
Node* deleteOccurrences(Node* head,int key)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        if(temp->data==key)
        {
            if(temp==head)
            {
                head = head->next;//new head updated
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            if(nextNode)
            {
                nextNode->prev = prevNode;
            }
            if(prevNode)
            {
                prevNode->next = nextNode;
            }
            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
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
    Node* head = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(4);
    Node* n3 = new Node(2);
    Node* n4 = new Node(1);
    Node* n5 = new Node(2);
    Node* n6 = new Node(1);

    head->next = n1;

    n1->prev = head; n1->next = n2;
    n2->prev = n1;   n2->next = n3;
    n3->prev = n2;   n3->next = n4;
    n4->prev = n3;   n4->next = n5;
    n5->prev = n4;   n5->next = n6;
    n6->prev = n5;

    head = deleteOccurrences(head,2);
    printf(head);
}
