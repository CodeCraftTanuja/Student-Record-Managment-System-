#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks;

public:
    Student(int r, string n, float m) {
        rollNumber = r;
        name = n;
        marks = m;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    string getName() const {
        return name;
    }

    float getMarks() const {
        return marks;
    }

    void setDetails(string n, float m) {
        name = n;
        marks = m;
    }

    void display() const {
        cout << left << setw(12) << rollNumber 
             << setw(25) << name 
             << fixed << setprecision(2) << marks << endl;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent() {
        int roll;
        string name;
        float marks;

        cout << "\nEnter Roll Number: ";
        cin >> roll;

        for (const auto& student : students) {
            if (student.getRollNumber() == roll) {
                cout << "Error: A student with this roll number already exists.\n";
                return;
            }
        }

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;

        students.push_back(Student(roll, name, marks));
        cout << "Student record added successfully.\n";
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "\nNo records found.\n";
            return;
        }

        cout << "\n----------------------------------------------------\n";
        cout << left << setw(12) << "Roll No" << setw(25) << "Name" << "Marks" << endl;
        cout << "----------------------------------------------------\n";
        for (const auto& student : students) {
            student.display();
        }
        cout << "----------------------------------------------------\n";
    }

    void searchStudent() const {
        if (students.empty()) {
            cout << "\nNo records available to search.\n";
            return;
        }

        int roll;
        cout << "\nEnter Roll Number to search: ";
        cin >> roll;

        for (const auto& student : students) {
            if (student.getRollNumber() == roll) {
                cout << "\nRecord Found:\n";
                cout << "----------------------------------------------------\n";
                cout << left << setw(12) << "Roll No" << setw(25) << "Name" << "Marks" << endl;
                cout << "----------------------------------------------------\n";
                student.display();
                cout << "----------------------------------------------------\n";
                return;
            }
        }
        cout << "Student with Roll Number " << roll << " not found.\n";
    }

    void updateStudent() {
        if (students.empty()) {
            cout << "\nNo records available to update.\n";
            return;
        }

        int roll;
        cout << "\nEnter Roll Number to update: ";
        cin >> roll;

        for (auto& student : students) {
            if (student.getRollNumber() == roll) {
                string newName;
                float newMarks;

                cin.ignore();
                cout << "Enter New Name: ";
                getline(cin, newName);
                cout << "Enter New Marks: ";
                cin >> newMarks;

                student.setDetails(newName, newMarks);
                cout << "Record updated successfully.\n";
                return;
            }
        }
        cout << "Student with Roll Number " << roll << " not found.\n";
    }

    void deleteStudent() {
        if (students.empty()) {
            cout << "\nNo records available to delete.\n";
            return;
        }

        int roll;
        cout << "\nEnter Roll Number to delete: ";
        cin >> roll;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getRollNumber() == roll) {
                students.erase(it);
                cout << "Record deleted successfully.\n";
                return;
            }
        }
        cout << "Student with Roll Number " << roll << " not found.\n";
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "      STUDENT RECORD MANAGEMENT SYSTEM   \n";
        cout << "=========================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Student Records\n";
        cout << "3. Search Student Record\n";
        cout << "4. Update Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.displayAll();
                break;
            case 3:
                sms.searchStudent();
                break;
            case 4:
                sms.updateStudent();
                break;
            case 5:
                sms.deleteStudent();
                break;
            case 6:
                cout << "\nExiting the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}