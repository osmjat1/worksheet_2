#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

struct Student {
    int roll;
    string name;
    int marks;

    // Method to display student record
    void display() const {
        cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

// Function to read students from a file
vector<Student> readFromFile(const string& filename) {
    vector<Student> students;
    ifstream file("student.txt");

    if (!file) {
        cerr << "Error opening file!" << endl;
        return students;
    }

    Student student;
    while (file >> student.roll >> ws) {
        getline(file, student.name);  // Read the name which may contain spaces
        file >> student.marks;

        try {
            if (student.marks < 0 || student.marks > 100) {
                throw out_of_range("Marks should be between 0 and 100.");
            }
            students.push_back(student);
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << " for student with roll number " << student.roll << endl;
        }
    }

    file.close();
    return students;
}

// Function to add a new student
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter roll number: ";
    cin >> newStudent.roll;
    cin.ignore();  // Ignore the newline character

    cout << "Enter name: ";
    getline(cin, newStudent.name);

    cout << "Enter marks: ";
    cin >> newStudent.marks;

    try {
        if (newStudent.marks < 0 || newStudent.marks > 100) {
            throw out_of_range("Marks should be between 0 and 100.");
        }
        students.push_back(newStudent);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

// Function to save students back to the file
void saveToFile(const string& filename, const vector<Student>& students) {
    ofstream file("student.txt");

    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    for (const auto& student : students) {
        file << student.roll << endl;
        file << student.name << endl;
        file << student.marks << endl;
    }

    file.close();
}

int main() {
    string filename = "students.txt"; // You can change this to any file name

    // Read existing student records from the file
    vector<Student> students = readFromFile(filename);

    // Display the students
    cout << "Existing Student Records:" << endl;
    for (const auto& student : students) {
        student.display();
    }

    // Allow the user to add a new student record
    char choice;
    cout << "Do you want to add a new student? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        addStudent(students);
    }

    // Save the modified student records back to the file
    saveToFile("student.txt", students);

    cout << "Updated Student Records:" << endl;
    for (const auto& student : students) {
        student.display();
    }

    return 0;
}
