#include<iostream>
#include<stack>
using namespace std;
int trappingWater(int arr[], int n)
{
    int leftmax =0, rightmax=0;
    int total= 0;
    //two pointers-->optimal approach
    int l=0,r=n-1;
    while(l<r)
    {
        if(arr[l]<=arr[r]) //smallest is on the left fs
        {
            if(leftmax>arr[l])
            {
                total += leftmax-arr[l];
            }
            else
            {
                leftmax = arr[l];
            }
            l = l+1;
        }
        else
        {
            if(rightmax>arr[r])//bigger is on the right fs
            {
                total += rightmax - arr[r];
            }
            else
            {
                rightmax = arr[r];
            }
            r = r-1; //back iteration from left side
        }
    }
return total;
}

int main()
{
    int arr[] ={0,1,0,2,1,0,1,3,2,1,2,1};
    int sizee = sizeof(arr)/sizeof(arr[0]);
    int answer = trappingWater(arr,sizee);
    cout<<"Total units of water trapped = "<<answer<<endl;

    return 0;
}
