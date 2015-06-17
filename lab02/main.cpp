#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class stack {
	private:
		int value[100];
		int top;
	public:
		stack();
		int pop();
		void push(int);
};

stack::stack() {
	top = -1;
}

int stack::pop() {
	if (top == -1) return -1;
	top--;
	return value[top+1];
}

void stack::push(int a) {
	if (top == 99) return;
	top++;
	value[top] = a;
}

int main(int argc, const char *argv[]) {
	stack S;
	string strargv[argc];
	int a, b;
	for (int i = 0; i < argc; i++) {
		strargv[i] = argv[i];
	}
	for (int i = 0; i < argc; i++) {
		if (strargv[i] == "+") {
			b = S.pop();
			a = S.pop();
			S.push(a+b);
		}
		else if (strargv[i] == "-") {
			b = S.pop();
			a = S.pop();
			S.push(a-b);
		}
		else if (strargv[i] == "x") {
			b = S.pop();
			a = S.pop();
			S.push(a*b);
		}
		else if (strargv[i] == "/") {
			b = S.pop();
			a = S.pop();
			S.push(a/b);
		}
		else {
			S.push((int)strtol(argv[i], NULL, 16));
		}
	}
	cout << "Output:" << endl;
	for (int i = 0; i < argc; i++) {
		cout << strargv[i] << " ";
	}
	cout << "= " << hex << S.pop() << endl;
	return 0;
}