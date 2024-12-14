#include <iostream>
using namespace std;

template <typename T>

struct stack {
    T* array;
    int size;
    int top;
    
    
    stack(int size) {
        this->size = size;
        this->top = 0;
        this->array = new T[size];
    }
    
    
    ~stack() {
        delete[] array;
    }
    
    
    void print() {
        if (top == 0) {
            cout << "[]" << endl;
        }
        else if (top == 1) {
            cout << "[" << array[0] << "]" << endl;
        }
        else {
            cout << "[" ;
            for (int i = 0; i < top - 1; i++) {
                cout << array[i] << ", "; 
            }
            cout << array[top - 1] << "]" << endl;
        }
    }
    
    
    void push(T item) {
        if (top < size) {
            array[top] = item;
            top ++;
        }
        else {
            cout << "Error : full stack cannot push new item" << endl;
        }
    }
    
    T pop() {
        if (top > 0) {
            top--;
            return array[top];
        }
        else {
            cout << "Error : empty stack cannot be popped" << endl;
            return array[0];
        }
    }
    
    T operator[] (int i) {
        if (i >= 0 && i < top) {
            return array[i];
        }
        else {
            cout << "Error : stack index out of bound" << endl;
            return array[0];
        }
    }
};



int main() {
    stack<int> s(2);
    s.print();
    s.push(1);
    s.print();
    s.push(2);
    s.print();
    s.push(3);
    cout << s[0] << ", " << s[1] << endl;
    int test = s[2];
    int a = s.pop();
    cout << a << endl;
    s.print();
    a = s.pop();
    cout << a << endl;
    s.print();
    s.pop();
    
    stack<double> s2(2);
    s2.print();
    s2.push(1.5);
    s2.print();
    s2.push(2.5);
    s2.print();
    s2.push(3.5);
    cout << s2[0] << ", " << s2[1] << endl;
    double test2 = s2[2];
    double b = s2.pop();
    cout << b << endl;
    s2.print();
    b = s2.pop();
    cout << b << endl;
    s2.print();
    s2.pop();
    
    stack<const char*> s3(2);
    s3.print();
    s3.push("a");
    s3.print();
    s3.push("b");
    s3.print();
    s3.push("c");
    cout << s3[0] << ", " << s3[1] << endl;
    const char* test3 = s3[2];
    const char* c = s3.pop();
    cout << c << endl;
    s3.print();
    c = s3.pop();
    cout << c << endl;
    s3.print();
    s3.pop();
    
    return 0;
}
