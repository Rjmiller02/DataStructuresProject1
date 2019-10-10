#include "fraction.h"

static int gcd(int a, int b) {
    int
        r;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

Fraction::Fraction(int n, int d) {
    int
        g;

    if (d < 0) {
        n = -n;
        d = -d;
    }

    g = gcd(n, d);
    n /= g;
    d /= g;

    num = n;
    den = d;
}

Fraction::~Fraction(void) {}

Fraction Fraction::operator+(Fraction rhs) {
    int
        s,
        t;

    s = num * rhs.den + den * rhs.num;
    t = den * rhs.den;

    return Fraction(s, t);
}

Fraction Fraction::operator-(Fraction rhs) {
    int 
        s,
        t;

    s = num * rhs.den - den * rhs.num;
    t = den * rhs.den;

    return Fraction(s, t);
}

Fraction Fraction::operator*(Fraction rhs) {
    int
        s,
        t;
    
    s = num * rhs.num;
    t = den * rhs.den;

    return Fraction(s, t);
}

Fraction Fraction::operator/(Fraction rhs) {
    int
        s,
        t;

    s = num * rhs.den;
    t = den * rhs.num;

    return Fraction(s, t);
}

bool Fraction::operator==(Fraction rhs) {
    
    return num == rhs.num && den == rhs.den;
}

bool Fraction::operator!=(Fraction rhs) {

    return num != rhs.num || den != rhs.den;
}

bool Fraction::operator<(Fraction rhs) {

    return num * rhs.den < den * rhs.num;
}

bool Fraction::operator>(Fraction rhs) {

    return num * rhs.den > den * rhs.num;
}

bool Fraction::operator<=(Fraction rhs) {

    return num * rhs.den <= den * rhs.num;
}

bool Fraction::operator>=(Fraction rhs) {

    return num * rhs.den >= den * rhs.num;
}

bool Fraction::operator==(int integer) {

    return num == integer && den == 1;
}

bool Fraction::operator!=(int integer) {

    return num != integer || den != 1;
}

bool Fraction::operator<(int integer) {

    return num * 1 < den * integer;
}

bool Fraction::operator>(int integer) {

    return num * 1 > den * integer;
}

bool Fraction::operator<=(int integer) {

    return num * 1 <= den * integer;
}

bool Fraction::operator>=(int integer) {

    return num * 1 >= den * integer;
}

istream &operator>>(istream &is, Fraction &f) {

    int
        s,
        t;

    char slash;

    is >> s >> slash >> t;
    f = Fraction(s, t);

    return is;
}

ostream &operator<<(ostream &os, Fraction &f) {

    os << f.num << " / " << f.den;

    return os;
}