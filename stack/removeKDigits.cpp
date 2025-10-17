#include<iostream>
#include<stack>
#include<math.h>
#include<string.h>
#include<cstring>
using namespace std;
void removeDigits(string s, int k)
{
    stack<char>st;
    for(int i=0; i<s.length(); i++)
    {
        while(!st.empty() && k>0 && (st.top()-'0')>(s[i]-'0'))
        {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    //edge case (if any greater number still left)
    while(k>0)
    {
        st.pop();
        k--;
    }
    if(st.empty())
    {
        cout<<"0";
    }
    string res ="";
    while(!st.empty())
    {
        res = res + st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    while(res.size()!=0 && )
    cout<<res<<endl;
}

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    removeDigits(s,k);

    return 0;
}
