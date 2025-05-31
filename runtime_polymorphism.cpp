
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
private:
    string course;
    int marks;
    int year;
public:
    Student(string n, string c, int m, int y) : Person(n), course(c), marks(m), year(y) {}
    void display() override {
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

class Employee : public Person {
private:
    string department;
    float salary;
public:
    Employee(string n, string d, float s) : Person(n), department(d), salary(s) {}
    void display() override {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Person* p;

    Student s("Sakshi", "CS", 90, 2);
    Employee e("Ankit", "IT", 50000.0);

    p = &s;
    p->display();  // Runtime polymorphism

    cout << endl;

    p = &e;
    p->display();  // Runtime polymorphism

    return 0;
}
