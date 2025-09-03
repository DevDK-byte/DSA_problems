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
Node* removeN(Node* head, int n)
{
    Node* temp = head;
    int count = 0;

    // Find length
    while(temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    // Edge case: delete head
    if(count == n)
    {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Move to the node just before the one we want to delete
    int steps = count - n - 1;
    Node* t = head;
    while(steps--)
    {
        t = t->next;
    }

    // Delete target node
    Node* deleteNode = t->next;
    t->next = t->next->next;
    delete deleteNode;

    return head;
}
Node* removeNth(Node* head,int n)
{
    Node* fast = head;
    Node* slow = head;

    for(int i=0;i<n;i++)
    {
        fast = fast->next;
    }
    if(fast==nullptr)//delete head
    {
        return head->next;
    }
    while(fast->next!=nullptr)
    {
        slow =  slow->next;//stops before nth node
        fast = fast->next;
    }
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
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
    // Create list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n;
    cout << "Enter n (node from end to delete): ";
    cin >> n;

    head = removeNth(head, n);

    cout << "List after deletion: ";
    printList(head);

    return 0;
}
