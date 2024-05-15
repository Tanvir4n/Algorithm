#include <iostream>
using namespace std;

double squareRoot(double x, double precision) {
    if (x == 0.0) return 0.0;
    
    double left = 0.0;
    double right = max(1.0, x); // Start with the maximum of 1 and x

    while (right - left > precision) {
        double mid = left + (right - left) / 2;
        double square = mid * mid;

        if (square == x)
            return mid;
        else if (square < x)
            left = mid; // Move to the right half
        else
            right = mid; // Move to the left half
    }

    return (left + right) / 2; // Return the approximate square root
}

int main() {
    double x, precision;

    cout << "Enter a number to calculate its square root: ";
    cin >> x;

    cout << "Enter the precision (e.g., 0.001): ";
    cin >> precision;

    double result = squareRoot(x, precision);

    cout << "Square root of " << x << " with precision " << precision << " is approximately: " << result << endl;

    return 0;
}
