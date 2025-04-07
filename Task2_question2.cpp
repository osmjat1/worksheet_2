#include <iostream>
using namespace std;

class MaxFinder {
private:
    // Private data members (not strictly necessary here but included for OOP structure)
    int intResult;
    float floatResult;

public:
    // Constructor (default, not used for much in this case)
    MaxFinder() : intResult(0), floatResult(0.0) {}

    // 1. Find maximum between two integers
    int findMax(int a, int b) {
        intResult = (a > b) ? a : b;
        return intResult;
    }

    // 2. Find maximum between two floating-point numbers
    float findMax(float a, float b) {
        floatResult = (a > b) ? a : b;
        return floatResult;
    }

    // 3. Find maximum among three integers
    int findMax(int a, int b, int c) {
        intResult = a;
        if (b > intResult) intResult = b;
        if (c > intResult) intResult = c;
        return intResult;
    }

    // 4. Find maximum between an integer and a float
    float findMax(int a, float b) {
        floatResult = (a > b) ? a : b; // Implicit conversion of int to float
        return floatResult;
    }

    // Function to display results (demonstrating OOP encapsulation)
    void displayResult(int a, int b) {
        cout << "Max of " << a << " and " << b << " is: "
             << findMax(a, b) << endl;
    }

    void displayResult(float a, float b) {
        cout << "Max of " << a << " and " << b << " is: "
             << findMax(a, b) << endl;
    }

    void displayResult(int a, int b, int c) {
        cout << "Max of " << a << ", " << b << ", and " << c << " is: "
             << findMax(a, b, c) << endl;
    }

    void displayResult(int a, float b) {
        cout << "Max of " << a << " and " << b << " is: "
             << findMax(a, b) << endl;
    }
};

int main() {
    // Create an object of MaxFinder class
    MaxFinder finder;

    // Test case 1: Two integers
    int int1 = 5, int2 = 8;
    finder.displayResult(int1, int2);

    // Test case 2: Two floats
    float float1 = 3.14, float2 = 2.718;
    finder.displayResult(float1, float2);

    // Test case 3: Three integers
    int int3 = 10, int4 = 4, int5 = 7;
    finder.displayResult(int3, int4, int5);

    // Test case 4: Integer and float
    int int6 = 9;
    float float3 = 9.5;
    finder.displayResult(int6, float3);

    return 0;
}
