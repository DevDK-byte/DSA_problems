#include<iostream>
using namespace std;

/*int ceil(int arr[],int target,int n)
{
    int low=0,high = n-1;
    int answer = -1; //-1 means no answer found
    while(low<=high)
    {
        int mid = (high + low)/2;
        if(arr[mid]>=target)
        {
            answer = arr[mid];
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    if(answer==-1)
    {
        return -1; //ceil doesn't exist
    }
    return answer
}*/

int floor(int arr[],int target,int n)
{
    int answer = -1;
    int low= 0,high = n-1;
     while(low<=high)
    {
        int mid = (high + low)/2;
        if(arr[mid]<=target)
        {
            answer = arr[mid]; //possible floor
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return answer;
}
int main()
{
    int arr[] = {1,2,4,5,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target;
    cin>>target;
   // cout<<ceil(arr,target,n);
    cout<<floor(arr,target,n);

    return 0;
}
