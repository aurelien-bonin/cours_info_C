#include <iostream>
using namespace std;

template <typename T>
struct Vector {
    T* array;
    int size;
    int top;

    Vector() {
        this->size = 1;
        this->top = 0;
        this->array = new T[size];
    }

    ~Vector() {
        delete[] array;
    }

    void push(T item) {
        if (top < size) {
            array[top] = item;
            top++;
        }
        else {
            T* temp = new T[2 * size];
            for (int i = 0; i < top; i++) {
                temp[i] = array[i];
            }
            temp[top] = item;
            delete[] array;
            array = temp;
            size *= 2;
            top++;
        }
    }

    void print() {
        if (top == 0) {
            cout << "[]" << endl;
        }
        else if (top == 1) {
            cout << "[" << array[0] << "]" << endl;
        }
        else {
            cout << "[";
            for (int i = 0; i < top - 1; i++) {
                cout << array[i] << ", ";
            }
            cout << array[top - 1] << "]" << endl;
        }
    }

    T pop() {
        if (top == 0) {
            cout << "Error : empty vector cannot be popped" << endl;
            return array[0];
        }
        else {
            top--;
            return array[top];
        }
    }

    T operator[] (int i) {
        if (0 <= i && i < top) {
            return array[i];
        }
        else {
            cout << "Error : Vector index out of range" << endl;
            return array[0];
        }
    }
};


int main() {
    Vector<double> v;
    double a;
    v.push(1.5);
    v.print();
    v.push(2.5);
    v.print();
    v.push(3.5);
    v.print();
    cout << v[0] << ", " << v[1] << ", " << v[2] << endl;
    double b = v[3];
    a = v.pop();
    cout << a << endl;
    v.print();
    a = v.pop();
    cout << a << endl;
    v.print();
    a = v.pop();
    cout << a << endl;
    v.print();
    v.pop();
    return 0;
}
