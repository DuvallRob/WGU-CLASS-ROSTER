#include "roster.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <regex>

using namespace std;

Roster::Roster(int studentofRoster)
{

	classRosterArray = new Student *[studentofRoster];
	numOfStudents = studentofRoster;

	//set each element in classRosterArray to point to nullptr
	for (i = 0; i < studentofRoster; i++)
	{
		classRosterArray[i] = nullptr;
	}
}

void Roster::parse(string rosterData) {

	int rhs = rosterData.find(",");
	string studentID = rosterData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = rosterData.find(",", lhs);
	string firstName = rosterData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = rosterData.find(",", lhs);
	string lastName = rosterData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = rosterData.find(",", lhs);
	string emailAddress = rosterData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = rosterData.find(",", lhs);
	int studentAge = stod(rosterData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = rosterData.find(",", lhs);
	int daysInCourse1 = stoi(rosterData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = rosterData.find(",", lhs);
	int daysInCourse2 = stoi(rosterData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = rosterData.find(",", lhs);
	int daysInCourse3 = stoi(rosterData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;

	rhs = rosterData.find(",", lhs);

	DegreeProgram degreeProgram;
	string degreeStrings = rosterData.substr(lhs, rhs - lhs);

	if (degreeStrings == "SECURITY") { degreeProgram = DegreeProgram::SECURITY; }
	else if (degreeStrings == "NETWORK") { degreeProgram = DegreeProgram::NETWORK; }
	else if (degreeStrings == "SOFTWARE") { degreeProgram = DegreeProgram::SOFTWARE; }
	add(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysArraySize[3] = {daysInCourse1,daysInCourse2,daysInCourse3};
	daysArraySize[0] = daysInCourse1;
	daysArraySize[1] = daysInCourse2;
	daysArraySize[2] = daysInCourse3;
	Student *stud = new Student(studentID, firstName, lastName, emailAddress, studentAge, daysArraySize, degreeprogram);

	for (i = 0; i < numOfStudents; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			classRosterArray[i] = stud;
			break;
		}
	}
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <numOfStudents; i++) 
	{
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i < numOfStudents; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) { classRosterArray[i]->print(); }
	}
}

void Roster::printInvalidEmails()
{
	bool theItem = false;
	for (int i = 0; i < numOfStudents; i++)
	{
		const regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		if (!regex_match(classRosterArray[i]->getEmail_address(), emailPattern)) {
			cout << "Invalid Email Address found for Student ID: " << classRosterArray[i]->getID();
			cout << "<--" << classRosterArray[i]->getEmail_address() << endl;
			theItem = true;
		}
	}
	if (!theItem) {
		cout << "No invalid email addresses found" << endl;
	}
	cout << endl;
}

void Roster::remove(string studentID)
{
	for (int i = 0; i < numOfStudents; i++)
	{
		if (classRosterArray[i]->getID() == studentID) 
		{
			delete classRosterArray[i];
			for (int j = i; j < numOfStudents - 1; j++)
			{ classRosterArray[j] = classRosterArray[j + 1]; }
			classRosterArray[numOfStudents - 1] = nullptr;
			numOfStudents--;
			return;
		}
	}
		cout << "  No students found with that ID" << endl << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	cout << "The average days in course for student " << studentID << " is: ";
	for (i = 0; i < numOfStudents; i++) {
		if (studentID == classRosterArray[i]->getID()) {
			string strName = classRosterArray[i]->getFirst_name() + " " + classRosterArray[i]->getLast_name();
			int avgDays = ((classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3);
			cout << "Student ID: " << studentID << ", average days in course: " << avgDays << endl;
		}
	}
	return;
}

Student *Roster::getStudentAt(int i)
{
	return classRosterArray[i];
}

Roster::~Roster() {
	for (i = 0; i < numOfStudents; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			delete classRosterArray[i];
		}
	}
	delete[] classRosterArray;
	return;
}