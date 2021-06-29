1
//circle.h
#ifndef circle_h
#define circle_h
class Circle {
public:
    int x;
    int y;
    int r;
    Circle(int a=0,int b=0,int c=0) {x=a;y=b;r=c;}
    int getR() {return this->r;}
    void getO(int &a, int &b) {a=this->x;b=this->y;}
    void move(int a,int b) {this->x += a;this->y += b;}
    void setR(int R) {this->r=R;}
};
#endif

//circle.cpp
//main.cpp
#include "circle.h"
#include <iostream>
using namespace std;
int main()
{
    int x,y,r;
    cin>>x>>y>>r;
    Circle c(x,y,r);

    int cx,cy;
    c.getO(cx,cy);
    cout<<cx<<' '<<cy<<endl;
    cout<<c.getR()<<endl;

    int move_x,move_y;
    cin>>move_x>>move_y;
    c.move(move_x,move_y);
    c.getO(cx,cy);
    cout<<cx<<' '<<cy<<endl;

    int new_r;
    cin>>new_r;
    c.setR(new_r);
    cout<<c.getR()<<endl;

    return 0;
}

2
//clock.h
#ifndef Clock_h
#define Clock_h
#include <iostream>
using namespace std;
class clockT {
    friend clockT operator-(const clockT &c1, const clockT &c2);
public:
    int hour;
    int minute;
    int second;
    void show();
};
#endif

//clock.cpp
#include "clock.h"
void clockT::show()
{
    cout << this->hour/10 << this->hour%10 << ':' << this->minute/10 <<this->minute%10 << ':' << this->second/10 << this->second%10;
}
clockT operator-(const clockT &c1, const clockT &c2)
{
    clockT c;
    c.hour=c1.hour-c2.hour;
    c.minute=c1.minute-c2.minute;
    c.second=c1.second-c2.second;
    if (c.second < 0) {c.second += 60;c.minute--;}
    if (c.minute < 0) {c.minute+= 60;c.hour--;}
    if (c.hour < 0) {c.hour = -c.hour;c.minute = -c.minute;c.second=-c.second;
        if (c.second < 0) {c.second += 60;c.minute--;}
        if (c.minute < 0) {c.minute+= 60;c.hour--;}
    }
    return c;
}

//main.cpp
#include "circle.h"
#include <iostream>
using namespace std;
int main()
{
    int x,y,r;
    cin>>x>>y>>r;
    Circle c(x,y,r);

    int cx,cy;
    c.getO(cx,cy);
    cout<<cx<<' '<<cy<<endl;
    cout<<c.getR()<<endl;

    int move_x,move_y;
    cin>>move_x>>move_y;
    c.move(move_x,move_y);
    c.getO(cx,cy);
    cout<<cx<<' '<<cy<<endl;

    int new_r;
    cin>>new_r;
    c.setR(new_r);
    cout<<c.getR()<<endl;

    return 0;
}

