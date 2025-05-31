#include <iostream>

using namespace std;

// Function to show the address of each character
void showAddress(char *str) {
    cout << "Character addresses in the string:\n";
    while (*str) {
        cout << *str << " - " << (void *)str << endl;
        str++;
    }
}

// Function to concatenate two strings manually
void concatenate(char *str1, char *str2, char *result) {
    while (*str1) {
        *result = *str1;
        result++;
        str1++;
    }
    while (*str2) {
        *result = *str2;
        result++;
        str2++;
    }
    *result = '\0';
}

// Function to compare two strings manually
int compare(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) return (*str1 - *str2);
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

// Function to find the length of a string using pointers
int length(char *str) {
    int len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}

// Function to convert lowercase characters to uppercase
void toUpperCase(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        str++;
    }
}

// Function to reverse a string manually
void reverse(char *str) {
    int len = length(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to insert a string at a specific position
void insertString(char *str1, char *str2, int pos, char *result) {
    int i = 0, j = 0;
    while (i < pos && str1[i]) {
        result[i] = str1[i];
        i++;
    }
    while (str2[j]) {
        result[i] = str2[j];
        i++; j++;
    }
    while (str1[pos]) {
        result[i] = str1[pos];
        i++; pos++;
    }
    result[i] = '\0';
}

int main() {
    char str1[100], str2[100], result[200];
    int choice, pos;

    do {
        cout << "\nMENU\n";
        cout << "1. Show address of each character\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of the string\n";
        cout << "5. Convert to uppercase\n";
        cout << "6. Reverse the string\n";
        cout << "7. Insert a string in another at a position\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character from previous input

        switch (choice) {
            case 1:
                cout << "Enter the string: ";
                cin.getline(str1, 100);
                showAddress(str1);
                break;

            case 2:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                concatenate(str1, str2, result);
                cout << "Concatenated string: " << result << endl;
                break;

            case 3:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                if (compare(str1, str2) == 0)
                    cout << "Strings are equal\n";
                else
                    cout << "Strings are not equal\n";
                break;

            case 4:
                cout << "Enter the string: ";
                cin.getline(str1, 100);
                cout << "Length of the string: " << length(str1) << endl;
                break;

            case 5:
                cout << "Enter the string: ";
                cin.getline(str1, 100);
                toUpperCase(str1);
                cout << "Uppercase string: " << str1 << endl;
                break;

            case 6:
                cout << "Enter the string: ";
                cin.getline(str1, 100);
                reverse(str1);
                cout << "Reversed string: " << str1 << endl;
                break;

            case 7:
                cout << "Enter the first string: ";
                cin.getline(str1, 100);
                cout << "Enter the second string: ";
                cin.getline(str2, 100);
                cout << "Enter position to insert: ";
                cin >> pos;
                cin.ignore();
                if (pos >= 0 && pos <= length(str1)) {
                    insertString(str1, str2, pos, result);
                    cout << "Resulting string: " << result << endl;
                } else {
                    cout << "Invalid position!\n";
                }
                break;

            case 8:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
