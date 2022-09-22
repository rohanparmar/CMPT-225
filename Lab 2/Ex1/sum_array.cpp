#include<iostream>

using namespace std;

int sumArray(int arr[], unsigned int arrSize)
{
    int sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int * arr = NULL;        // Pointer variable, can point to an array of int
    unsigned int arrSize = 0;     // Variable to hold the number of cells in the array - Right now, initialized to 0 - User-defined

    // Get the array size from the user using cin:
    // cin ... for you to complete!
    cout << "Enter the size of the array: "<<endl;
    cin >> arrSize;

    arr = new int[arrSize]; // Create a heap-allocated (dynamically allocated) array


    // Get the array elements from the user using cin:
    // cin ... for you to complete!
    cout << "Enter the elements of the array: "<<endl;
    
    for (int i = 0; i < arrSize; i++)
    {
        cout<<"Element "<<i+1<<": ";   
        cin >> arr[i];
        cout<<endl;
    }



    if ( arr != NULL )
    {
        // Get the array elements from the user using cin:
        cout << "The sum of the array elements is: " << sumArray(arr, arrSize) << endl;
        delete[] arr; // Deallocate the array
    }
    else
    {
        cout << "Error allocating memory for the array!" << endl;
    }
    // make sure the pointer the operator new returned is valid 
}