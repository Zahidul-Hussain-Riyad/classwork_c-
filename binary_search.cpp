#include<iostream>
#include<algorithm>
using namespace std;
int main( )
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements of the array : ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    sort(a, a + n);

    int left = 0, right = n - 1;
    bool found = false;

    while(left <= right){
        int mid = (left+right)/2;
        if(a[mid] == value){
            cout << "Element found at index (after sorting): " << mid << endl;
            found = true;
            break;
        }
        else if(a[mid]<value){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

    if(!found){
        cout << "Element not found." << endl;
    }

    return 0;
}
