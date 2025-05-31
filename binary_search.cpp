/*
Write a program to search a given element in a set of N numbers using Binary Search

a. with recursion

b. without recursion.
*/

#include <iostream>
using namespace std;

int searchwith(int lst[], int n, int start, int end){
    if (start > end){
        return -1;
    }
    int mid = (start + end)/2;
    if(lst[mid]==n){
        return mid;
    }
    else if(lst[mid] > n){
        end = mid-1;
        return searchwith(lst, n, start, end);
    }
    else{
        start = mid +1;
        return searchwith(lst, n, start, end);
    }
}

int search(int lst[], int n, int len){
    int start = 0, end = len - 1;
    while(start <= end){
        int mid= (start + end)/2;
        
        if(lst[mid] == n){
            return mid;
        }
        else if(lst[mid]< n){
            start= mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return -1;
}

int main(){
    int lst [10]= {1,2,3,4,5,6,7,8,9,10};
    int n;

    cout<< "the number to be searched: ";
    cin>> n;

    int len = sizeof(lst)/ sizeof(lst[0]);

    int found = search(lst,n,len);

    cout<< "binary search without recurrsion"<< endl;
    if(found == -1){
        cout<< "does not exists int the set "<< endl;
    }
    else{
        cout<<"element found at : "<< found << endl;
    }

    int start = 0, end = len - 1;
    int found_with = searchwith(lst, n , start , end);

    cout << "binary search with recurrsion" << endl;
    if (found == -1){
        cout << "does not exists in the set";
    }
    else{
        cout << "element found at : "<< found;
    }
    return 0;
}