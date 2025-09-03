#include<iostream>
#include<stack>
using namespace std;

void nextSmaller(int arr[],int n)
{
    int nse[n]; stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nse[i]= -1;
        }
        else
        {
            nse[i] = st.top();
        }
        st.push(arr[i]);
    }
    for(int i=0; i<n;i++)
    {
        cout<<nse[i]<<endl;
    }
}
int main()
{
    int arr[] = {5,4,1,3,2};
    int sizee = sizeof(arr)/sizeof(arr[0]);
    nextSmaller(arr,sizee);
    /*brute force-->
    int nse[sizee];
    for(int i=0;i<sizee;i++)
    {
        nse[i] =-1;
        for(int j=i-1;j>=0;j--)
            {
                if(arr[j]<arr[i])
                {
                    nse[i] = arr[j];
                    break;
                }
                else
                {
                    nse[i] = -1;
                }
            }
    }
    for(int i=0; i<sizee; i++)
    {
        cout<<nse[i]<<endl;
    }
    */
}
