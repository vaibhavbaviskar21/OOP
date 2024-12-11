#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

public:
    Student() : rollNumber(0), division('A') {}

    Student(string n, int r, string c, char d, string dob, string bg, string addr, string tel, string dl)
        : name(n), rollNumber(r), className(c), division(d), dateOfBirth(dob), bloodGroup(bg),
          contactAddress(addr), telephoneNumber(tel), drivingLicenseNo(dl) {}

    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        className = other.className;
        division = other.division;
        dateOfBirth = other.dateOfBirth;
        bloodGroup = other.bloodGroup;
        contactAddress = other.contactAddress;
        telephoneNumber = other.telephoneNumber;
        drivingLicenseNo = other.drivingLicenseNo;
    }

    ~Student() {
    }

    static void displayTotalStudents(int total) {
        cout << "Total Students: " << total << endl;
    }

    inline void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
    }

    friend void inputStudentData(Student& student);
};

void inputStudentData(Student& student) {
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Enter Roll Number: ";
    while (!(cin >> student.rollNumber)) {
        cout << "Invalid input. Please enter a valid roll number: ";
        cin.clear(); 
        cin.ignore();
    }

    cin.ignore(); 
    cout << "Enter Class: ";
    getline(cin, student.className);

    cout << "Enter Division: ";
    cin >> student.division;
    cin.ignore();

    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    getline(cin, student.dateOfBirth);

    cout << "Enter Blood Group: ";
    getline(cin, student.bloodGroup);

    cout << "Enter Contact Address: ";
    getline(cin, student.contactAddress);

    cout << "Enter Telephone Number: ";
    getline(cin, student.telephoneNumber);

    cout << "Enter Driving License No: ";
    getline(cin, student.drivingLicenseNo);
}

class StudentDatabase {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student newStudent;
        inputStudentData(newStudent);
        students.push_back(newStudent);
    }

    void displayAllStudents() const {
        cout << "\nStudent Information:\n";
        for (size_t i = 0; i < students.size(); ++i) {
            cout << "\nStudent " << (i + 1) << ":\n";
            students[i].displayInfo();
        }
        Student::displayTotalStudents(students.size());
    }
};

int main() {
    StudentDatabase db;
    int numberOfStudents;

    cout << "Enter the number of students to add: ";
    cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; ++i) {
        cout << "\nEntering data for student " << (i + 1) << ":\n";
        db.addStudent();
    }

    db.displayAllStudents();
    return 0;
}