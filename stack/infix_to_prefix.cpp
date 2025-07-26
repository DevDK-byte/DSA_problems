#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;

int precedence(char op)
{
    if(op=='^')
    {
        return 3;
    }
    if(op=='*' || op=='/')
    {
        return 2;
    }
    if(op=='+' || op=='-')
    {
        return 1;
    }
    return -1;
}

void InfixToPrefx(string s, int n)
{
    int i=0;
    stack<char>st;
    string answer = "";
    reverse(s.begin(),s.end()); //reverse the infix and covert parenthesis
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            s[i] = ')';
        }
        else if(s[i]==')')
        {
            s[i] = '(';
        }
    }

    while(i<n) //step 2: do infix to postfix
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            answer += s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                answer += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(s[i]=='^')
            {
               while(!st.empty() && precedence(s[i])<=precedence(st.top()))
               {
                   answer += st.top();
                   st.pop();
               }
            }
            else{
                while(!st.empty() && precedence(s[i]) < precedence(st.top()))
                {
                    answer += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }

    while(!st.empty())
    {
        answer += st.top();
        st.pop();
    }

    reverse(answer.begin(),answer.end()); //reverse the postfix, get prefix
    cout<<answer<<endl;
}

int main()
{

string s = "(A+B)*C-D+F";
int n = s.length();
InfixToPrefx(s,n);

return 0;
}
