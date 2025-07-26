#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>
#include<math.h>
using namespace std;

class MinStack
{
    stack<int>main;
    stack<int>minimum;

public:
    void pop()
    {
        if(main.empty())
        {
            cout<<"cannot remove element from empty stack"<<endl;
            return;
        }
        if(minimum.top() == main.top()) //if element being popped is minimum,pop from min stack tooo
        {
            minimum.pop();
        }
        main.pop();
    }
    int top()
    {
        if(main.empty())
        {
            return -1;
        }
        return main.top();
    }
    void push(int n)
    {
        main.push(n);
        if(minimum.empty() || n<minimum.top())
        {
            minimum.push(n);
        }
    }
    int getmin()
    {
        if(minimum.empty())
        {
           return -1;
        }
        return minimum.top();
    }
};

int main()
{
    MinStack m;
    m.push(10);
    m.push(20);
    m.push(30);
    cout<<m.top()<<endl;
    cout<<m.getmin()<<endl;
    m.pop();
    cout<<m.getmin()<<endl;
    cout<<m.top()<<endl;
    return 0;
}
