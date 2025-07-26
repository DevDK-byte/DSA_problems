#include<iostream>
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

void InfixToPostifx(string s,int n)
{
   int i=0;
   stack<char>s1; string answer="";

   while(i<n)
   {
       if((s[i]>='A' && s[i]<='Z') || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9')
       {
           answer += s[i];
       }
       else if(s[i]=='(')
       {
           s1.push(s[i]);
       }
       else if(s[i]==')')
       {
           while(!s1.empty() && s1.top()!= '(')
           {
               answer += s1.top();
               s1.pop();
           }
           s1.pop();
       }
       else
       {
           while(!s1.empty() && precedence(s[i])<=precedence(s1.top()))
           {
               answer += s1.top();
               s1.pop();
           }
           s1.push(s[i]);

       }
       i++;
   }
   while(!s1.empty()) //until stack is not empty.
   {
       answer += s1.top();
       s1.pop();
   }
   cout<<answer<<endl;
}

int main()
{
    string input = "a+b*(c^d-e)";
    int n = input.length();
    InfixToPostifx(input,n);

    return 0;
}
