#pragma once
#include<iostream>
#include<string>
#include"Student.h"

//class  Student;

using namespace std;

class Course
{
	int courseCode;
public:
	string courseName;
	Teacher* teacher;
	list<Student*> studentsEnrolled;


	void addStudent(Student* student) {
		studentsEnrolled.push_back(student);
	}

	void removeStudent(Student* student) {
		studentsEnrolled.push_back(student);
	}

	void viewStudents() const {
		cout << "Students enrolled in " << courseName << ":" << endl;
		for (const auto& student : studentsEnrolled) {
			cout << student->Name() << endl;
		}
	}

	string getCourseName() {
		return courseName;
	}


	void setTeacher(Teacher* t) {
		teacher = t;
	}

};

