#include<iostream>
using namespace std;

int searchPosition(int arr[],int target,int n)
{
    int low=0,high = n-1;
    int answer = n;
    while(low<=high)
    {
        int mid = (high + low)/2;
        if(arr[mid]>=target)
        {
            answer = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return answer;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target;
    cin>>target;
    cout<<searchPosition(arr,target,n);

    return 0;
}
