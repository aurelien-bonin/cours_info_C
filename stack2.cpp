#include <iostream>
using namespace std;

class IntStack {
	int size;
	int* pushed_integers;
	int indice = 0;

public:
	IntStack (int size) {
		this->size = size;
		this->pushed_integers = new int[size];
	};
	
    IntStack (const IntStack& stack){
	    size = stack.size;
	    pushed_integers = new int[size];
	    indice = stack.indice;
	    for (int i = 0; i <= indice; i++) {
	        pushed_integers[i] = stack.pushed_integers[i];
	    };
	};

	~IntStack () {
	    delete[] pushed_integers;
	}

	bool empty() {
		return indice == 0;
	};

	bool full() {
		return indice == size;
	};

	void print() {
		if (empty()) {
			cout << "{ }" << endl;
		}
		else {
			cout << "{ ";
			for (int i = 0;i < indice - 1; i++) {
				cout << pushed_integers[i] << " ; ";
			};
			cout << pushed_integers[indice - 1] << " }" << endl;
		};
	};

	IntStack operator += (int n) {
		if (full() == false) {
			pushed_integers[indice] = n;
			indice = indice + 1;
			cout << n << " was pushed into the stack : ";
			print();
		}
		else {
			cout << "Full stack cannot push new item" << endl;
		};
	};
	
	IntStack operator -- () {
		if (empty() == false) {
			int temp = pushed_integers[indice - 1];
			pushed_integers[indice] = 0;
			indice = indice - 1;
			cout << temp << " was popped from the stack : ";
			print();
			return temp;
		}
		else {
			cout << "Empty stack cannot be popped" << endl;
		};
	};

};

int main() {
	IntStack stack (10);
	stack += 1;
	stack += 2;
	stack += 3;
	--stack;
	--stack;
	--stack;
	--stack;
	stack += 1;
	stack += 2;
	stack += 3;
	stack += 4;
	stack += 5;
	stack += 6;
	stack += 7;
	stack += 8;
	stack += 9;
	stack += 10;
	stack += 11;
	{ IntStack stack2 = stack; }
	stack.print();
	return 0;
}
