#pragma once
#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Student {
private:
    int studentID;
    string name;
    string email;
    vector<string> coursesEnrolled;

public:
    Student(int id, const string& studentName, const string& emailAddress);

    void enrollCourse(const string& course);
    void dropCourse(const string& course);
    void viewCourses() const;
};


