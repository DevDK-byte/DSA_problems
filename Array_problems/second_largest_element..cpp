#include<iostream>
using namespace std;


int main()
{
    int arr[] = {1,4,68,32,29,58,42,65};
    int largest = arr[0]; int second = -1;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        if(arr[i]>largest)
        {
            largest = arr[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>second && arr[i]!=largest)
        {
            second  = arr[i];
        }
    }
    cout<<second<<endl;
}
