//S = 1 - 1/2^2 + 1/3^3 - 1/4^4 + ... + 1/n^n

#include <iostream>
#include <cmath>  // For pow function

using namespace std;

int main(int argc, char* argv[]) {
    int n;
    
    // Check if n is passed as a command line argument
    if (argc > 1) {
        n = atoi(argv[1]);  // Convert command line argument to integer
    } else {
        // Prompt the user to input the value of n
        cout << "Enter the number of terms (n): ";
        cin >> n;
    }

    double sum = 0.0;

    // Calculate the sum of the series
    for (int i = 1; i <= n; ++i) {
        double term = 1.0 / pow(i, i);  // 1/i^i
        if (i % 2 == 0) {
            term = -term;  // Alternate the signs
        }
        sum += term;
    }

    // Output the result
    cout << "The sum of the first " << n << " terms of the series is: " << sum << endl;

    return 0;
}