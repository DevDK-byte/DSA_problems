#include<iostream>
#include<stdlib.h>
using namespace std;
//creating dynamic array

class myArray //ADT
{
    public:
    int total_size;
    int used_size;
    int *ptr;//points to first memory block
};
void createArray(myArray* a,int tsize,int usedsize)
{
    (*a).total_size = tsize;
    (*a).used_size = usedsize;
    (*a).ptr = (int *) malloc(tsize*sizeof(int));//dynamically allocates memory on the heap to store tsize amount of integers;
}
void setvalue(myArray *a) //set values for aray
{
    for(int i=0; i<(*a).used_size; i++)
    {
        cin>> (*a).ptr[i];
    }
}
void insertAtIndex(myArray *a, int index, int value)
{
    if(a->used_size >= a->total_size)
    {
        cout << "Error: Cannot insert, array is full!" << endl;
        return;
    }

    if(index < 0 || index > a->used_size)
    {
        cout << "Error: Invalid index!" << endl;
        return;
    }

    // Shift elements to the right
    for(int i = a->used_size - 1; i >= index; i--)
    {
        a->ptr[i + 1] = a->ptr[i];
    }

    a->ptr[index] = value; // Insert value at index
    a->used_size++;        // Increase used size
}

void show(myArray *a)//print elements in array(used)
{
    for(int i=0; i<(*a).used_size;i++)
    {
        cout<<(*a).ptr[i]<<endl;
    }
}
int main()
{
    myArray marks;
    createArray(&marks,6,3);
    setvalue(&marks);
    insertAtIndex(&marks,2,69);
    show(&marks);
    return 0;
}













