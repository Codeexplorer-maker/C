#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    float a, b, c;

    bool isValidTriangle() {
        return (a > 0 && b > 0 && c > 0 &&
                (a + b > c) && (a + c > b) && (b + c > a));
    }

public:
    // Constructor
    Triangle(float side1, float side2, float side3) {
        a = side1;
        b = side2;
        c = side3;
    }

    // Function to calculate area using Heron's formula
    float area() {
        if (!isValidTriangle()) {
            cout << "Invalid triangle dimensions.\n";
            return 0;
        }

        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Overloaded function to calculate area of right-angled triangle
    float area(char type) {
        if (type == 'r' || type == 'R') {
            if (!isValidTriangle()) {
                cout << "Invalid triangle dimensions.\n";
                return 0;
            }

            // assuming 'c' is the hypotenuse for simplicity
            if (fabs(c * c - (a * a + b * b)) < 1e-6) {
                return 0.5 * a * b;
            } else {
                cout << "Not a right-angled triangle.\n";
                return 0;
            }
        }

        cout << "Unknown type for area calculation.\n";
        return 0;
    }
};

int main() {
    Triangle t1(3, 4, 5);
    cout << "Area using Heron's formula: " << t1.area() << endl;
    cout << "Area of right-angled triangle: " << t1.area('r') << endl;

    return 0;
}
