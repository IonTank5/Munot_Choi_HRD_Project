// Munot_HonorRollProcedural.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Saakshi Munot and Jacob Choi
// 05/27/2021
// Honor Roll 2
// No Extra
// Software Design
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include "Functions.h"

int main()
{
    bool runAgain = false;
    string answer = "n";
    string dummy;
    fstream studChecker;
    studChecker.open("Student Information.txt", ios::in);
    int counter = 0;
    while (!studChecker.eof()) { //sees how manylines are in the code
        getline(studChecker, dummy);
        counter++;
    }
    studChecker.close();
    const string PASSCODE = "1111";
    const int MAX_GRADE = 120;
    string fullName, numberOfCourses, courseName;// definen variable
    int noOfCourses;
    do{

    
    do {
        cout << "Please enter your full name (first name, last name): ";// Ask user for full name
        getline(cin, fullName); // takes full name
        isBlank(fullName); // Checks if it is a blank string
    } while (isBlank(fullName) == true);
    cout << endl;
    do {
        cout << "Please enter how many courses you want to enter (You can enter between 1 and 8 courses): ";// ASks for number of courses
        getline(cin, numberOfCourses); // takes the number of courses
    } while (getValidCourses(numberOfCourses) == false); // keeps the loop to check if the number is between 1 and 8
    noOfCourses = stoi(numberOfCourses); // changes the string into an int
    cout << endl << "Course Name " << endl;
    cout << "(It should be a maximum of 20 characters or it will be truncated to 20 characters.)" << endl;

    cout << endl;
    vector<string> Cname;// Create Vector for course name
    vector<int> grade; // Create vector for course grades

    for (int i = 0; i < noOfCourses; i++) { // for loop for the number of courses
        do {
            cout << "Enter Course " << (i + 1) << " Name: "; // Asks Course name
            getline(cin, courseName);
        } while (isBlank(courseName) == true); /// checks if it is a blank string
        if (courseName.length() > 20) { // if the string is greater than 20 characters
            courseName = courseName.substr(0, 20); // truncates it to 20 character
            cout << "You entered a course name that is greater than 20 characters, so it will be truncated." << endl;
        }
        Cname.push_back(courseName); // adds the course name to the vector
    }

    cout << "Grades" << endl;
    cout << "(The Grades should be between 0 and 120, it can only be a whole number)" << endl;
    int grades;
    string cgrades;
    for (int i = 0; i < Cname.size(); ++i) // for loop till the length of the course name vector
    {
        do {
            cout << "What was you grade in: " << Cname[i] << '\n'; // ASks the grade
            getline(cin, cgrades);
        } while (getValidInt(cgrades, MAX_GRADE) == false); // checks if the grade entered is an int
        grades = stoi(cgrades); // turns it into an int
        grade.push_back(grades); // adds the course into the vector
    }
    double average = calculateAverage(grade);

    bool discipline = disiplineIssue(); // discipline issue

    cout << endl;
    formattable(grade, Cname, fullName); // formats it in a table
    cout << endl;
    cout << "Average: " << round(average) << endl; // Prints average
    //Prints if the user has an DIsciplinary Infraction or nor
    if (discipline == true) {
        cout << "Disciplinary Infraction: YES" << endl;
    }
    else {
        cout << "Disciplinary Infraction: NO" << endl;
    }
    // Checks if the user is honor roll or not
    bool eligible;
    if (average >= 90 && noOfCourses >= 5 && discipline == false) {
        cout << "CONGRATULATIONS " << fullName << "! You have made the honor roll." << endl << endl;
        eligible = true;
    }
    else {
        cout << "I'm Sorry " << fullName << " but you didn't qualify for the honor roll." << endl << endl;
        eligible = false;

    }
    //THIS IS TEMPORARY FOR TESTING PURPOSES
    vector<double> averages = { average };
    vector<double>GPAs = averageToGPA(averages);
    //Writing information to the file
    fstream studWriter;
    studWriter.open("Student Information.txt", ios::app);
    studWriter << fullName << "|" << average << "|" << discipline << "|" << GPAs[0] << "|" << numberOfCourses << "|" << eligible;
    for (int i = 0; i < noOfCourses; i++) {
        studWriter << "|" << Cname[i];
    }
    for (int i = 0; i < noOfCourses; i++) {
        studWriter << "|" << grade[i];
    }
    studWriter << endl;
    studWriter.close();

    cout << "Press y/Y to run again. Any other character to proceed: ";
        getline(cin, answer);
        if (answer == "y" || answer == "Y") {
            runAgain = true;
        }   
        else {
            runAgain = false;
        }
    } while (runAgain);
}
    

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
