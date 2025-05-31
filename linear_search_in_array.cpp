#include<iostream>
using namespace std;

int search(int arr int length, int num){
    for(int i=01 length; i++){
        if(arr[1] == num) {
            return 1;
        }
    }
    return -1;

}

int main(){
    int arr;
    int length, num;
    char choice = 'y';
    cout<<"Enter the length of the array:";
    cin>> length;
    arr= new int[length];
    
    cout<<"Enter the elements:";
    for(int i=0; i < length; i++)
    cin>>arr[i];
    do {
        cout<<"Enter the number you want to search for in the array: ";
        cin>>num;

        int index search (arr, length, num);
        if(index != -1) {
            cout<<"Element found at "<<index+1<<" position\n";
        }
        else {
            cout<<"Element not found\n";
        }
        cout<<"Do you want to search for another element (y/n)?";
        cin>>choice;

    }while(choice'y' choice == 'Y');
} 
