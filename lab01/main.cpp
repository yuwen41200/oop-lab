#include <iostream>
#define QUEUE_SIZE 5
using namespace std;

class queue {
public:
	int data[QUEUE_SIZE];
	int front;
	int rear;
	void push(int);
	void pop();
	void print();
};
queue Q;

void queue::push(int num) {
	if (Q.front == (Q.rear + 1) % 5) {
		cout << "full";
		return;
	}
	Q.rear = (Q.rear + 1) % 5;
	Q.data[Q.rear] = num;
	// cout << "debug:" << Q.front << " " << Q.rear << endl;
}

void queue::pop() {
	if (Q.front == Q.rear) {
		cout << "empty";
		return;
	}
	Q.front = (Q.front + 1) % 5;
	cout << Q.data[Q.front];
	// cout << "debug:" << Q.front << " " << Q.rear << endl;
}

void queue::print() {
	int i;
	if (Q.front == Q.rear) {
		cout << "empty";
		return;
	}
	for (i = (Q.front + 1) % 5; i != Q.rear; i = (i + 1) % 5) {
		cout << Q.data[i] << " ";
	}
	cout << Q.data[i];
}

int main() {
	int option, value;
	Q.front = 0;
	Q.rear = 0;
	while (1) {
		cout << "1.push 2.pop 3.print\n";
		cin >> option;
		switch (option) {
			case 1:
				cin >> value;
				Q.push(value);
				break;
			case 2:
				Q.pop();
				break;
			case 3:
				Q.print();
				break;
			default:
				break;
		}
		cout << endl;
	}
	return 0;
}