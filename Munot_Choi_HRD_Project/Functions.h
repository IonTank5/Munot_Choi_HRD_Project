#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// header file
// method prototypes.
bool isBlank(std::string);
bool getValidCourses(std::string);
bool getValidInt(std::string, const int);
bool disiplineIssue(void);
void formattable(std::vector<int>, std::vector<std::string>, std::string);
double calculateAverage(std::vector<int>);
bool enterPasscode(const std::string);

bool intTrap(std::string);
void Studentinformation(std::vector<std::string>, std::vector<std::string>, std::vector<int>, std::vector<bool>);
std::vector<double> averageToGPA(std::vector<double>);

std::vector<std::string> alphabeticalSort(std::vector<std::string>&);
std::vector<int> GPASort(std::vector<int> &);
void Information_for_one_student (std::vector<std::string> &, std::string, std::vector<std::string> &);
void sortingWithinSameGPA(std::vector<string> &, vector<double> &);