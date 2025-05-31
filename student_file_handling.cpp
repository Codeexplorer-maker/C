#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int rollNo;
    string name;
    string className;
    int year;
    float totalMarks;

public:
    void input() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Class: ";
        getline(cin, className);
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Total Marks: ";
        cin >> totalMarks;
    }

    void display() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nClass: " << className;
        cout << "\nYear: " << year;
        cout << "\nTotal Marks: " << totalMarks << "\n";
    }
};

int main() {
    Student students[5];

    // Writing to file
    ofstream outFile("students.dat", ios::binary);
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].input();
        outFile.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }
    outFile.close();

    // Reading from file
    Student temp;
    ifstream inFile("students.dat", ios::binary);
    cout << "\n--- Student Details from File ---\n";
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        temp.display();
    }
    inFile.close();

    return 0;
}
