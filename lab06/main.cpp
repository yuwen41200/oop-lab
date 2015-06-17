#include <iostream>
#include <string>
using namespace std;

class RegSys;

class CourseTable {

private:

	string name[6];
	int time[6][40];
	int timeCount[6];
	string timeStr[6];

public:

	friend class RegSys;

	CourseTable() {
		name[0] = "CO";
		name[1] = "NP";
		name[2] = "DS";
		name[3] = "PL";
		name[4] = "LA";
		name[5] = "OS";
		time[0][0] = 11;
		time[0][1] = 12;
		time[0][2] = 13;
		timeCount[0] = 3;
		time[1][0] = 13;
		time[1][1] = 14;
		time[1][2] = 15;
		timeCount[1] = 3;
		time[2][0] = 33;
		time[2][1] = 34;
		time[2][2] = 35;
		timeCount[2] = 3;
		time[3][0] = 35;
		time[3][1] = 36;
		time[3][2] = 37;
		timeCount[3] = 3;
		time[4][0] = 55;
		time[4][1] = 56;
		time[4][2] = 57;
		timeCount[4] = 3;
		time[5][0] = 56;
		time[5][1] = 57;
		time[5][2] = 58;
		timeCount[5] = 3;
		timeStr[0] = "MON 123";
		timeStr[1] = "MON 345";
		timeStr[2] = "WED 345";
		timeStr[3] = "WED 567";
		timeStr[4] = "FRI 567";
		timeStr[5] = "FRI 678";
	}

};

class RegSys {

private:

	string usr[100];
	string prompt[2];
	int userCount;
	int sysStat;
	int usrNo;
	int courseNo[6];
	int courseCount;

	int findUsr(string a) {
		for (int i = 0; i < userCount; ++i)
			if (usr[i] == a)
				return i;
		return -1;
	}

	int findCourse(CourseTable& a, string b) {
		for (int i = 0; i < 6; ++i)
			if (a.name[i] == b)
				return i;
		return -1;
	}

public:

	RegSys() {
		sysStat = 0;
		userCount = 0;
		usrNo = -1;
		courseCount = 0;
		prompt[0] = "Press 0 for new user register, press 1 for login:\n";
		prompt[1] = "Press 2 for choosing courses, press 3 for showing courses, press 4 to logout:\n";
	}

	void addUsr() {
		string input;
		cout << "Enter a username: ";
		cin >> input;
		if (findUsr(input) != -1)
			cout << "Error: Already created.\n";
		else {
			usr[userCount++] = input;
			cout << "User " << input << " has been created successfully.\n";
		}
	}

	void loginUsr() {
		string input;
		cout << "Enter a username: ";
		cin >> input;
		if (findUsr(input) != -1) {
			cout << "Welcome, " << input << ".\n";
			usrNo = findUsr(input);
			sysStat = 1;
		}
		else
			cout << "Error: Not registered yet.\n";
	}

	void chooseCourse(CourseTable& a) {
		string inputCourse;
		cout << "Enter course name: ";
		cin >> inputCourse;
		if (findCourse(a, inputCourse) != -1) {
			int tmpNo = findCourse(a, inputCourse);
			bool overlap = false;
			for (int i = 0; i < courseCount; ++i) {
				for (int j = 0; j < a.timeCount[courseNo[i]]; ++j) {
					for (int k = 0; k < a.timeCount[tmpNo]; ++k) {
						if (a.time[courseNo[i]][j] == a.time[tmpNo][k]) {
							overlap = true;
							break;
						}
					}
				}
			}
			if (overlap) {
				cout << "Error: Course " << inputCourse << " overlap!\n";
			}
			else {
				courseNo[courseCount++] = tmpNo;
				cout << inputCourse << " choosed.\n";
			}
		}
		else
			cout << "Error: Invalid course name.\n";
	}

	void showCourse(CourseTable& a) {
		cout << usr[usrNo] << "'s courses:\n";
		for (int i = 0; i < courseCount; ++i)
			cout << a.name[courseNo[i]] << " " << a.timeStr[courseNo[i]] << endl;
	}

	void logoutUsr() {
		cout << "Logged out.\n";
		sysStat = 0;
	}

	void writePrompt() {
		cout << prompt[sysStat];
	}

	int getSysStat() {
		return sysStat;
	}

};

int main() {
	CourseTable ct;
	RegSys rs;
	int choise;
	while(1) {
		rs.writePrompt();
		cin >> choise;
		switch (choise) {
			case 0:
				if (rs.getSysStat() == 0)
					rs.addUsr();
				else
					cout << "Error: Already logged in.\n";
				break;
			case 1:
				if (rs.getSysStat() == 0)
					rs.loginUsr();
				else
					cout << "Error: Already logged in.\n";
				break;
			case 2:
				if (rs.getSysStat() == 1)
					rs.chooseCourse(ct);
				else
					cout << "Error: Not logged in yet.\n";
				break;
			case 3:
				if (rs.getSysStat() == 1)
					rs.showCourse(ct);
				else
					cout << "Error: Not logged in yet.\n";
				break;
			case 4:
				if (rs.getSysStat() == 1)
					rs.logoutUsr();
				else
					cout << "Error: Not logged in yet.\n";
				break;
			default:
				return 0;
		}
		cout << endl;
	}
	return 0;
}
