#pragma once
#include <iostream>
#include<string>

using namespace std;

class Course;


class Teacher
{
	string studentId;
	string Email;
public:
	string name;

	void getId(string Id) {
		studentId = Id;
	}

	void getEmail(string email) {
		Email = email;
	}


};

