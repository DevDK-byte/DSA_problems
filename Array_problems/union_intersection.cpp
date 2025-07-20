#include<iostream>
using namespace std;
bool exists(int arr[],int sizee, int value)
{
    for(int i=0; i<sizee;i++)
    {
        if(arr[i]==value)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr1[] = {1,2,0,0,3,0,3,4,0,4,5};
    int arr2[] = {1,2,3,0,4,5,6,7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    //union -->brute force
    /*int result[n1+n2];
    int k=0;//index for result
    for(int i=0; i<n1; i++)
    {
        if(!exists(result,k,arr1[i]))
        {
            result[k++] = arr1[i];
        }
    }
    for(int i=0; i<n2; i++)
    {
        if(!exists(result,k,arr2[i]))
        {
            result[k++] = arr2[i];
        }
    }
    for(int i=0; i<k; i++)
    {
        cout<<result[i]<<endl;
    }*/
    //optimal  approach using two pointer-->

    int i = 0, j = 0, k = 0;
    int un[n1 + n2];

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            if (k == 0 || un[k - 1] != arr1[i])
                un[k++] = arr1[i];
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (k == 0 || un[k - 1] != arr2[j])
                un[k++] = arr2[j];
            j++;
        }
        else // arr1[i] == arr2[j]
        {
            if (k == 0 || un[k - 1] != arr1[i])
                un[k++] = arr1[i];
            i++;
            j++;
        }
    }

    while (i < n1)
    {
        if (k == 0 || un[k - 1] != arr1[i])
            un[k++] = arr1[i];
        i++;
    }

    while (j < n2)
    {
        if (k == 0 || un[k - 1] != arr2[j])
            un[k++] = arr2[j];
        j++;
    }

    // Print the union array
    for (int x = 0; x < k; x++)
        cout << un[x] << " ";
    cout << endl;

    return 0;
}


