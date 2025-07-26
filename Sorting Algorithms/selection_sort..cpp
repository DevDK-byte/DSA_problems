#include<iostream>
using namespace std;

void selectionSort(int arr[],int n)
{
    int minimum,temp;
    for(int i=0; i<n-1; i++)
    {
        minimum = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[minimum])
            {
                 minimum =j;
            }
            temp = arr[minimum];
            arr[minimum] = arr[i];
            arr[i] = temp;        }
    }
}
int main()
{
    int arr[] = {13,46,24,52,20,9};
    int n = 6;
    selectionSort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
