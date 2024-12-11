#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct PersonalRecord {
    string name;
    string dob;
    string telephone;

    bool operator<(const PersonalRecord& other) const {
        return name < other.name;
    }
};

void displayRecord(const PersonalRecord& record) {
    cout << "Name: " << record.name << ", DOB: " << record.dob << ", Telephone: " << record.telephone << endl;
}

void inputRecords(vector<PersonalRecord>& records, int count) {
    for (int i = 0; i < count; ++i) {
        PersonalRecord record;
        cout << "Enter details for record " << (i + 1) << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, record.name);
        cout << "DOB (YYYY-MM-DD): ";
        cin >> record.dob;
        cout << "Telephone: ";
        cin >> record.telephone;
        records.push_back(record);
    }
}

void searchRecord(const vector<PersonalRecord>& records, const string& name) {
    auto it = find_if(records.begin(), records.end(), [&name](const PersonalRecord& record) {
        return record.name == name;
    });

    if (it != records.end()) {
        cout << "Record found:\n";
        displayRecord(*it);
    } else {
        cout << "Record not found for name: " << name << endl;
    }
}

int main() {
    vector<PersonalRecord> records;
    int count;

    cout << "Enter the number of personal records to input: ";
    cin >> count;

    inputRecords(records, count);

    sort(records.begin(), records.end());

    cout << "\nSorted Personal Records:\n";
    for (const auto& record : records) {
        displayRecord(record);
    }

    string searchName;
    cout << "\nEnter a name to search for: ";
    cin.ignore();
    getline(cin, searchName);
    searchRecord(records, searchName);

    return 0;
}