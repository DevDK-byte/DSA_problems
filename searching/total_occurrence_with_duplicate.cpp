#include<iostream>
using namespace std;

int firstOccurrence(int arr[],int number,int n)
{
    int low = 0,high = n-1;
    int first = -1;
    while(low<=high)
    {
        int mid = (high+low)/2;
        if(arr[mid]==number)
        {
            first = mid;
            high = mid-1;
        }
        else if(arr[mid]<number)
        {
            low = mid+1;

        }
        else
        {
            high = mid-1;
        }
    }
    return first;
}
int lastOccurrence(int arr[],int number,int n)
{
    int low=0,high=n-1,last=-1;
    while(low<=high)
    {
        int mid = (high+low)/2;
        if(arr[mid]==number)
        {
            last = mid;
            low = mid+1;
        }
        else if(arr[mid]<number)
        {
            low = mid+1;
        }
        else
        {
            high =mid-1;
        }
    }
    return last;
}

int totalOccurrence(int arr[],int number,int n)
{
    int first = firstOccurrence(arr,number,n);
    int last = lastOccurrence(arr,number,n);
    int total = (last - first) +1;
}
int main()
{
    int arr[] = {2,3,3,8,8,8,11,13,13,13,13,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    int number;
    cin>>number;
    cout<<totalOccurrence(arr,number,n)<<endl;
}
