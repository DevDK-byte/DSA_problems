#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;

    Node(int dat,Node* nex)
    {
        data = dat;
        next = nex;
    }
    Node(int da)
    {
        data = da;
        next = nullptr;
    }
};
Node* findN(Node* head,int n)
{
    Node* current = head;
    while(current!=nullptr)
    {
        int count = 0;
        Node* temp = current->next; //count how many nodes after head
        while(temp!=nullptr)
        {
            count++;
            temp = temp->next;
        }
            if(count==n-1)
            {
                return current;
            }
            current = current->next;
    }
    return nullptr;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    int n;
    cin>>n;
    Node* result = findN(head,n);
    if(result!=nullptr)
    {
        cout<<"found and value is = "<<result->data<<endl;
    }
    else
        cout<<"not found"<<endl;

    return 0;
}
