#pragma once

#include <iostream>
#include <string>
#include <list>
#include"Course.h"

class Student {
private:
    int studentID;
    std::string name;
    std::string email;
    std::list<std::string> coursesEnrolled;

public:
    Student(int id, const std::string& studentName, const std::string& emailAddress)
        : studentID(id), name(studentName), email(emailAddress) {}

    void enrollCourse(const std::string& courseName);

    void dropCourse(const std::string& courseName);

    void viewCourses() const;

    std::string Name() const;

    std::list<std::string> getCoursesEnrolled() const;
};

void Student::enrollCourse(const std::string& courseName) {
    coursesEnrolled.push_back(courseName);
    std::cout << name << " enrolled in " << courseName << "." << std::endl;
}

void Student::dropCourse(const std::string& courseName) {
    coursesEnrolled.remove(courseName);
    std::cout << name << " dropped " << courseName << "." << std::endl;
}

void Student::viewCourses() const {
    std::cout << name << " is enrolled in the following courses:" << std::endl;
    for (const auto& course : coursesEnrolled) {
        std::cout << course << std::endl;
    }
}

std::string Student::Name() const {
    return name;
}

std::list<std::string> Student::getCoursesEnrolled() const {
    return coursesEnrolled;
}
