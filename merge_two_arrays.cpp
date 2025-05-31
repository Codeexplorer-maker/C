#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int size1, int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge the arrays
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1 (if any)
    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2 (if any)
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create an array to hold the merged result
    int merged[size1 + size2];

    mergeArrays(arr1, arr2, size1, size2, merged);

    // Output the merged array
    cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}
