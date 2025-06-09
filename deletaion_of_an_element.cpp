#include<iostream>
using namespace std;
int main( )
 {
    int arr[100], n, pos;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter position to delete (1-based index): ";
    cin >> pos;

    if(pos<1 || pos>n)
    {
        cout << "Invalid position!" << endl;
    }
    else
    {
        for (int i=pos-1; i<n-1; i++)
        {
            arr[i] = arr[i+1];
        }
        n--;

        cout << "Array after deletion: ";
        for (int i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
