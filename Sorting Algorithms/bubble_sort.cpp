#include<iostream>
#include<algorithm>
using namespace std;

/*void bubbleSort(int arr[],int n)
{
    int temp;int swapped = 1;
    for(int pass=n-1; pass>=0 && swapped; pass--)
    {
        swapped=0;
        for(int i=0; i<pass; i++)
        {
            if(arr[i]>arr[i+1])
            {
                //swap
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = 1;
            }
        }
    }
}*/
void bubbleSort(int arr[],int n)
{
    int pass = 1;
    while(true){
    bool swapped = false;
    int u = n-pass; //calculates each pass iteration
    for(int i=0; i<u; i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
            swapped = true;
        }
    }
    pass++;
    if(!swapped || pass>n-1) //if no swap occur and pass exceeds
    {
        break;
    }
}
}
int main()
{
    int arr[] = {34,52,13,23,12,5,6,10};
    int sizee = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,sizee);
    for(int i=0; i<sizee; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}

