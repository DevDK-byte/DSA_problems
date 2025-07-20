#include<iostream>
using namespace std;


int main()
{
    int arr[] = {1,4,68,32,29,58,42};
    int n= sizeof(arr)/sizeof(arr[0]);
    //left rotate by one places -->
   /* int temp = arr[0];
    for(int i=1; i<n; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }*/

    //left rotate by k places--->
    int d;
    cin>>d;
    d = d%n;
    int temp[d];
    //insert 1st k elements into temp array-->
    for(int i=0; i<d;i++)
    {
        temp[i] = arr[i];
    }
    //shifting k elements to left-->
    for(int i= d; i<n;i++)
    {
        arr[i-d] = arr[i];
    }
    int j=0;
    for(int i=(n-d); i<n; i++)
    {
        arr[i] = temp[j];
        j++;
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
