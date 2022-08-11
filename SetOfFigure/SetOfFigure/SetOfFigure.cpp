// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() = 0;
};

class Triangle : public Figure {
public:
    Triangle(const double& a, const double& b, const double& c)
        : A(a), B(b), C(c) {
    }
    string Name() const override {
        return FigureName;
    }
    double Perimeter() const override {
        return A + B + C;
    }
    double Area() override {
        double p = Perimeter() / 2.0;
        return sqrt(p * (p - A) * (p - B) * (p - C));
    }
private:
    const string FigureName = "TRIANGLE";
    const double A;
    const double B;
    const double C;
};

class Rect : public Figure {
public:
    Rect(const double& lenght, const double& width)
        : Lenght(lenght), Width(width){
    }
    string Name() const override {
        return FigureName;
    }
    double Perimeter() const override {
        return (Lenght + Width) * 2;
    }
    double Area() override {
        return Lenght * Width;
    }
private:
    const string FigureName = "RECT";
    const double Lenght;
    const double Width;
};

class Circle : public Figure {
public:
    Circle(const double& radius)
        : Radius(radius) {
    }
    string Name() const override {
        return FigureName;
    }
    double Perimeter() const override {
        return 2 * pi * Radius;
    }
    double Area() override {
        return pi * Radius * Radius;
    }
private:
    const string FigureName = "RECT";
    const double pi = 3.14;
    const double Radius;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string name = "";
    is >> name;
    is.ignore(1);

    if (name == "TRIANGLE") {
        double a = 0, b = 0, c = 0;
        is >> a;
        is.ignore(1);
        is >> b;
        is.ignore(1);
        is >> c;
        return make_shared<Triangle>(a, b, c);
    }
    else if (name == "RECT") {
        double lenght = 0, width = 0;
        is >> lenght;
        is.ignore(1);
        is >> width;
        return make_shared<Rect>(lenght, width);
    }
    else {
        double radius = 0;
        is >> radius;
        return make_shared<Circle>(radius);
    }
}
int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}
