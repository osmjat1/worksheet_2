#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    float radius;

public:
    // Constructor to initialize radius
    Circle(float r) : radius(r) {}

    // Friend function declaration
    friend void compareTwoCircles(const Circle& c1, const Circle& c2);
};

// Friend function definition
void compareTwoCircles(const Circle& c1, const Circle& c2) {
    float area1 = M_PI * c1.radius * c1.radius;
    float area2 = M_PI * c2.radius * c2.radius;

    cout << "Circle 1 area: " << area1 << endl;
    cout << "Circle 2 area: " << area2 << endl;

    if (area1 > area2) {
        cout << "Circle 1 has larger area." << endl;
    } else if (area2 > area1) {
        cout << "Circle 2 has larger area." << endl;
    } else {
        cout << "Both circles have equal area." << endl;
    }
}

int main() {
    // Create two circle objects with radii 5.0 and 3.5
    Circle circle1(5.0f);
    Circle circle2(3.5f);

    // Compare them using friend function
    compareTwoCircles(circle1, circle2);

    return 0;
}
