#include<iostream>
using namespace std;
//using two pointers-->
void reverseArray(int arr[],int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
//with two pointers and recursion
int rev_array(int arr[],int i,int j)
{
    //base case
    if(i>=j)
    {
        return 0;
    }
    swap(arr[i],arr[j]);
    rev_array(arr,i+1,j-1);
}
int main()
{
    int arr[5] ={5,4,3,2,0};
    //reverseArray(arr,5);
    rev_array(arr,0,5-1);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;
    }
}
