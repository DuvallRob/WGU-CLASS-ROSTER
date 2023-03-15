#include <iostream>
#include <string>
#include "roster.h"



using namespace std;

int main() {


    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Duvall,Roberts,drob98@wgu.edu,24,30,45,50,SOFTWARE"
    };

const int studentRoster = 5;
//Roster roster;

cout << "Course Title: Scripting & Programming - Applications" << endl;
cout << "Programming Language: C++" << endl;
cout << "Student Name: Duvall Roberts" << " and Student ID: 007792396 " << endl;

Roster classRosterArray(studentRoster);

for (int i = 0; i < studentRoster; i++) {
    classRosterArray.parse(studentData[i]);
}

cout << endl;

cout << "Displaying all students: " << endl;
classRosterArray.printAll();

cout << endl;

classRosterArray.printInvalidEmails();

cout << endl;

cout << "Average days in course for each student: " << endl;
for (int i = 0; i < studentRoster; i++) {
    classRosterArray.printAverageDaysInCourse(classRosterArray.getStudentAt(i)->getID());
}

cout << endl;

classRosterArray.printByDegreeProgram(SOFTWARE);

cout << endl;

classRosterArray.remove("A3");

cout << endl;

classRosterArray.printAll();

cout << endl;

classRosterArray.remove("A3");

cout << endl;

return 0;
}
