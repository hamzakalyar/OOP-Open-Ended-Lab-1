#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Teacher.h"
#include "Student.h"

class Teacher; // Forward declaration
class Student; // Forward declaration

class Course {
private:
    int courseCode;

public:
    std::string courseName;
    Teacher* teacher;
    std::list<Student*> studentsEnrolled;

    void addStudent(Student* student) {
        studentsEnrolled.push_back(student);
    }

    void removeStudent(Student* student) {
        studentsEnrolled.remove(student);
    }

    void viewStudents() const {
        std::cout << "Students enrolled in " << courseName << ":" << std::endl;
        for (const auto& student : studentsEnrolled) {
            std::cout << student->Name() << std::endl;
        }
    }

    std::string getCourseName() const {
        return courseName;
    }

    void setTeacher(Teacher* t) {
        teacher = t;
    }
};
