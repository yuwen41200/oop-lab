#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;
const int MAX_DATA_COUNT = 100;

class SortNumbersFromFile {

private:
    string names[MAX_DATA_COUNT];
    int numbers[MAX_DATA_COUNT];
    int dataCount;
    string filename;

public:
    SortNumbersFromFile() {
        dataCount = 0;
        fstream input;
        cout << "Please input the filename: ";
        cin >> filename; // type /home/forever41200/Downloads/input.txt for sample input
        input.open(filename.c_str(), ios::in);
        if (input.is_open()) {
            while (!input.eof()) {
                input >> names[dataCount] >> numbers[dataCount];
                ++dataCount;
            }
        }
        else {
            cout << "Invalid filename." << endl;
        }
        input.close();
        print();
        convertToDec();
    }

    void print() {
        for (int it = 0; it < dataCount; ++it) {
            cout << names[it] << " " << numbers[it] << endl;
        }
    }

    void convertToDec() {
        for (int it = 0; it < dataCount; ++it) {
            int tmpDec = 0, tmpBin = numbers[it], power = 1;
            while (tmpBin) {
                int bit = tmpBin % 10;
                tmpDec += bit * power;
                tmpBin /= 10;
                power *= 2;
            }
            numbers[it] = tmpDec;
        }
    }

    void generateFile() {
        sort();
        fstream output;
        filename += ".out";
        output.open(filename.c_str(), ios::out);
        if (output.is_open()) {
            for (int it = 0; it < dataCount; ++it) {
                bitset<32> binNumber(static_cast<unsigned long long int>(numbers[it]));
                output << names[it] << " " << binNumber << endl;
            }
        }
        else {
            cout << "Error Occurred." << endl;
        }
        output.close();
    }

    void sort() {
        for (int i = dataCount-1; i >= 1 ; --i) {
            for (int j = 1; j <= i; ++j) {
                if (numbers[j-1] > numbers[j]) {
                    string tmpName = names[j-1];
                    int tmpNumber = numbers[j-1];
                    names[j-1] = names[j];
                    numbers[j-1] = numbers[j];
                    names[j] = tmpName;
                    numbers[j] = tmpNumber;
                }
            }
        }
    }

};

int main() {
    SortNumbersFromFile sortNumbersFromFile;
    sortNumbersFromFile.generateFile();
    return 0;
}
