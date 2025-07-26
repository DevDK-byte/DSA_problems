#include<iostream>
#include<stack>
using namespace std;

bool Balanced(string s, int n)
{
    stack<char> str;  // use char not string

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            str.push(s[i]);
        }
        else
        {
            if(str.empty())
            {
                return false;
            }

            char ch = str.top();
            str.pop();

            if((s[i] == ')' && ch != '(') ||
               (s[i] == '}' && ch != '{') ||
               (s[i] == ']' && ch != '['))
            {
                return false;
            }
        }
    }

    return str.empty();  // If stack is empty at the end, it's balanced
}

int main()
{
    string s = "()(()[()]";
    int n = s.length();

    if(Balanced(s, n))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
