#include <iostream>

using namespace std;

class Matrix {
private:
    int data[10][10];
    int rows, cols;

public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {}

    void input() {
        cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(const Matrix &other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix multiply(const Matrix &other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

int main() {
    int choice;
    do {
        cout << "\nMatrix Operations:\n1. Sum\n2. Product\n3. Transpose\n4. Exit\nEnter your choice: ";
        cin >> choice;
        if (choice == 1) {
            int r, c;
            cout << "Enter rows and columns: ";
            cin >> r >> c;
            Matrix A(r, c), B(r, c);
            A.input(); B.input();
            A.add(B).display();
        } else if (choice == 2) {
            int r1, c1, r2, c2;
            cout << "Enter rows and columns for first matrix: ";
            cin >> r1 >> c1;
            cout << "Enter rows and columns for second matrix: ";
            cin >> r2 >> c2;
            if (c1 != r2) {
                cout << "Error: Incompatible matrices for multiplication!\n";
                continue;
            }
            Matrix A(r1, c1), B(r2, c2);
            A.input(); B.input();
            A.multiply(B).display();
        } else if (choice == 3) {
            int r, c;
            cout << "Enter rows and columns: ";
            cin >> r >> c;
            Matrix A(r, c);
            A.input();
            A.transpose().display();
        }
    } while (choice != 4);
    return 0;
}
