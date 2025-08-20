#include<iostream>
#include<queue>
using namespace std;

class qu
{
    int start =-1,end=-1;
    static const int sizee = 5;
    int q[sizee];
    int current_size=0;

public:
    int push(int n)
    {
        if(current_size==sizee)
        {
            cout<<"queue overflow"<<endl;
            return -1;
        }
        if(current_size==0)
        {
            start=0,end=0;
        }
        else
        {
            end = (end+1)%sizee;
        }
        q[end] = n;
        current_size++;
    }
    int pop()
    {
        if(current_size==0)
        {
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        int element = q[start];
        if(current_size==1)
        {
            start=-1;end=-1;
        }
        else
        {
            start = (start+1)%sizee;
        }
        current_size--;
        return element;
    }
    int top()
    {
        if(current_size==0)
        {
            return -1;
        }
        return q[start];
    }
    int length()
    {
        return current_size;
    }
    void display()
    {
        int i=start;
        for(int counting=0;counting<current_size;counting++)
        {
            cout<<q[i]<<endl;
            i = (i+1)%sizee;
        }
    }
};
int main()
{
    qu q;
    q.push(23);
    q.push(10);
    q.push(15);
    q.pop();
    cout<<q.length()<<endl;
    //cout<<q.top()<<endl;
    q.display();
}
