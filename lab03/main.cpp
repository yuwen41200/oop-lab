#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Students_Data {
private:
	int height;
	char* name;
public:
	Students_Data() {
		cout << "Constructor 1 called." << endl;
	}
	Students_Data(int _height, char* _name) {
		height = _height;
		name = _name;
		cout << "Constructor 2 called." << endl;
	}
	Students_Data(const Students_Data& obj) {
		height = obj.height;
		name = obj.name;
		cout << "Copy constructor called." << endl;
	}
	~Students_Data() {
		cout << "Destructor called." << endl;
	}
	void setHeight(int _height) {
		height = _height;
	}
	void setName(char* _name) {
		name = _name;
	}
	int getHeight() {
		return height;
	}
	char* getName() {
		return name;
	}
};

int main() {
	// part I
	Students_Data S1;
	Students_Data S2(160, "Tony");
	Students_Data S3 = S2;
	// part II
	cout << S3.getName() << " " << S3.getHeight() << endl;
	S3.setName("Jeff");
	S3.setHeight(180);
	cout << S3.getName() << " " << S3.getHeight() << endl;
	// part III
	srand(time(NULL));
	char* arrName[5] = {"A", "B", "C", "D", "E"};
	Students_Data Data[5];
	cout << "before sorting: " << endl;
	for (int i = 0; i < 5; ++i) {
		Data[i].setName(arrName[i]);
		Data[i].setHeight(150+rand()%31);
		cout << Data[i].getName() << " " << Data[i].getHeight() << endl;
	}
	for (int i = 5; i > 0; --i) {
		for (int j = 1; j < i; ++j) {
			if (Data[j-1].getHeight() > Data[j].getHeight()) {
				Students_Data temp = Data[j];
				Data[j] = Data[j-1];
				Data[j-1] = temp;
			}
		}
	}
	cout << "after sorting: " << endl;
	for (int i = 0; i < 5; ++i) {
		cout << Data[i].getName() << " " << Data[i].getHeight() << endl;
	}
	return 0;
}
