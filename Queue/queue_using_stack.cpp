#include <iostream>
#include <stack>
using namespace std;
//approach-1
/*
class queue_using_stack
{
    stack<int> s1, s2;

public:
    void push(int n)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(n);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        if(s1.empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int val = s1.top();
        s1.pop();
        return val;
    }

    int top()
    {
        if(s1.empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return s1.top();
    }

    void display()
    {
        stack<int> temp = s1;
        while(!temp.empty())
        {
            cout << temp.top() << endl;
            temp.pop();
        }
    }
};
*/

class queue_using_stack
{
    stack<int> s1, s2;

public:
    void push(int n)
    {
        s1.push(n);
    }

    int top()
    {
        if(s2.empty())
        {
            // Move all elements from s1 to s2
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return s2.top();
    }

    int pop()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    void display()
    {
        // Copy stacks so original queue is not lost
        stack<int>temp2 = s2;

        // Elements in s2 are in correct queue order
        while(!temp2.empty())
        {
            cout << temp2.top() << " ";
            temp2.pop();
        }
    }
};
int main()
{
    queue_using_stack qs;
    qs.push(23);
    qs.push(26);
    qs.push(15);
    qs.pop();
    cout<<qs.top()<<endl;
    qs.display();
    return 0;
}
