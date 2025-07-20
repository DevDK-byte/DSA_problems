#include<iostream>
using namespace std;

void bubblesort(int arr[],int n)
{
    int temp;
     for(int pass=n-1; pass>=0; pass++)
     {
         for(int i=0; i<pass; i++)
         {
             if(arr[i]>arr[i+1])
             {
                 temp = arr[i];
                 arr[i] = arr[i+1];
                 arr[i+1] = temp;
             }
         }
     }
}
int main()
{
    int arr[] = {2,16,3,15,69,43};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
