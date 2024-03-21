#pragma once
#include<iostream>
#include<string>
#include'Student.h'

class  Student;

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


};

