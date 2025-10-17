#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int main()
{
    int arr[] = {3,1,2,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum=0; int mod = 10000007;
    int minimum;
    for(int i=0;i<size;i++)
    {
        minimum = arr[i];
        for(int j=i;j<size;j++)
        {
            minimum = min(minimum,arr[j]);
            sum = (sum+minimum)%mod;
        }
    }
    cout<<sum<<endl;
}
