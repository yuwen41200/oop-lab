#include <iostream>
#include "vec.h"
using namespace std;

class Queue : protected vec {

	private:
		int front, rear;

	public:
		Queue(int n) : vec(n) {
			front = rear = 0;
		}

		Queue(Queue& b) : vec(b) {
			front = b.front;
			rear = b.rear;
		}

		void Push(int n) {
			if ((rear + 1) % get_size() == front)
				cout << "Full" << endl;
			else {
				rear = (rear + 1) % get_size();
				set(rear, n);
			}
		}

		void Pop() {
			if (rear == front)
				cout << "Empty" << endl;
			else
				front = (front + 1) % get_size();
		}

		int Front() {
			return get_data((front + 1) % get_size());
		}

		bool isEmpty() {
			return (rear == front);
		}

};

class Stack : protected vec {

	private:
		int top;

	public:
		Stack(int n) : vec(n) {
			top = -1;
		}

		Stack(Stack& b) : vec(b) {
			top = b.top;
		}

		void Push(int n) {
			if (top + 1 == get_size())
				cout << "Full" << endl;
			else
				set(++top, n);
		}

		void Pop() {
			if (top == -1)
				cout << "Empty" << endl;
			else
				--top;
		}

		int Top() {
			return get_data(top);
		}

		bool isEmpty() {
			return (top == -1);
		}

};

int main() {
	cout<<"Test Stack"<<endl;
	Stack s(5);

	for (int i = 0; i < 6; i++)
		s.Push(i);

	while (!s.isEmpty()) {
		cout << s.Top() << " ";
		s.Pop();
	}

	cout<<endl;
	s.Pop();
	cout<<endl;

	cout<<"Test Queue"<<endl;
	Queue test(10+1);

	for (int i = 1; i < 4; i++)
		test.Push(i);

	Queue test1(test);

	for (int i = 4; i <= 11; i++)
		test1.Push(i);

	test1.Pop();
	test1.Pop();
	test1.Push(11);

	while (!test1.isEmpty()) {
		cout << test1.Front() << " ";
		test1.Pop();
	}

	cout<<endl;
	test1.Pop();

	return 0;
}
