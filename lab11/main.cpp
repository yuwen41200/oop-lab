#include <iostream>
#include <vector>
using namespace std;

class student {
private:
    string name;
    int height;
public:
    student(string name, int height) {
        this -> name = name;
        this -> height = height;
    }
    void print() {
        cout << name << ": " << height << endl;
    }
    int getHeight() {
        return height;
    }
};

template <class T>
void sort(vector<T>& a) {
    for (typename vector<T>::iterator it1 = a.end() - 2; it1 >= a.begin(); --it1)
        for (typename vector<T>::iterator it2 = a.begin(); it2 <= it1; ++it2)
            if (*it2 > *(it2 + 1))
                swap(*it2, *(it2 + 1));
}

void sort(vector<student>& a) {
    for (typename vector<student>::iterator it1 = a.end() - 2; it1 >= a.begin(); --it1)
        for (typename vector<student>::iterator it2 = a.begin(); it2 <= it1; ++it2)
            if (it2 -> getHeight() < (it2 + 1) -> getHeight())
                swap(*it2, *(it2 + 1));
}

int main() {
    srand((unsigned int)time(NULL));

    vector<int> part_a_int;
    for (int i = 0; i < 10; ++i) {
        int rd_int = rand() % 101;
        part_a_int.push_back(rd_int);
    }
    sort(part_a_int);
    for (vector<int>::iterator it = part_a_int.begin(); it < part_a_int.end(); ++it)
        cout << *it << " ";
    cout << endl << endl;

    vector<double> part_a_double;
    for (int i = 0; i < 10; ++i) {
        double rd_double = (double) rand();
        part_a_double.push_back(rd_double);
    }
    sort(part_a_double);
    for (vector<double>::iterator it = part_a_double.begin(); it < part_a_double.end(); ++it)
        cout << *it << " ";
    cout << endl << endl;

    vector<student> data;
    char n = 'A';
    for (int i = 0; i < 10; ++i) {
        char m[2];
        m[0] = n + (char) i;
        m[1] = '\0';
        string p(m);
        int rd_int = rand() % 31 + 150;
        student std(p, rd_int);
        data.push_back(std);
    }
    for (vector<student>::iterator it = data.begin(); it < data.end(); ++it)
        it -> print();
    cout << endl;
    sort(data);
    data.pop_back();
    for (vector<student>::iterator it = data.end() - 1; it >= data.begin(); --it)
        it -> print();
    cout << endl;

    return 0;
}
