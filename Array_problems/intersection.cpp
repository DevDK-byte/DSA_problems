#include<iostream>
using namespace std;

int main()
{
    int arr1[] = {1,2,2,3,4,5,6,7,7};
    int arr2[] = {2,3,3,5,6,6,7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int res[n1+n2];
    int k = 0;
    //brute force-->
   /* int j=0;
    int visited[n2] = {0}; //check if any element in array 2 is visited or not.
    for(int i=0; i<n1; i++)
    {
        for(j=0; j<n2; j++)
        {
            if(arr1[i]==arr2[j] && visited[j]==0)
            {
                res[k++] = arr1[i];
                visited[j] = 1;
                break;
            }
        }
        if(arr2[j]>arr1[i]) //works only for sorted array
            break;

    }*/
    //optimal(using two pointers)-->
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        else if(arr2[j]<arr1[i])
        {
            j++;
        }
        else
        {
            res[k++] = arr1[i];
            i++;
            j++;
        }
    }

    for(int i=0; i<k; i++)
    {
        cout<<res[i]<<endl;
    }
}
