#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    int arr[] = {1,1,2,3,4,4,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int number;
    //brute force-->
    for(int i=0;i<n;i++)
    {
        number = arr[i];
        int counter=0;
        for(int j=0; j<n; j++)
        {
            if(arr[j]==number)
            {
                counter++;
            }
        }
        if(counter==1)
        {
            cout<<number<<endl;
        }
    }
    return 0;
}
