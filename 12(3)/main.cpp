1
//Shape.h
#ifndef shape_h
#define shape_h
#include <iostream>
using namespace std;
class Shape {
protected:
    int x,y;
public:
    Shape(int xx, int yy) {x = xx;y = yy;}
    virtual double area () const =0;
    virtual double circum() const = 0;
    void show_position() {cout << '(' << x << ',' << y << ')';}
};
#endif

//Shape.cpp

//Circle.h
#ifndef circle_h
#define circle_h
#include "Shape.h"
class Circle:public Shape{
protected:
    int r;
public:
    Circle(int xx, int yy, int rr):Shape(xx,yy) {r = rr;}
    virtual double area() const {return 3.1415926535*r*r;}
    virtual double circum() const {return 2*3.1415926535*r;}



};
#endif

//Circle.cpp

//Rectangle.h
#ifndef rectangle_h
#define rectangle_h
#include "Shape.h"
class Rectangle:public Shape {
protected:
    int w,h;
public:
    Rectangle(int xx, int yy, int ww, int hh=0):Shape(xx,yy) {w = ww;h = hh;}
    virtual double area() const {return w*h;}
    virtual double circum() const {return 2*(h+w);}

};
#endif

//Rectangle.cpp

//Square.h
#ifndef square_h
#define square_h
#include "Shape.h"
#include "Rectangle.h"

class Square: public Rectangle {
public:
    Square(int xx, int yy,int ww):Rectangle(xx,yy,ww) {h = w;}

};
#endif

//Square.cpp





2
//Employee.h
#ifndef employee_h
#define employee_h
#include <iostream>
#include <cstring>
using namespace std;
class Employee {
    friend void virtualViaPointer(Employee* p);
    friend void virtualViaReference(const Employee &obj);
protected:
    char firstname[20];
    char secondname[20];
    char ssn[15];
    int earned;
public:
    Employee(char *a,char *b,char *c) {strcpy(firstname,a);strcpy(secondname,b);strcpy(ssn,c);}
    virtual void print() const = 0;
    virtual int earnings() const = 0;
};
void virtualViaPointer(Employee* p)
{
    p->print();
    cout << "\nearned $" << p->earnings() << "\n\n";
}
void virtualViaReference(const Employee &obj)
{
    obj.print();
    cout << "\nearned $" << obj.earnings() << "\n\n";
}
#endif

//SalariedEmployee.h
#ifndef salariedemployee_h
#define salariedemployee_h
#include "Employee.h"
class SalariedEmployee:public Employee {
protected:
    int salary;
public:
    SalariedEmployee(char *a,char *b,char *c,int s):Employee(a,b,c) {salary = s;}
    virtual void print() const {
        cout << "salaried employee: " << firstname << ' ' << secondname <<endl << "social security number: " << ssn << endl;
        cout << "weekly salary: " <<salary;
    }
    virtual int earnings() const {return salary;}
};
#endif

//HourlyEmployee.h
#ifndef hourlyemployee_h
#define hourlyemployee_h
#include "Employee.h"
class HourlyEmployee:public Employee {
protected:
    double per;
    int hour;
public:
    HourlyEmployee(char *a,char *b,char *c, double p, int h):Employee(a,b,c) {per = p;hour = h;}
    virtual void print() const {
        cout << "hourly employee: " << firstname << ' ' << secondname <<endl << "social security number: " << ssn << endl;
        cout << "hourly wage: " << per << "; hours worked: " << hour;
    }
    virtual int earnings() const {if (hour <= 40) return int(per*hour);else return int(per*40+per*2*(hour-40));}
};
#endif

//CommissionEmployee.h
#ifndef commissionemployee_h
#define commissionemployee_h
#include "Employee.h"
class CommissionEmployee:public Employee {
protected:
    int sell;
    double rate;
public:
    CommissionEmployee(char *a,char *b,char *c, int s, double r):Employee(a,b,c) {sell = s;rate = r;}
    virtual void print() const {
        cout << "commission employee: " << firstname << ' ' << secondname <<endl << "social security number: " << ssn << endl;
        cout << "gross sales: " << sell << "; commission rate: " << rate;
    }
    virtual int earnings() const {return int(sell*rate);}
};
#endif

//BasePlusCommissionEmployee.h
#ifndef baseemployee_h
#define baseemployee_h
#include "Employee.h"
#include "CommissionEmployee.h"
class BasePlusCommissionEmployee:public CommissionEmployee {
protected:
    int basic;
public:
    BasePlusCommissionEmployee(char *a,char *b,char *c, int s, double r, int ba):CommissionEmployee(a,b,c,s,r) {basic = ba;}
    virtual void print() const {
        cout << "base-salaried commission employee: " << firstname << ' ' << secondname <<endl << "social security number: " << ssn << endl;
        cout << "gross sales: " << sell << "; commission rate: " << rate << "; base salary: " << basic;
    }
    virtual int earnings() const {return int(sell*rate+basic);}
};
#endif
