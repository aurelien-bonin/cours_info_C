#include <iostream>
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
        cout << "Shape area"<<endl;
    };
    
    virtual void draw() const {
        cout << "Shape drawing";
    };
};


class Circle : public Shape {
public: 
    int r;
    
    Circle(int r) {
        this->r = r;    
    };
    
    void area() const {
        cout << "Circle area = "<< pi*r*r <<endl;
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
        cout << "Rectangle area = "<< l*w <<endl; 
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
        cout << "Square area = "<< a * a << endl;
    };
    
    void draw() const {
        cout << "|__|";
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
                Draw(pushed_shapes[i]);
                cout<<" ; ";
            };
            Draw(pushed_shapes[top-1]);
            cout <<" }"<<endl;
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
    Area(c);
    Rectangle* r = new Rectangle(1,2);
    Area(r);
    Shape* s = new Shape();
    Area(s);
    Square* sq = new Square(4);
    Area(sq);
    
    ShapeStack stack(3);
    stack.push(c);
    stack.push(r);
    stack.push(sq);
    stack.push(s);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    return 0;
};


