#include<iostream>
#include<math.h>
using namespace std;


int main()
{
    int arr[] = {1,1,0,1,1,1,0,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maximum = 0; int counter =0;

    for(int i=0; i<n; i++)
    {
        if(arr[i]==1)
        {
            counter++;
            maximum = max(maximum,counter);
        }
        else
            counter =0;
    }

cout<<maximum<<endl;
}
