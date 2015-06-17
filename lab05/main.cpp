#include <iostream>
#include <cstdio>
#include <string>
#define MAX 100

using namespace std;
int total = 0;

class Zip
{
	string name;
	int code1, code2;
public:
	void setName(string a) {
		name = a;
		total++;
	}
	void setCode(int a, int b) {
		code1 = a;
		code2 = b;
	}
	string getName() {
		return name;
	}
	string getCode() {
		char temp1[20];
		sprintf(temp1, "%d-%d", code1, code2);
		string temp2(temp1);
		return temp2;
	}
	int getSum() {
		int temp1 = code1;
		int temp2 = code2;
		int sum = 0;
		while (temp1 > 0) {
			sum += temp1 % 10;
			temp1 /= 10;
		}
		while (temp2 > 0) {
			sum += temp2 % 10;
			temp2 /= 10;
		}
		return sum;
	}
	Zip operator+(Zip a) {
		Zip temp;
		temp.name = name;
		temp.code1 = code1 + a.code1;
		temp.code2 = code2 + a.code2;
		return temp;
	}
	void operator=(Zip a) {
		name = a.name;
		code1 = a.code1;
		code2 = a.code2;
	}
};

Zip data[MAX];

int find(string a) {
	for (int i = 0; i < total; ++i)
		if (data[i].getName() == a)
			return i;
	return -1;
}

int main() {
	while (1) {
		int choose, position1, position2;
		string input1, input2;
		cin >> choose;
		switch (choose) {
			case 0:
				cin >> input1;
				position1 = find(input1);
				if (position1 != -1)
					cout << "Already Created." << endl;
				else {
					data[total].setName(input1);
					cout << "User Created." << endl;
				}
				break;
			case 1:
				cin >> input1;
				position1 = find(input1);
				if (position1 == -1)
					cout << "Not Exist." << endl;
				else {
					int a, b;
					scanf("%d-%d", &a, &b);
					data[position1].setCode(a, b);
					cout << "Name: " << data[position1].getName() << endl;
					cout << "Code: " << data[position1].getCode() << endl;
				}
				break;
			case 2:
				cin >> input1;
				cin >> input2;
				position1 = find(input1);
				position2 = find(input2);
				if (position1 == -1 || position2 == -1)
					cout << "Not Exist." << endl;
				else {
					data[position1] = data[position1] + data[position2];
					cout << "Name: " << data[position1].getName() << endl;
					cout << "Code: " << data[position1].getCode() << endl;
					cout << "Name: " << data[position2].getName() << endl;
					cout << "Code: " << data[position2].getCode() << endl;
				}
				break;
			case 3:
				for (int i = 0; i < total; ++i) {
					cout << "Name: " << data[i].getName() << endl;
					cout << "Sum: " << data[i].getSum() << endl;
				}
				for (int i = total - 1; i > 0; --i) {
					for (int j = 0; j < i; ++j)	{
						if (data[j].getSum() < data[j+1].getSum()) {
							Zip temp = data[j];
							data[j] = data[j+1];
							data[j+1] = temp;
						}
					}
				}
				cout << "Comparison: ";
				for (int i = 0; i < total; ++i) {
					if (i == total - 1)
						cout << data[i].getName() << endl;
					else
						cout << data[i].getName() << " > ";
				}
				break;
			default:
				return 0;
		}
	}
	return 0;
}
