#include<iostream>
using namespace std;

int search_rotated(int arr[],int target,int n)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[low]<=arr[mid])//identifying if left half is sorted
        {
            if(arr[low]<=target && target<=arr[mid])//means Target number lies within left half
            {
                high= mid-1;//check only left half
            }
            else
            {
                low = mid+1;
            }
        }
        else //right half is sorted
        {
            if(arr[mid]<=target && target<=arr[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return -1; //if element not found
}
int main()
{
    int arr[] = {7,8,9,1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int number;
    cin>>number;
    cout<<search_rotated(arr,number,n)<<endl;

    return 0;
}
