#include <iostream>
using namespace std;

struct IntStack10 {
	int pushed_integers[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int indice = 0;

	bool empty() {
		return indice == 0;
	};
	
	bool full() {
		return indice == 10;
	};

	void print() {
		if (empty()) {
			cout << "{ }" << endl;
		} else {
			cout << "{ ";
			for (int i = 0;i < indice - 1; i++) {
				cout << pushed_integers[i] << " ; ";
			};
			cout << pushed_integers[indice - 1] << " }" << endl;
		};
	};

	void print_bis() {
		cout << "{ ";
		for (int i = 0; i < 9;i++) {
			cout << pushed_integers[i] << " ; ";
		};
		cout << pushed_integers[9] << " }" << endl;
	};

	void push(int n) {
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

	int pop() {
		if (empty() == false) {
			int temp = pushed_integers[indice-1];
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
	IntStack10 stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	stack.push(9);
	stack.push(10);
	stack.push(11);
	return 0;
}
