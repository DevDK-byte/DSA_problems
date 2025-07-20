#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,0,0,3,0,3,4,0,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[11];
    //brute force-->
    /*
    int j = 0; // Index for temp

    // Copy non-zero elements to temp[]
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }

    // Fill the rest of temp[] with 0s
    while(j < n)
    {
        temp[j] = 0;
        j++;
    }

    // Copy temp[] back to arr[]
    for(int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    } */

     //optimal solution using two pointers-->
     int j=-1;
     for(int i=0;i<n; i++)
     {
         if(arr[i]==0)
         {
             j= i;
             break;
         }
     }
     for(int i=j+1; i<n; i++)
     {
         if(arr[i]!=0)
         {
             swap(arr[i],arr[j]);
             j++;
         }
     }
    // Print the result
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
