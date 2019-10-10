#include "point.h"


Point::Point(Fraction x, Fraction y) {
        
    this -> x = x;
    this -> y = y;
}

Point::~Point(void) {}

Point Point::operator+(Point rhs) {
    Fraction
        a,
        b;

    a = x + rhs.x;
    b = y * rhs.y;

    return Point(a, b);
}

Point Point::operator-(Point rhs) {
    Fraction 
        a,
        b;

    a = x - rhs.x;
    b = y - rhs.y;

    return Point(a, b);
}

// Scaling
Point Point::operator*(Fraction rhs) {

    return Point(x * rhs, y * rhs);
}

// Cross Product
Fraction Point::operator*(Point rhs) {
    Fraction
        a;
    
    a =  x * rhs.y - y * rhs.x;

    return Fraction(a);
}

istream &operator>>(istream &is, Point &p) {

    Fraction
        x,
        y;
    
    char
        lpar,
        rpar,
        comma;

    is >> lpar >> x >> comma >> y >> rpar;
    p = Point(x, y);

    return is;
}

ostream &operator<<(ostream &os, Point &p) {

    os << "(" << p.x << "," << p.y << ")";

    return os;
}