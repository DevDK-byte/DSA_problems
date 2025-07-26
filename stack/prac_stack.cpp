#include<iostream>
using namespace std;
#define sizee 10

class StackImplementation
{
    int top = -1;
    int st[sizee];

public:
    void push(int n)
    {
        if(top == sizee - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top += 1;
        st[top] = n; //similar as st[++top] = n
    }

    int Top()
    {
        if(top == -1)
        {
            cout << "No elements found" << endl;
            return -1;
        }
        return st[top];
    }

    int Pop()
    {
        if(top == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return st[top--];//removing element frm top of array and then reducing top by 1
    }

    bool isEmptyStack()
    {
        if(top==-1)
        {
            return true;//condition is true
        }
    return false;
    }
    bool isFullStack()
    {
        if(top == sizee-1)
        {
            return true;
        }
    return false;
    }
    int Size()
    {
        return top + 1;
    }
};

int main()
{
    StackImplementation s1;
   // s1.push(10);
   // s1.push(12);
    //s1.Pop();
    cout << s1.Top() << endl;
  //  cout<<s1.Size()<<endl;
    cout<<s1.isEmptyStack()<<endl;
   // cout<<s1.isFullStack()<<endl;
    return 0;
}

