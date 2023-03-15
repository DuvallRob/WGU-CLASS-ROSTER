#pragma once
#include<iostream>
#include<iomanip>
#include "degree.h"
using std::string;
using std::cout;


class Student
{
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int daysArraySize[3];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysArraySize[3], DegreeProgram degreeProgram);
	~Student();

	/*getters*/
	string getID();
	string getFirst_name();
	string getLast_name();
	string getEmail_address();
	int getAge();
	int *getDays();
	DegreeProgram getDegreeProgram();

	/*setters*/
	void setID(string ID);
	void setFirst_name(string firstName);
	void setLast_name(string lastName);
	void setEmail_address(string emailAddress);
	void setAge(int studentAge);
	void setDays(int daysArraySize[]);
	void setDegreeProgram(DegreeProgram dp);

	static void printHeader();

	void print();
};
