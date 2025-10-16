#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int d, Node* n)
    {
        data = d;
        next = n;
    }
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

Node* collisionPoint(Node* small, Node* large, int diff)
{
    while(diff)
    {
        large = large->next;
        diff--;
    }
    while(small!=nullptr && large!=nullptr)
    {
        if(small==large)
        {
            return small;
        }
        small = small->next;
        large = large->next;
    }
    return nullptr;
}
//T.C = 0(n1+2n2) and S.C = 0(1)-->better aproach
Node* intersectingPoint(Node* head1, Node* head2)
{
    Node* t1 = head1;
    Node* t2 = head2;
    int length1 = 0, length2 = 0;
    //finding lengths
    while(t1!=nullptr)
    {
        length1++;
        t1 = t1->next;
    }
    while(t2!=nullptr)
    {
        length2++;
        t2 = t2->next;
    }
    if(length1<length2)
    {
        return collisionPoint(head1,head2,length2-length1);
    }
    else
    {
        return collisionPoint(head2, head1, length1-length2);
    }
}
//optimal approach-->
Node* collPoint(Node* head1, Node* head2)
{
    Node* t1 = head1;
    Node* t2 = head2;

    while(t1!=t2)
    {
        if(t1==nullptr)
        {
            t1 = head2;
        }
        else
        {
            t1 = t1->next;
        }
        if(t2==nullptr)
        {
            t2 = head1;
        }
        else
        {
            t2 = t2->next;
        }
        if(t1==t2){
            return t1;
        }
    }
    return t1;
}
int main()
{
   Node* common = new Node(15);
    common->next = new Node(30);

    // First list: 3->6->9->15->30
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = common; // link to common

    // Second list: 10->15->30
    Node* head2 = new Node(10);
    head2->next = common; // link to common

    Node* intersection = collPoint(head1, head2);

    if(intersection)
        cout << "Intersection at node with data = " << intersection->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
