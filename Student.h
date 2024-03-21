#pragma once
#include<iostream>
#include<string>
#include <list>
#include"Course.h"

using namespace std;


class Student {
private:
    int studentID;
    string name;
    string email;
    list<Course*> coursesEnrolled;

public:
    // Constructor
    Student(int id, const string& studentName, const string& emailAddress) : studentID(id), name(studentName), email(emailAddress) {}


    /*void getName(string StudentName) {
        name = StudentName;
    }*/

    // Method to enroll in a course
    void enrollCourse(Course* course) {
        coursesEnrolled.push_back(course);
        cout << name << " enrolled in " << course->getCourseName() << "." << endl;
    }

    // Method to drop a course
    void dropCourse(Course* course) {
        coursesEnrolled.remove(course);
        cout << name << " dropped " << course->getCourseName() << "." << endl;
    }

    // Method to view enrolled courses
    void viewCourses() const {
        cout << name << " is enrolled in the following courses:" << endl;
        for (Course* course : coursesEnrolled) {
            cout << course->getCourseName() << endl;
        }
    }

    //For geting names of Students
    string Name() {
        return name;
    }
};
