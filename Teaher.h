#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Course.h" 

using namespace std;

class Course;

class Teacher {
private:
    string teacherId;
    string email;
    list<Course*> courses;

public:
    string name;



    void setId(const string& id) {
        teacherId = id;
    }

    void setEmail(const string& emailAddress) {
        email = emailAddress;
    }

    Teacher(){}
    Teacher(const string& teacherName,const string& id,const string& emailAddress) : name(teacherName) , email(emailAddress) , teacherId(id){}

    void assignCourse(Course* course) {
        courses.push_back(course);
    }


    void removeCourse(Course* course) {
        courses.remove(course);
    }


    void viewCourses() {
        cout << "Courses taught by " << name << ":" << endl;
        for (Course* course : courses) {
            cout << course->getCourseName() << endl;
        }

    }
};
