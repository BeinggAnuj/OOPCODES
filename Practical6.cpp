#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct PersonalRecord {
    std::string name;
    std::string dob; // Format: YYYY-MM-DD
    std::string telephone;
};

void displayRecords(const std::vector<PersonalRecord>& records) {
    std::cout << "Name\tDOB\tTelephone\n";
    for (const auto& record : records) {
        std::cout << record.name << "\t" << record.dob << "\t" << record.telephone << "\n";
    }
}

int main() {
    std::vector<PersonalRecord> records;
    int n;

    std::cout << "Enter the number of records: ";
    std::cin >> n;
    std::cin.ignore(); // Clear the newline character from the input buffer

    // Input records
    for (int i = 0; i < n; ++i) {
        PersonalRecord record;
        std::cout << "Enter Name: ";
        std::getline(std::cin, record.name);
        std::cout << "Enter DOB (YYYY-MM-DD): ";
        std::getline(std::cin, record.dob);
        std::cout << "Enter Telephone: ";
        std::getline(std::cin, record.telephone);
        records.push_back(record);
    }

    std::sort(records.begin(), records.end(), [](const PersonalRecord& a, const PersonalRecord& b) {
        return a.name < b.name;
    });

    std::cout << "\nSorted Records:\n";
    displayRecords(records);

    std::string searchName;
    std::cout << "\nEnter the name to search: ";
    std::getline(std::cin, searchName);

    bool found = false;
    for (const auto& record : records) {
        if (record.name == searchName) {
            std::cout << "Record found: " << record.name << ", " << record.dob << ", " << record.telephone << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Record not found.\n";
    }

    return 0;
}
