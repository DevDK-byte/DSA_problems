#include<iostream>
using namespace std;
void oneToN(int i,int n)
{
    if(i>n)
    {
        return;
    }
    cout<<i<<endl;
    oneToN(i+1,n);
}

void call(int n,int i){
    if(n < i)return;
    call(n,i+1);
    cout<<i<<" ";
}
int main (){
    int  n;cin>>n;
    call(n,1);
}
