#include <iostream>
#include <cmath>
using namespace std;

const float pi = 3.1415;

class Shape{
    public:
    string position;
    string color;
    int borderThickness;

    Shape(string pos, string clr, int t) 
        : position(pos), color(clr), borderThickness(t) {}

    virtual void draw() {}
    virtual void calculateArea () {}
    virtual void calculatePerimeter() {}
};

class Circle : public Shape{
    public:
    int radius; 
    double area = 0, perimeter = 0; 


    Circle(string pos, string clr, int t, int rad) 
        : Shape(pos, clr, t), radius(rad) {}

    void draw() override {
        cout << "Drawing a " << color << " Circle in " << position << ", with " << borderThickness << " Thickness" << endl;
    }

    void calculateArea() override {
        area = pi * (radius * radius);
        cout << "The Area is " << "(" << area << ")" << endl;
    }

    void calculatePerimeter() override {
        perimeter = 2 * pi * radius;
        cout << "The Perimeter is " << "(" << perimeter << ")" << endl;
    }
};

class Rectangle : public Shape{
    public:
    int length, width; 
    double area = 0, perimeter = 0; 


    Rectangle(string pos, string clr, int t, int l, int w) 
        : Shape(pos, clr, t), length(l), width(w) {}

    void draw() override {
        cout << "Drawing a " << color << " Rectangle in " << position << ", with " << borderThickness << " Thickness" << endl;
    }

    void calculateArea() override {
        area = length * width;
        cout << "The Area is " << "(" << area << ")" << endl;
    }

    void calculatePerimeter() override {
        perimeter = 2* (length + width);
        cout << "The Perimeter is " << "(" << perimeter << ")" << endl;
    }
};

class Triangle : public Shape{
    public:
    int base,height, slant; 
    double area = 0, perimeter = 0; 


    Triangle (string pos, string clr, int t, int h, int b, int s) 
        : Shape(pos, clr, t), height(h),base(b), slant(s) {}

    void draw() override {
        cout << "Drawing a " << color << " Triangle in " << position << ", with " << borderThickness << " Thickness" << endl;
    }

    void calculateArea() override {
        area = 0.5 * base * height;
        cout << "The Area is " << "(" << area << ")" << endl;
    }

    void calculatePerimeter() override {
        perimeter = base + height + slant;
        cout << "The Perimeter is " << "(" << perimeter << ")" << endl;
    }
};

class Polygon : public Shape {
    public:
        int numSides;
        double sideLength, area = 0, perimeter = 0; 
    
        Polygon(string pos, string clr, int t, int sides, double length)
            : Shape(pos, clr, t), numSides(sides), sideLength(length) {}
    
        void draw() override {
            cout << "Drawing a " << color << " Polygon with " << numSides << " sides at position " << position << " with border thickness " << borderThickness << endl;
        }
    
        void calculateArea() override {
            if (numSides < 3) {
                cout << "A polygon must have at least 3 sides!" << endl;
                return;
            }
            area = (numSides * sideLength * sideLength) / (4 * tan(pi / numSides));
            cout << "The Area is (" << area << ")" << endl;
        }
    
        void calculatePerimeter() override {
            perimeter = numSides * sideLength;
            cout << "The Perimeter is (" << perimeter << ")" << endl;
        }
};

int main(){
    Circle c("Center","Red", 20, 3);
    c.draw();
    c.calculateArea();
    c.calculatePerimeter();

    cout << endl;

    Rectangle r("Top-Right","Blue",15,2,3);
    r.draw();
    r.calculateArea();
    r.calculatePerimeter();

    cout << endl;

    Triangle t("Top-Left","Green",25,1,2,3);
    t.draw();
    t.calculateArea();
    t.calculatePerimeter();

    cout << endl;

    Polygon p("Bottom", "Blue", 10, 5, 4.0);
    p.draw();
    p.calculateArea();
    p.calculatePerimeter();

    return 0;
}
