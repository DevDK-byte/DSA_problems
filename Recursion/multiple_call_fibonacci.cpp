#include<iostream>
using namespace std;
int MultipleFibonacci(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return MultipleFibonacci(n-1)+MultipleFibonacci(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<MultipleFibonacci(n);
    return 0;
}
