#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int &n) {
    int temp[n], j = 0;
    
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int k = 0; k < j; k++) {
            if (arr[i] == temp[k]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[j++] = arr[i];
        }
    }
    
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }
    n = j;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    removeDuplicates(arr, n);
    
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
