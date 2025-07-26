#include<iostream>
using namespace std;

int Merge(int arr[],int low,int mid,int high)
{
    int temp[high-low+1];//temp array including (low to mid) + (mid+1 to high)
    int tempindex = 0; //index for temp array
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp[tempindex] = arr[left];
            left++;
        }
        else
        {
            temp[tempindex] = arr[right];
            right++;
        }
        tempindex++;
    }
    //copy remaining elements from left part
    while(left<=mid)
    {
        temp[tempindex] = arr[left];
        left++;
        tempindex++;
    }
    //copy remaining elements from right part
    while(right<=high)
    {
        temp[tempindex] = arr[right];
        right++;
        tempindex++;
    }
//copying all elements from temp array to real array back
for(int i=low; i<=high; i++)
{
    arr[i] = temp[i-low];
}
}
void mergesort(int arr[],int low, int high)
{
    if(low>=high) //base case for sorting
    {
        return;
    }
    int mid = (high+low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}
int main()
{
    int arr[] = {3,1,2,4,1,5,2,6,4};
    int sizee = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,sizee-1);
    for(int i=0; i<sizee;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}


