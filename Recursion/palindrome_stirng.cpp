#include<iostream>
using namespace std;

bool checkPalindrome(string s,int i,int n)
{
    if(i>=n/2)
    {
        return true;
    }
    if(s[i]!=s[n-i-1])
    {
        return false;
    }
    return checkPalindrome(s,i+1,n);
}
int main()
{
    string s;
    cin>>s;
    int sizee = s.size();
    if(checkPalindrome(s,0,sizee))
    {
        cout<<"yes"<<endl;
    }
    else
        cout<<"no"<<endl;
}
