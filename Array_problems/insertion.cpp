#include<iostream>
using namespace std;

void display(int arr[], int sizee)
{
    for(int i=0; i<sizee; i++)
    {
        cout<<arr[i]<<endl;
    }
}
int insertion(int arr[],int sizee,int element,int capacity,int index)
{
    if(sizee>=capacity)
    {
        return -1;
    }
    for(int i = sizee-1; i>=index; i--)
    {
        arr[i+1] = arr[i]; //shift towards right until desired index shifts
    }
    arr[index] = element;// insert that element into desired index
    return 0;
}
int main()
{
    int arr[50] = {1,3,5,7,8,9};
    int sizee = 6;
    int element;
    cin>>element;
    int index;
    cin>>index;
    insertion(arr,sizee,element,50,index);
    sizee++;
    display(arr,sizee);

}
