#pragma once
#include "student.h"
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->studentAge = 0;
	for (int i = 0; i < 3; i++) { this->daysArraySize[i] = 0; }
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysArraySize[3], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	
	this->daysArraySize[0] = daysArraySize[0];
	this->daysArraySize[1] = daysArraySize[1];
	this->daysArraySize[2] = daysArraySize[2];

	this->degreeProgram = degreeProgram;
}

Student:: ~Student() {}

string Student::getID() { return studentID; }
string Student::getFirst_name() { return firstName; }
string Student::getLast_name() { return lastName; }
string Student::getEmail_address() { return emailAddress; }
int Student::getAge() { return studentAge; }
int *Student::getDays() { return daysArraySize; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirst_name(string firstName) { this->firstName = firstName; }
void Student::setLast_name(string lastName) { this->lastName = lastName; }
void Student::setEmail_address(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int studentAge) { this->studentAge = studentAge; }
void Student::setDays(int daysArraySize[]) {
	for (int i = 0; i < 3; i++) this->daysArraySize[i] = daysArraySize[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::printHeader()
{
	cout << "Output format:\nID|First_name|Last_name|Email_address|Age|Days in Course|Degree\n";
}

void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getFirst_name() << '\t';
	cout << this->getLast_name() << '\t';
	cout << this->getEmail_address() << '\t';
	cout << this->getAge() << '\t';
	cout  << daysArraySize[0] << ", " << daysArraySize[1] << ", " << daysArraySize[2] << "\t ";
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}