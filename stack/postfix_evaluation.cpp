#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>
#include<math.h>
using namespace std;

bool isOperator(char op)
{
    if(op=='+' || op=='-' || op=='*' || op=='/' || op=='^')
    {
        return true;
    }
    return false;
}

int operations(int op1,int op2,char op)
{
    if(op=='+')
    {
        return op1+op2;
    }
    else if(op=='-')
    {
        return op1-op2;
    }
    else if(op=='*')
    {
        return op1*op2;
    }
    else if(op=='/')
    {
        return op1/op2;
    }
    else{
        return pow(op1,op2);
    }
    return -1;
}

void postfix_evaluation(string s,int n)
{
    stack<int>st;

    for(int i=0; i<n; i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0'); //convert char to integer
        }
        else if(isOperator(s[i])==true)
        {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            int result = operations(op1,op2,s[i]);
            st.push(result);
        }
    }
    cout<<st.top()<<endl;
}

int main()
{
string s = "123*+5-";
int n = s.length();
postfix_evaluation(s,n);

return 0;
}
