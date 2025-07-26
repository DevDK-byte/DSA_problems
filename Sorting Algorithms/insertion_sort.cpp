#include<iostream>
using namespace std;

void insertionSort(int arr[],int n)
{
    int temp;
    for(int i=0; i<n; i++)
    {
        int j=i;
        while(arr[j-1]>arr[j] && j>0)
        {
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
int main()
{
    int arr[] = {34,52,13,23,12,5,6,10};
    int sizee = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,sizee);
    for(int i=0; i<sizee; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}

