#include <iostream>
#include <cstring>
using namespace std;

class vec {

	private:
		int* data;
		int size;

	public:
		~vec() {
			delete [] data;
		}

		int get_size() {
			return size;
		}

		int get_data(int index) {
			if (index < size && index >= 0)
				return data[index];
		}

		vec() {
			data = NULL;
			size = 0;
		}

		vec(int n) {
			data = new int[n];
			size = n;
		}

		vec(vec& b) {
			data = new int[b.size];
			size = b.size;
			memcpy(data, b.data, size * sizeof(int));
		}

		vec(int n, int* initial) {
			data = new int[n];
			size = n;
			memset(data, *initial, size * sizeof(int));
		}

		void print() {
			for (int i = 0; i < size; ++i) {
				cout << data[i] << " ";
			}
		}

		void set(int index, int n) {
			if (index < size && index >= 0)
				data[index] = n;
		}

		void operator=(vec& b) {
			delete [] data;
			data = new int[b.size];
			size = b.size;
			memcpy(data, b.data, size * sizeof(int));
		}

};
