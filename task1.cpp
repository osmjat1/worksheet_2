#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks[3];

public:
    // Function to accept student details
    void acceptDetails() {
        cout << "Enter student name: ";
        cin >> name;

        for (int i = 0; i < 3; i++) {
            cout << "Enter mark for subject " << (i + 1) << ": ";
            cin >> marks[i];

            // Validate marks
            if (marks[i] < 0 || marks[i] > 100) {
                cout << "Invalid mark! Marks must be between 0 and 100." << endl;

            }
        }
    }

    // Function to calculate total marks
    void calculateTotal() {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        cout << "Total marks: " << total << endl;
    }

    // Function to calculate average marks
    void calculateAverage() {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        double average = total / 3.0;
        cout << "Average marks: " << average << endl;
    }

    // Function to calculate and display grade
    void calculateGrade() {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        double average = total / 3.0;

        char grade;
        if (average >= 90) {
            grade = 'A';
        } else if (average >= 80) {
            grade = 'B';
        } else if (average >= 70) {
            grade = 'C';
        } else if (average >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
        cout << "Grade: " << grade << endl;
    }

    // Function to display all details
    void displayDetails() {
        cout << "Student Name: \n" << name << endl;

    }
};

int main() {
    Student s1;
    s1.acceptDetails();
    s1.calculateTotal();
    s1.calculateAverage();
    s1.calculateGrade();
    s1.displayDetails();
    return 0;
}
