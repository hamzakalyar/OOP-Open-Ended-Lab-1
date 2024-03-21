#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Teacher.h"
#include "Student.h"
#include "Course.h"

using namespace std;

// Function to read students' enrollment information from file
void readEnrollmentInfo(vector<Student>& students, vector<Course>& courses) {
    ifstream inFile("enrollment_info.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file!" << endl;
        return;
    }

    string studentName, courseName;
    while (inFile >> studentName >> courseName) {
        for (auto& student : students) {
            if (student.Name() == studentName) {
                for (auto& course : courses) {
                    if (course.getCourseName() == courseName) {
                        student.enrollCourse(&course);
                        course.addStudent(&student);
                        break;
                    }
                }
                break;
            }
        }
    }

    inFile.close();
}

// Function to save students' enrollment information to file
void saveEnrollmentInfo(const vector<Student>& students) {
    ofstream outFile("enrollment_info.txt");
    if (!outFile.is_open()) {
        cout << "Unable to open file!" << endl;
        return;
    }

    for (const auto& student : students) {
        for (const auto& course : student.coursesEnrolled) {
            outFile << student.Name() << " " << course->getCourseName() << endl;
        }
    }

    outFile.close();
}

int main() {
    // Create teachers
    Teacher teacher1("Dr. Smith", "123", "smith@example.com");
    Teacher teacher2("Prof. Johnson", "456", "johnson@example.com");

    // Create courses
    Course course1;
    course1.courseName = "Math";
    Course course2;
    course2.courseName = "Physics";

    // Assign teachers to courses
    course1.setTeacher(&teacher1);
    course2.setTeacher(&teacher2);

    // Create students
    vector<Student> students;
    Student student1(1, "Alice", "alice@example.com");
    Student student2(2, "Bob", "bob@example.com");
    students.push_back(student1);
    students.push_back(student2);

    // Read enrollment info from file
    readEnrollmentInfo(students, {course1, course2});

    // Main menu
    int choice;
    do {
        cout << "\nUniversity Management System\n";
        cout << "1. Enroll in a course\n";
        cout << "2. View enrolled courses\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Available Courses:\n";
                cout << "1. " << course1.getCourseName() << "\n";
                cout << "2. " << course2.getCourseName() << "\n";
                cout << "Enter course number to enroll: ";
                int courseChoice;
                cin >> courseChoice;
                if (courseChoice == 1) {
                    student1.enrollCourse(&course1);
                } else if (courseChoice == 2) {
                    student1.enrollCourse(&course2);
                } else {
                    cout << "Invalid choice\n";
                }
                // Save enrollment info to file
                saveEnrollmentInfo(students);
                break;
            }
            case 2: {
                cout << "Enrolled Courses:\n";
                student1.viewCourses();
                break;
            }
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
