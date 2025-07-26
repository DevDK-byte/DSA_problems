#include<iostream>
using namespace std;
//linear search
/*bool linearsearch(int arr[],int sizee,int number)
{
    for(int i=0;i<sizee;i++)
    {
        if(arr[i]==number)
        {
            cout<<"the number is in index = "<<i+1<<endl;
            return true;
        }
    }
    return false;
}
int main()
{
   int arr[10] = {6,3,19,10,69,30};
   int target,sizee = 6;
   cin>>target;
   if(linearsearch(arr,sizee,target)==true)
   {
       cout<<"Target number found"<<endl;
   }
   else
   {
       cout<<"not found"<<endl;
   }
}*/

//Binary search-->
bool binarySearch(int arr[], int sizee, int element)
{
    int low = 0, high = sizee - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == element)
        {
            return true;
        }
        if(arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false; // element not found
}

int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 69};
    int target, sizee = 6;

    cout << "Enter element to search: ";
    cin >> target;

    if(binarySearch(arr, sizee, target) == true)
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}

