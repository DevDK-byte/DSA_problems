#include<iostream>
using namespace std;

/*int lowerBound(int arr[],int number, int n){
    int ans = -1;
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = (high+low)/2;
        if(arr[mid]>=number)
        {
            ans = arr[mid];
            high = mid-1;
        }
        else
        {
            low= mid+1;
        }
    }
    return ans;
}
int upperBound(int arr[],int number,int n){
int ans = -1;
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = (high+low)/2;
        if(arr[mid]>number)
        {
            ans = arr[mid];
            high = mid-1;
        }
        else
        {
            low= mid+1;
        }
    }
    return ans;
}
int firstANDlast(int arr[],int number,int n)
{
    int lb= lowerBound(arr,number,n);
    if(lb==n || arr[lb]!=n)//either lowerbound is pointing to hypothetical index or at a index which doesnt match value of number
    {
        cout<<"-1  -1"<<endl;
    }
int first = lb;
int last = upperBound(arr,number,n)-1;
return {first,last}; //USE VECTOR FOR RETURNING LIKE THIS

}*/
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

int main()
{
    int arr[] = {2,3,6,8,8,8,11,13};
    int n = sizeof(arr)/sizeof(arr[0]);
   // int first = -1,last=-1;
    int number;
    cin>>number;
    //brute force-->
    /*for(int i=0;i<n;i++)
    {
        if(arr[i]==number)
        {
            if(first==-1)
            {
                first = i;
            }
            last = i;
        }
    } */
    //optimal solution-->
    //cout<<firstANDlast<<endl;
    cout<<firstOccurrence(arr,number,n)<<" "<<lastOccurrence(arr,number,n)<<endl;
    return 0;
}
