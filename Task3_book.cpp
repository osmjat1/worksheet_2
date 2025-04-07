#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Function to write book titles to a binary file
void writeToFile(const string& book, string titles[], int numBooks) {
    ofstream file("book.txt", ios::binary);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    for (int i = 0; i < numBooks; i++) {
        int length = titles[i].length();
        file.write(reinterpret_cast<char*>(&length), sizeof(length));  // Write the length of the title
        file.write(titles[i].c_str(), length);  // Write the title itself
    }
    file.close();
}

// Function to read and display book titles from the binary file
bool searchInFile(const string& book, const string& searchTitle) {
    ifstream file("book.txt", ios::binary);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return false;
    }

    bool found = false;
    while (file) {
        int length;
        file.read(reinterpret_cast<char*>(&length), sizeof(length));  // Read the length of the title
        if (file.eof()) break;

        char* buffer = new char[length + 1];  // Create buffer to store title
        file.read(buffer, length);  // Read the title itself
        buffer[length] = '\0';  // Null-terminate the string

        if (searchTitle == buffer) {
            found = true;
            cout << "Title found: " << buffer << endl;
        }

        delete[] buffer;
    }

    file.close();
    return found;
}

int main() {
    const int NUM_BOOKS = 10;
    string titles[NUM_BOOKS];

    // Read book titles from user
    cout << "Enter 10 book titles:" << endl;
    for (int i = 0; i < NUM_BOOKS; i++) {
        cout << "Title " << i + 1 << ": ";
        getline(cin, titles[i]);
    }

    // Get file name from user
    string bookFileName;
    cout << "Enter filename to save the books: ";
    cin >> bookFileName;

    // Write titles to the binary file
    writeToFile(bookFileName, titles, NUM_BOOKS);

    // Allow the user to search for a title
    cin.ignore();  // To clear the input buffer
    string searchTitle;
    cout << "Enter a title to search: ";
    getline(cin, searchTitle);

    // Search in the file
    if (!searchInFile(bookFileName, searchTitle)) {
        cout << "Title not found!" << endl;
    }

    return 0;
}
