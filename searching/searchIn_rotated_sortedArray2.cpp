#include<iostream>
using namespace std;

bool search_rotated(int arr[],int number,int n)
{
    int low=0,high =n-1;
    while(low<=high)
    {
        int mid = (high+low)/2;
        if(arr[mid]==number)
        {
            return true;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high])//shrink left and right search spaces
        {
            low +=1;
            high -=1;
            continue; //continue shrinking until condition is false
        }
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=number && number<=arr[mid])
            {
                high = mid-1; //eliminate right search space
            }
            else
            {
                low = mid+1; //eliminate left search space
            }
        }
        else
        {
            if(arr[mid]<=number && number<=arr[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return false;
}
int main()
{
    int arr[] = {3,1,2,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int number;
    cin>>number;

    if(search_rotated(arr,number,n)==true)
    {
        cout<<"yes found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }

    return 0;
}
