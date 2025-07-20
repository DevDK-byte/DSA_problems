#include<iostream>
using namespace std;

bool isSorted(int arr[],int n)
{
    for(int i=1; i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int arr[] = {1,4,68,32,29,58,42};
    int n= sizeof(arr)/sizeof(arr[0]);
    if(isSorted(arr,n))
    {
        cout<<"yes"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}

