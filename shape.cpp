#include <iostream>
#include <cmath>
using namespace std;


float pi = 3.14159265358;


class Shape {
public:
    int x, y;
    
    void move (int dx, int dy) {
        x += dx;
        y += dy;
    };
    
    virtual void area() const {
        cout << "\"Shape area\"";
    };
    
    virtual void draw() const {
        cout << "\"Shape drawing\"";
    };
};


class Circle : public Shape {
public: 
    int r;
    
    Circle(int r) {
        this->r = r;    
    };
    
    void area() const {
        cout << pi*r*r;
    };
    
    void draw() const {
        cout << "O";
    };
    
};


class Rectangle : public Shape {
public :
    int l, w;
    
    Rectangle(int l, int w) {
        this->l = l;
        this->w = w;
    };
    
    void area() const {
        cout << l*w; 
    };
    
    void draw() const {
        cout << "|____|";
    };
};


class Square : public Shape {
public:
    int a;
    
    Square(int a) {
        this->a = a;
    };
    
    void area() const {
        cout << a * a;
    };
    
    void draw() const {
        cout << "|__|";
    };
};


class EquiTriangle : public Shape {
public:
    int a;
    
    EquiTriangle(int a) {
        this->a = a;
    };
    
    void area() const {
        cout << sqrt(3)*a*a/4;
    };
    
    void draw() const {
        cout << "/\\";
    };
};


void Area (Shape* s) {
  s->area();  
};


void Draw (Shape* s) {
    s->draw();
}


class ShapeStack {
public:
    int size;
    int top = 0;
    Shape** pushed_shapes;
    
    ShapeStack(int size){
        this->size = size;
        this->pushed_shapes = new Shape* [size];
        cout <<"Shape Stack size set to "<<size<<endl;
    };
    
    bool empty(){
        return top == 0;
    };
    
    bool full(){
        return top == size;
    };
    
    void print(){
        if (empty()){
            cout <<"{ }"<<endl;
        }
        else{
            cout <<"{ ";
            for(int i = 0; i<top-1;i++){
                cout << "( ";
                Draw(pushed_shapes[i]);
                cout << " , ";
                Area(pushed_shapes[i]);
                cout << " ) ; "; 
            };
            cout << "( ";
            Draw(pushed_shapes[top-1]);
            cout << " , ";
            Area(pushed_shapes[top-1]);
            cout <<" ) }"<<endl;
        };
    };
    
    void push(Shape* s){
        if (full()==false){
            pushed_shapes[top] = s;
            top += 1;
            cout << "New shape  ";
            Draw(s);
            cout << "  pushed into the stack : ";
            print();
        }
        else{
            cout << "Full stack cannot push new item"<<endl;
        };
    };
    
    Shape* pop(){
        if (empty()==false){
            Shape* temp = pushed_shapes[top - 1];
            pushed_shapes[top] = 0;
            top -= 1;
            cout << "Shape  ";
            Draw(temp);
            cout << "  popped from the stack : ";
            print();
            return temp;
        }
        else{
            cout <<"Empty stack cannot be pushed"<<endl;
            return 0;
        };
    };
    
};

int main() {
    Circle* c = new Circle(1);
    Rectangle* r = new Rectangle(1,2);
    Shape* s = new Shape();
    Square* sq = new Square(4);
    EquiTriangle* t = new EquiTriangle(1);
    ShapeStack stack(3);
    stack.push(c);
    stack.push(r);
    stack.push(sq);
    stack.push(s);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.push(t);
    stack.push(s);
    return 0;
};
