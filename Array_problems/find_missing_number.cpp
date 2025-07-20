#include<iostream>
using namespace std;
//brute force
/*
int missing(int arr[],int n)
{
    for(int i=1;i<=n; i++)//for numbers 1 to n
    {
        int flag = 0; //let innitially not found.
        for(int j=0; j<n-1; j++)
        {
            if(arr[j]==i)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return i;
        }
    }
    return -1;
}*/
int main()
{
    int arr[] = {1, 2, 4, 5, 6}; // missing 6
    int n = 6;

    // Optimal (using series sum)
    /*int sum = n * (n + 1) / 2;
    int s2 = 0;

    for(int i = 0; i < n - 1; i++) // array size is n-1
    {
        s2 += arr[i];
    }

    int new_sum = sum - s2;

    cout << "Expected Sum: " << sum << endl;
    cout << "Actual Sum: " << s2 << endl;
    cout << "Missing number: " << new_sum << endl;
    */
    //optimal using xor-->
    int xor1 = 0;
    for(int i=1; i<=n; i++)//for arraywith all elements
    {
        xor1 ^= i;
    }
    int xor2 = 0;
    for(int i=0; i<n-1; i++)//for array with missing element
    {
        xor2 ^= i;
    }
    int answer = xor1^xor2;
    cout<<answer<<endl;
    return 0;
}

