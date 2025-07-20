#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int issorted = 1;
    for(int pass = n-1; pass>=0 && issorted; pass--)
    {
        issorted = 0;
        for(int i=0; i< pass; i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(arr[i],arr[i+1]);
                issorted=1;
            }
        }
    }
}

int main()
{
    int arr[] = {3, 1, 56, 29, 34, 55, 67,20};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
