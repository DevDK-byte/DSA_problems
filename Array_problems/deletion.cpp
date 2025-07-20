#include<iostream>
using namespace std;

void display(int arr[], int sizee)
{
    for(int i=0; i<sizee; i++)
    {
        cout<<arr[i]<<endl;
    }
}
void deletion(int arr[], int sizee, int index)
{
    for(int i=index; i<=sizee-2; i++)
    {
        arr[i] = arr[i+1];
    }
}
int main()
{
    int arr[50] = {2,12,3,4,78};
    int sizee = 5;
    int index;
    cin>>index;
    display(arr,sizee);
    deletion(arr,sizee,index);
    sizee--;
    display(arr,sizee);
}
