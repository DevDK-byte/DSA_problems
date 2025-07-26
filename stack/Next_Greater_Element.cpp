#include<iostream>
#include<stack>
using namespace std;
//optimal solution-->
void nextGreaterElement(int arr[], int n)
{
    stack<int> st;
    int nge[n];

    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        cout << nge[i] << endl;
    }
}

int main()
{
    int arr[] = {6, 0, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreaterElement(arr, n);
    //int nge[n];
    //brute force-->
   /* for(int i=0; i<n; i++)
    {
        nge[i] =-1;
        for(int j=i+1; j<n; j++)
        {
        if(arr[j]>arr[i])
        {
            nge[i] = arr[j];
            break;
        }
    }
    }
    for(int i=0; i<n; i++)
    {
        cout<<nge[i]<<endl;
    }*/


    return 0;
}
