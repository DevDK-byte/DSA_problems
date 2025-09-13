#include<iostream>
using namespace std;
int sumOfN(int i,int sum)//parameterised way
{
    if(i==0)
    {
        cout<<sum<<endl;
    }
    return sumOfN(i-1,sum+i);
}
//function way
int sumofn(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n+sumofn(n-1);
}
int main()
{
    int n;
    cin>>n;
    //cout<<sumOfN(n,0)<<endl;
    cout<<sumofn(n)<<endl;
   return 0;
}
