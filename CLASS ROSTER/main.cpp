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

/*
                                                                References
         Vahid,F.Introduction to C++.zyBooks. Programming in C++.https://learn.zybooks.com/zybook/WGUC867v4.

         Vahid,F.Variables/Assignments.zyBooks. Programming in C++.https://learn.zybooks.com/zybook/WGUC867v4.

         Vahid,F.Branches.zyBooks. Programming in C++.https://learn.zybooks.com/zybook/WGUC867v4.

         Vahid,F.Loops.zyBooks. Programming in C++.https://learn.zybooks.com/zybook/WGUC867v4.

         Vahid,F.Arrays/Vectors.zyBooks. Programming in C++.https://learn.zybooks.com/zybook/WGUC867v4.

         Vahid,F.User-Defined Functions. Programming in C++.https://learn.zybooks.com/zybook/WGUC867v4.

         Vahid,F.Objects and Classes.zyBooks. Programming in C++.https://learn.zybooks.com/zybook/WGUC867v4.

         Vahid,Pointers.zyBooks. Programming in C++.https://learn.zybooks.com/zybook/WGUC867v4.

         Vahid,F.Streams.zyBooks. Programming in C++.https://learn.zybooks.com/zybook/WGUC867v4.
         
         Krypto,D.Book Repo.https://www.youtube.com/playlist?list=PLy3px7ccyKLdhMyTkvgbQN9mrYCM0OYSP

         .https://github.com/sophiedang0101/WGU-C867-Class-Roster-Project/blob/main/C%2B%2B_Class_Roster/Class_Roster_Program
*/