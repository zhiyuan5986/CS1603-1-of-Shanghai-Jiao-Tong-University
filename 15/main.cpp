//integer.h
#ifndef integer_h
#define integer_h
#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;
//class overflow_error {
//private:
//    char *message;
//public:
//    overflow_error(int hint) {
//        if (hint == 1) {message = new char;strcpy(message,"Overflow in addition!");}
//        if (hint == 2) {message = new char;strcpy(message,"Overflow in subtrction!");}
//        if (hint == 3) {message = new char;strcpy(message,"Overflow in multiplication!");}
//        if (hint == 4) {message = new char;strcpy(message,"Overflow in division!");}
//    }
//    const char* what() {return message;}
//};

class integer{
    friend int operator+(const integer &i1, const integer &i2);
    friend int operator-(const integer &i1, const integer &i2);
    friend int operator*(const integer &i1, const integer &i2);
    friend double operator/(const integer &i1, const integer &i2);
    friend void change(integer &i);
    friend ostream &operator<<(ostream &os, const integer &i);

public:
    int x;
    integer(int enter):x(enter) {}
    integer(const integer &i) {
        x = i.x;
    }
    integer& operator=(const integer &i) {
        x = i.x;
        return *this;
    }
};

#endif


//integer.cpp
#include "integer.h"
using namespace std;
void change(integer &i) {
    i.x = -i.x;
}
int operator+(const integer &i1, const integer &i2)
{
    int tmp = i1.x+i2.x;
    if ((tmp < 0 && i1.x >= 0 && i2.x >= 0) || (tmp > 0 && i1.x <= 0 && i2.x <= 0)) throw overflow_error("Overflow in addition!");
    return tmp;
}
int operator-(const integer &i1, const integer &i2)
{
    integer i3 = i2;
    change(i3);
    int tmp = 0;
    try {
        tmp = i1+i3;
    }
    catch (overflow_error) {throw overflow_error("Overflow in subtraction!");}
    return tmp;
}
int operator*(const integer &i1, const integer &i2)
{
    integer tmp(0);
    integer i3(0),i4(0);
    bool flag = 0;
    if (i1.x < 0 && i2.x > 0) {
        i3 = i1;
        change(i3);
        i4 = i2;
        flag = 1;
    }
    else if (i1.x > 0 && i2.x < 0) {
        i3 = i2;
        change(i3);
        i4 = i1;
        flag = 1;
    }
    else {
        i3 = i1;
        i4 = i2;
    }
    try {
        if (i3.x > i4.x) {
            for (int i=0;i<i4.x;i++) tmp = tmp+i3;
        }
        else {
            for (int i=0;i<i3.x;i++) tmp = tmp+i4;
        }
    }
    catch (overflow_error) {throw overflow_error("Overflow in multiplication!");}
    if (flag) change(tmp);
    return tmp.x;
}
double operator/(const integer &i1, const integer &i2)
{
    return i1.x/i2.x;
}
ostream &operator<<(ostream &os, const integer &i)
{
    os << i.x;
    return os;
}
