#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Course.h"

class Course; // Forward declaration

class Teacher {
private:
    std::string teacherId;
    std::string email;
    std::list<Course*> courses;

public:
    std::string name;

    Teacher() {}

    Teacher(const std::string& teacherName, const std::string& id, const std::string& emailAddress)
        : name(teacherName), teacherId(id), email(emailAddress) {}

    void assignCourse(Course* course) {
        courses.push_back(course);
    }

    void removeCourse(Course* course) {
        courses.remove(course);
    }

    void viewCourses() {
        std::cout << "Courses taught by " << name << ":" << std::endl;
        for (Course* course : courses) {
            std::cout << course->getCourseName() << std::endl;
        }
    }
};
