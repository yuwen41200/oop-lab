#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int LENGTH = 100;

class Poly {
private:
	int coe[LENGTH];
	int exp[LENGTH];
	int num;
public:
	Poly(int);
	Poly(Poly&);
	Poly();
	Poly operator-(Poly);
	Poly operator*(Poly);
	void init();
	int getValue(int);
	friend ostream& operator<<(ostream&, Poly&);
};

Poly::Poly(int n) {
	num = n;
}

Poly::Poly(Poly& a) {
	num = a.num;
	memcpy(coe, a.coe, sizeof(int)*LENGTH);
	memcpy(exp, a.exp, sizeof(int)*LENGTH);
}

Poly::Poly() {
}

Poly Poly::operator-(Poly a) {
	int n = num + a.num, i = 0, j = 0, k;
	static Poly tmp(n);
	for (k = 0; k < LENGTH; ++k) {
		if (j > a.num-1 && i > num-1) {
			break;
		}
		else if (j > a.num - 1) {
			tmp.coe[k] = coe[i];
			tmp.exp[k] = exp[i];
			i++;
		}
		else if (i > num - 1) {
			tmp.coe[k] = 0 - a.coe[j];
			tmp.exp[k] = a.exp[j];
			j++;
		}
		else if (exp[i] > a.exp[j]) {
			tmp.coe[k] = coe[i];
			tmp.exp[k] = exp[i];
			i++;
		}
		else if (exp[i] < a.exp[j]) {
			tmp.coe[k] = 0 - a.coe[j];
			tmp.exp[k] = a.exp[j];
			j++;
		}
		else {
			tmp.coe[k] = coe[i] - a.coe[j];
			tmp.exp[k] = exp[i];
			i++;
			j++;
		}
	}
	tmp.num = k;
	return tmp;
}

Poly Poly::operator*(Poly a) {
	int n = num * a.num, k = 0, b = 0;
	static Poly tmp(n);
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < a.num; ++j) {
			tmp.coe[k] = coe[i] * a.coe[j];
			tmp.exp[k] = exp[i] + a.exp[j];
			k++;
		}
	}
	tmp.num = k;
	k = tmp.exp[0] + 1;
	int *arrange = new int[k];
	memset(arrange, 0, sizeof(int)*k);
	for (int i = 0; i < tmp.num; ++i)
		arrange[tmp.exp[i]] += tmp.coe[i];
	for (int i = k - 1; i >= 0; --i) {
		if (arrange[i] != 0) {
			tmp.coe[b] = arrange[i];
			tmp.exp[b] = i;
			b++;
		}
	}
	tmp.num = b;
	delete [] arrange;
	return tmp;
}

void Poly::init() {
	cout << "Enter coefficients: ";
	for (int i = 0; i < num; ++i)
		cin >> coe[i];
	cout << "Enter exponentials: ";
	for (int i = 0; i < num; ++i)
		cin >> exp[i];
}

int Poly::getValue(int n) {
	int sum = 0;
	for (int i = 0; i < num; ++i)
		sum += coe[i]*pow(n, exp[i]);
	return sum;
}

ostream& operator<<(ostream& os, Poly& a) {
	bool notFirst = false;
	for (int i = 0; i < a.num; ++i) {
		if (a.coe[i] != 0) {
			if (notFirst) os << " + ";
			else notFirst = true;
			os << a.coe[i] << " x^" << a.exp[i];
		}
	}
	cout << endl;
	return os;
}

int main() {
	int a, b, x;
	Poly poly1, poly2, poly3;
	cout << "Enter the number of terms: ";
	cin >> a;
	Poly polyA(a);
	polyA.init();
	cout << "Enter the number of terms: ";
	cin >> b;
	Poly polyB(b);
	polyB.init();
	cout << "Enter the value of x: ";
	cin >> x;
	//cout << polyA;
	//cout << polyB;
	poly1 = polyA - polyB;
	poly2 = polyB - polyA;
	poly3 = polyA * polyB;
	cout << "P1 - P2: " << poly1;
	cout << "P2 - P1: " << poly2;
	cout << "P1 * P2: " << poly3;
	cout << "P1(x): " << polyA.getValue(x) << endl;
	cout << "P2(x): " << polyB.getValue(x) << endl;
	cout << "(P1-P2)(x): " << poly1.getValue(x) << endl;
	cout << "(P2-P1)(x): " << poly2.getValue(x) << endl;
	cout << "(P1*P2)(x): " << poly3.getValue(x) << endl;
	return 0;
}