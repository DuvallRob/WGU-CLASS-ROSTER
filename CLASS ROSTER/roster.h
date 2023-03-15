#pragma once
#include <iostream>
#include "student.h"
#include "degree.h"
class Roster
{
private:
	Student** classRosterArray;
	int numOfStudents;

public:
	
	Roster(int studentofRoster);

	void parse(string row);
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int studentAge,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);
	int i;
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void remove(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	Student* getStudentAt(int i);
	~Roster();
};