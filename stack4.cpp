#include <iostream>
using namespace std;

template<typename T>

struct Stack {
    int size;
    int top;
    T* stack;
    
    
    Stack(int size){
        this->size = size;
        this->top = 0;
        this->stack = new T[size];
    }
    
    
    ~Stack() {
        delete[] stack;
    }
    
    
    void print() {
		if (top == 0) {
			cout << "{ }" << endl;
		}
		else {
			cout << "{ ";
			for (int i = 0;i < top - 1; i++) {
				cout << stack[i] << " ; ";
			};
			cout << stack[top - 1] << " }" << endl;
		};
	}
	
	
	void push(T item) {
	    if (top < size) {
	        stack[top] = item;
	        top ++;
	    }
	    else {
	        cout << "Error : full stack cannot push new item" << endl;
	    }
	}
	
	
	void pop() {
	    if (top > 0) {
	        T popped = stack[top - 1];
	        top --;
	        cout << popped << " popped from stack" << endl;
	    }
	    else {
	        cout << "Error : empty stack cannot be popped" << endl;
	    }
	}
};

 
int main() {
    Stack<const char*> stack(3);
    stack.push("a");
    stack.print();
    stack.push("b");
    stack.print();
    stack.push("c");
    stack.print();
    stack.push("d");
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    
    Stack<int> stack2(3);
    stack2.push(1);
    stack2.print();
    stack2.push(2);
    stack2.print();
    stack2.push(3);
    stack2.print();
    stack2.push(4);
    stack2.pop();
    stack2.print();
    stack2.pop();
    stack2.print();
    stack2.pop();
    stack2.print();
    stack2.pop();
    return 0;
}
