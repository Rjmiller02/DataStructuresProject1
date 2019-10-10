#ifndef _POINT_H
#define _POINT_H

#include <iostream>
#include "fraction.h"

class Point {
    public:
        Point(Fraction x = Fraction(), Fraction y = Fraction());
        ~Point(void);

        Point operator+(Point rhs);
        Point operator-(Point rhs);
        Point operator*(Fraction rhs);
        Fraction operator*(Point rhs);
        
        friend istream &operator>>(istream &, Point &);
        friend ostream &operator<<(ostream &, Point &);

        Fraction getx() { return x; }
        Fraction gety() { return y; }
        
    private:
        Fraction
            x,
            y;
};

#endif