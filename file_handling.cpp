#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("example.txt"); 
    if (!outFile) { 
        cerr << "Error creating file!" << endl;
        return 1; 
    }

    outFile << "Hello, World!" << endl;
    outFile << "This is a simple file I/O example." << endl;
    outFile << "C++ file handling is straightforward." << endl;

    outFile.close();

    ifstream inFile("example.txt"); 
    if (!inFile) { 
        cerr << "Error opening file!" << endl;
        return 1; 
    }

    string line;
    cout << "Contents of the file:" << endl;
    while (getline(inFile, line)) { 
        cout << line << endl;
    }

    inFile.close();

    return 0;
}