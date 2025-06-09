#include<iostream>
using namespace std;
int main( )
 {
    int arr[100], n, position, element;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert (0 to " << n << "): ";
    cin >> position;

    if(position<0 || position>n)
    {
        cout << "Invalid position!";
        return 1;
    }

    for(int i=n; i>position; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[position] = element;
    n++;

    cout << "Array after insertion: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

