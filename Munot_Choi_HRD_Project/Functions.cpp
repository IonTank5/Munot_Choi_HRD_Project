#include "Functions.h"
#include <iostream>

bool isBlank(string blank) { // method that checks if the string inputed is blank
	if (blank == " " || blank == "") {
		return true;
	}
	else {
		return false;
	}
}
bool getValidCourses(string course) { // method that checks if the number is between 1 and 8

	bool isValid = true;
	regex int_regex("[1-8]{1}");
	if (regex_match(course, int_regex)) {
		isValid = true;
	}
	else {
		isValid = false;
	}
	return isValid;
}
bool getValidInt(string number, const int MAX_GRADE) { // method that checks if the number is an integer between 0 and 120
	regex int_regex("[0-9]{1,3}");
	if (regex_match(number, int_regex)) {
		if (stoi(number) <= MAX_GRADE) {

			return 	true;
		}
		else {
			cout << "Invalid Input\n";
			return false;
		}

	}
	else {
		cout << "Invalid Input\n";
		return false;
	}
}
bool disiplineIssue() { // return a true or faslse depending on random disciplinary infraction
	int randomNumber;
	srand((unsigned)time(NULL));
	randomNumber = (rand() % 100) + 1;
	bool hasDisciplineIssue = ((randomNumber <= 5)) ? true : false;
	return hasDisciplineIssue;
}
void formattable(vector<int> grade, vector<std::string> course, string name) { // formats vectors and string into a table.
	const char separator = ' ';
	const int nameWidth = 25;
	const int numWidth = 8;

	cout << name << "\n\n";

	cout << left << setw(nameWidth) << setfill(separator) << "Class ";
	cout << left << setw(nameWidth) << setfill(separator) << "Grade";
	cout << endl;

	for (int i = 0; i < grade.size(); i++) {
		cout << left << setw(nameWidth) << setfill(separator) << course.at(i);
		cout << left << setw(numWidth) << setfill(separator) << grade.at(i);
		cout << endl;
	}
}
double calculateAverage(std::vector<int> grade) { //calculates average, pretty self explanatory
	double sum = accumulate(grade.begin(), grade.end(), 0); // sum of all the grades
	double average = sum / grade.size(); // average of all the grades
	return average;
}

bool enterPasscode(const string pass) {
	string input;
	cout << "Enter passcode: ";
	getline(cin, input);
	if (input == pass) {
		cout << "Welcome, administrator";
		return true;
	}
	else {
		cout << "Try again: ";
		getline(cin, input);
		if (input == pass) {
			cout << "Welcome, administrator";
			return true;
		}
		else {
			return false;
		}
	}
}
bool intTrap(string number) {
	regex int_regex("[0-9]{1,3}");
	if (regex_match(number, int_regex)) {
		return true;
	}
	else {
		cout << "Invalid Input\n";
		return false;
	}
}

/*void Studentinformation(std::vector<std::string> fullName, std::vector<std::string> courses, std::vector<int> grades, std::vector<bool> disciplinaryInfraction){
	ofstream fout;
	fout.open("Student Information.txt", ios::out);
	if(fout)

}*/

std::vector<double> averageToGPA(std::vector<double> averages) { //takes the averages and changes them to gpas
	std::vector<double> gpa;
	double temp = 0;
	for (int i = 0; i < averages.size(); i++) {
		if (averages[i] >= 93) {
			gpa.push_back(4);
			continue;
		}
		else if (averages[i] >= 90) {
			gpa.push_back(3.7);
			continue;
		}
		else if (averages[i] >= 87) {
			gpa.push_back(3.3);
			continue;
		}
		else if (averages[i] >= 83) {
			gpa.push_back(3);
			continue;
		}
		else if (averages[i] >= 80) {
			gpa.push_back(2.7);
			continue;
		}
		else if (averages[i] >= 77) {
			gpa.push_back(2.3);
			continue;
		}
		else if (averages[i] >= 73) {
			gpa.push_back(2);
			continue;
		}
		else if (averages[i] >= 70) {
			gpa.push_back(1.7);
			continue;
		}
		else if (averages[i] >= 67) {
			gpa.push_back(1.3);
			continue;
		}
		else if (averages[i] >= 65) {
			gpa.push_back(1);
			continue;
		}
		else if (averages[i] <= 65 && averages[i] >= 0) {
			gpa.push_back(0);
			continue;
		}
		else;
	}
	return gpa;
}

vector<string> alphabeticalSort(vector<string> &lastname){
	sort(lastname.begin(), lastname.end());
	return lastname;
}

vector<int> GPASort(vector<int> &GPA){
	sort(GPA.begin(), GPA.end(), greater<int>());
	return GPA;
}

void Information_for_one_student (vector<string> &fullname, string nameToFind, vector<string> &vecOfNums){
	vector<string>::iterator it = find(fullname.begin(), fullname.end(), nameToFind);
	if (it != vecOfNums.end())
		cout << "Element Found" << std::endl;

	else
		cout << "Element Not Found" << std::endl;

}	
void sortingWithinSameGPA(std::vector<string> &names, vector<double> &gpa) {
	double tempDub;
	string tempStr;
	for (int i = 0; i < gpa.size()-1; i++) {
		if (gpa[i + 1] == gpa[i]) {
			if (names[i] > names[i+1]) {//NOTE: VERIFY THIS WORKS AS INTENDED
				tempDub = gpa[i];
				gpa[i] = gpa[i + 1];
				gpa[i + 1] = tempDub;
				tempStr = names[i];
				names[i] = names[i + 1];
				names[i + 1] = tempStr;
			}
		}
	}
}
