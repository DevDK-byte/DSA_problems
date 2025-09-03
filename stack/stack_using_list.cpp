#include<iostream>
#include<stack>
using namespace std;
struct Node //linked list structure
{
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

struct stackUsingList
{
    Node* top = nullptr;//no assignment means top = nullptr;
    int current_size=0;

    void push(int n)
    {
        Node* newNode = new Node(n); //create a new node
        newNode->next = top;
        top = newNode;
        current_size++;
    }
    void pop()
    {
        Node* temp = top;
        top = top->next;
        delete temp;
        current_size--;
    }
    int Top()
    {
        return top->data;
    }
    int Length()
    {
        return current_size;
    }
    void print()
    {
        Node* i = top;
        while(i!=nullptr)
        {
            cout<<i->data<<" ";
            i = i->next;
        }
    }
} ;

int main()
{
    stackUsingList sl;
    sl.push(1);
    sl.push(12);
    sl.push(23);
    cout<<sl.Top()<<endl;
    sl.pop();
    sl.print();
    return 0;
}
