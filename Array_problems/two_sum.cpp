#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int number;
    cin >> number;
    //brute force-->
    /*
    int i,j;
    bool found = false;
    for( i=0; i<n; i++) {
        for(j=i+1; j<n; j++) { // avoid checking same pair twice
           if(i==j){continue;}
           if(arr[i] + arr[j] == number) {
                found = true;
                break;
            }
        }
        if(found) break;
    }

    if(found) {
            cout << "Yes, indexes are = " << i << " " << j << endl;
    }
    else
    {
        cout << "No such pair found." << endl;
    }
    */
    //optimal solution-->
    int left =0;
    int right = n-1;
    sort(arr, arr+n);
    bool yes = false;
    while(left<right)
    {
        int sum = arr[left] + arr[right];
        if(sum==number)
        {
            cout<<"yes"<<endl;
            yes = true;
            break;
        }
        else if(sum>number){
                right--;
        }
        else
        {
            left++;
        }
    }
    if(!yes)
    {
        cout<<"no"<<endl;
    }

    return 0;
}
