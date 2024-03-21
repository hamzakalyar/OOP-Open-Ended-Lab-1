#include "student.h"
#include <iostream>

using namespace std;
Student::Student(int id, const string& studentName, const string& emailAddress) : studentID(id), name(studentName), email(emailAddress) {}

void Student::enrollCourse(const string& course) {coursesEnrolled.push_back(course); 
     cout << name << " has enrolled in course: " << course << endl;}

void Student::dropCourse(const string& course) {
    for (auto it = coursesEnrolled.begin(); it != coursesEnrolled.end(); ++it) {
        if (*it == course) {
            coursesEnrolled.erase(it);
            cout << name << " has dropped course: " << course << endl;
            return;
        }
    }
    cout << name << " is not enrolled in course: " << course << endl;
}

void Student::viewCourses() const {
    cout << "Courses enrolled by " << name << ":" << endl;
    for (const auto& course : coursesEnrolled) {
        cout << course << endl;
    }
}
