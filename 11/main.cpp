1
//matrix.h
#ifndef matrix_h
#define matrix_h
#include <iostream>
using namespace std;
class Matrix {
    friend Matrix operator+(const Matrix &a, const Matrix &b);
    friend ostream & operator<<(ostream &os, const Matrix &obj);
    friend istream & operator>>(istream &is, Matrix &obj);
    int **row;
public:
    int r;
    int c;
    Matrix(int m=0,int n=0) {
        r = m;
        c = n;
        row = new int*[r];
        for (int i=0;i<r;++i) row[i] = new int[c];
    }
    Matrix(const Matrix &obj)
    {
        r = obj.r;
        c = obj.c;
        delete row;
        int **row = new int*[r];
        for (int i=0;i<r;++i) row[i] = new int[c];
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) row[i][j] = obj.row[i][j];
        }
    }
    ~Matrix() {
        for (int i=0;i<r;++i) delete [] row[i];
        delete [] row;
    }
    int operator()(int x, int y) {
        return row[x][y];
    }
    Matrix &operator=(const Matrix &obj);
};
#endif

//matrix.cpp
#include "matrix.h"
Matrix operator+(const Matrix &a, const Matrix &b)
{
    Matrix C(a.r,a.c);
    for (int i=0;i<C.r;i++) {
        for (int j=0;j<C.c;j++) C.row[i][j] = a.row[i][j]+b.row[i][j];
    }
    return C;
}
ostream & operator<<(ostream &os, const Matrix &obj)
{
    for (int i=0;i<obj.r;i++) {
        for (int j=0;j<obj.c-1;j++) cout << obj.row[i][j] << ' ';
        cout << obj.row[i][obj.c-1] << endl;
    }
    return os;
}
istream & operator>>(istream &is, Matrix &obj)
{
    for (int i=0;i<obj.r;i++) {
        for (int j=0;j<obj.c;j++) cin >> obj.row[i][j];
    }
    return is;
}
Matrix & Matrix::operator=(const Matrix &obj)
{
    if (this == &obj) return *this;
    r = obj.r;
    c = obj.c;
    delete row;
    int **row = new int*[r];
    for (int i=0;i<r;++i) row[i] = new int[c];
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) row[i][j] = obj.row[i][j];
    }
    return *this;
}

//main.cpp
#include<iostream>
#include "matrix.h"
using namespace std;

int main()
{
  int m, n, x, y;
  cin >> m >> n >> x >> y;
  Matrix a(m, n), b(m, n);
  cin >> a >> b;
  Matrix c = a+b;
  cout << c;
  a = b+c;
  // print element at row-x column-y of Matrix a, row and column count from 0
  cout << a(x, y) << endl;
  return 0;
}


2
//date.h
#ifndef date_h
#define date_h
#include <iostream>
using namespace std;

class Date {
    friend ostream & operator<<(ostream &os, const Date &one);
    friend bool operator<(const Date &d1, const Date &d2);
    int year;
    int month;
    int day;
public:
    Date(int y=1900,int m=1, int d=1) {
        switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:if (d <= 31 && d > 0) {year = y;month = m;day = d;}else {year = 1900;month = 1;day = 1;}break;
        case 4:
        case 6:
        case 9:
        case 11:if (d <= 30 && d > 0) {year = y;month = m;day = d;}else {year = 1900;month = 1;day = 1;}break;
        case 2:if (((y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && d <= 29 && d > 0) || !(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && d <= 28 && d > 0) {year = y;month = m;day = d;}else {year = 1900;month = 1;day = 1;}break;
        default:{year = 1900;month = 1;day = 1;}
        }
    }

    Date & operator++() {
        day++;
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:if (day > 31) {day -= 31;month++;}break;
            case 2: if (day > 29 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {day -= 29;month++;}else if (day > 28 && !(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {day -= 28;month++;}break;
            default:if (day > 30) {day -= 30;month++;}break;
        }
        if (month > 12) {month = 1;year++;}
        return *this;
    }
    Date & operator+=(int n) {
        for (int i=0;i<n;i++) ++*this;
        return *this;
    }
    Date operator++(int) {
        Date tmp = *this;
        ++*this;
        return tmp;
    }
    void setDate(int y=1900,int m=1,int d=1) {
        switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:if (d <= 31 && d > 0) {year = y;month = m;day = d;}break;
        case 4:
        case 6:
        case 9:
        case 11:if (d <= 30 && d > 0) {year = y;month = m;day = d;}break;
        case 2:if (((y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && d <= 29 && d > 0) || !(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && d <= 28 && d > 0) {year = y;month = m;day = d;}break;
        default:{year = 1900;month = 1;day = 1;}
        }
    }
    int getyear() {return year;}
    int getmonth() {return month;}
    int getday() {return day;}
};
#endif

//date.cpp
#include "date.h"
ostream & operator<<(ostream &os, const Date &one) {
    os << one.year << '-' <<one.month << '-' << one.day;
    return os;
}
bool operator<(const Date &d1, const Date &d2) {
    if (d1.year < d2.year || d1.year == d2.year && d1.month < d2.month || d1.year == d2.year && d1.month == d2.month && d1.day < d2.day) return true;
    else return false;
}

//main.cpp
#include<iostream>
using namespace std;
#include "date.h"
int main()
{
     int day,month,year;
     cin>>year>>month>>day;
     Date d1; // 默认值为1900年1月1日
     Date d2(year,month,day);
     cin>>year>>month>>day;
     Date d3(year,month,day);

     cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3<<endl;
     cout << "d2+=7 is " << ( d2 += 7 )<<endl;

     d3.setDate( d3.getyear(),d3.getmonth(), d3.getday()+5);//重新设置日期，如果新日期非法，则保持原日期不变
     cout << "d3 is " << d3<<endl; //
     cout << "++d3 is " << ++d3 <<endl;

     Date d4( 2002,6,20 );

     cout << "d4 is " << d4 << endl;
     cout << "d4++ is " << d4++ << endl;
     cout << "d4 is " << d4 << endl;
     cout << "d3<d4 is "<<((d3<d4)?"true":"false")<<endl;
     return 0;
}

3
//myvect.h
#ifndef myvect_h
#define myvect_h
#include <iostream>
#include <cmath>
using namespace std;
class MyVect {
    friend MyVect operator+(const MyVect &v1, const MyVect &v2);
    friend ostream & operator<<(ostream &os, const MyVect &obj);
    friend istream & operator>>(istream &is, MyVect &obj);
    friend bool operator==(const MyVect &v1, const MyVect &v2);
    friend bool operator!=(const MyVect &v1, const MyVect &v2);
    static int living;
public:
    int dim;
    int *p;
    MyVect(int n=0) {
        dim = n;
        p = new int[n];
        living++;
    }
    ~MyVect() {
        delete [] p;
        living--;
    }
    MyVect(const MyVect &obj)
    {
        dim = obj.dim;
        p = new int[obj.dim];
        for (int i=0;i<dim;i++) p[i] = obj.p[i];
        living++;
    }
    MyVect & operator=(const MyVect &obj)
    {
        if (this == &obj) return *this;
        delete p;
        dim = obj.dim;
        p = new int[obj.dim];
        for (int i=0;i<dim;i++) p[i] = obj.p[i];
        return *this;
    }
    int operator[](int i) {int j = p[i];return j;}
    static int getliving() {return living;}
    int getlength() {return dim;}
    MyVect & operator++() {
        for (int i=0;i<dim;i++) p[i]++;
        return *this;
    }
    MyVect operator++(int) {
        MyVect tmp = *this;
        for (int i=0;i<dim;i++) p[i]++;
        return tmp;
    }
    double getnorm() {
        double count = 0;
        for (int i=0;i<dim;i++) count += p[i]*p[i];
        return sqrt(count);
    }
    double operator-(int n) {
        double count = 0;
        for (int i=0;i<dim;i++) count += p[i]*p[i];
        return sqrt(count)-n;
    }
    // operator double () const {double count = 0;
    //     for (int i=0;i<dim;i++) count += p[i]*p[i];
    //     return sqrt(count);}
};
#endif

//myvect.cpp
#include "myvect.h"
int MyVect::living = 0;
MyVect operator+(const MyVect &v1, const MyVect &v2)
{
    MyVect v3;
    v3.dim = v2.dim;
    v3.p = new int[v3.dim];
    for (int i=0;i<v3.dim;i++) v3.p[i] = v1.p[i]+v2.p[i];
    return v3;
}
ostream & operator<<(ostream &os, const MyVect &obj)
{
    for (int i=0;i<obj.dim-1;i++) os << obj.p[i] << ' ';
    os << obj.p[obj.dim-1];
    return os;
}
istream & operator>>(istream &is, MyVect &obj)
{
    for (int i=0;i<obj.dim;i++) is >> obj.p[i];
    return is;
}
bool operator==(const MyVect &v1, const MyVect &v2)
{
    for (int i=0;i<v1.dim;i++) if (v1.p[i] != v2.p[i]) return false;
    return true;
}
bool operator!=(const MyVect &v1, const MyVect &v2)
{
    for (int i=0;i<v1.dim;i++) if (v1.p[i] != v2.p[i]) return true;
    return false;
}

//main.cpp
#include <iostream>
using namespace std;
#include "myvect.h"
int main()
{
    int n;
    cin>>n;
    MyVect v1(n);
    double x;
    cin >> v1;
    cout << "Now v1 is: "<< v1 << endl;
    cout << "The length of v1 is " << v1.getlength() << endl;
    cout << "The norm of v1 is " << v1.getnorm() << endl;
    x = v1 - 1.0;
    cout << "The norm of v1 minus 1 is " << x << endl;
    MyVect v2 = v1;
    cout << "Now v2 is: " << v2 << endl;
    //cout << "The number of vectors is: " << v1.getcount() << endl;
    cout << endl;
    {
        MyVect v3(n);
        v3= v1 + v2;
        cout << "The result of v1+v2 is: " << v3 << endl;
        cout << "The 1st element of v3 is " << v3[1] << endl;
        //cout << "The number of vectors is: " << MyVect::getcount() << endl;
    }
    cout << endl;
    cout << "The number of living vectors is: " << v1.getliving() << endl;
    //cout << "The number of total vector is: " << v1.getcount() << endl;
    cout << "The result of v1++ is: " << v1++ << endl;
    cout << "The result of v1==v2 is " << (v1==v2) << endl;
    cout << "The result of ++v2 is: " << ++v2 << endl;
    cout << "The result of v1==v2 is " << (v1==v2) << endl;
    return 0;
}


4
//LongLongInt.h
#ifndef longlongint_h
#define longlongint_h
#include <iostream>
#include <cstring>
using namespace std;

class LongLongInt {
    friend LongLongInt operator+(LongLongInt &i1, LongLongInt &i2);
    friend LongLongInt operator-(const LongLongInt &i1, const LongLongInt &i2);
    friend ostream & operator<<(ostream &os, const LongLongInt &obj);
public:
    int *p;
    int len;
    LongLongInt(char a[]) {
        len = strlen(a);
        p = new int[len];
        for (int i=0;i<len;i++) p[i] = (a[i]-'0');
    }
    LongLongInt(const LongLongInt &obj)
    {
        len = obj.len;
        p = new int[len];
        for (int i=0;i<len;i++) p[i] = obj.p[i];
    }
    LongLongInt &operator=(const LongLongInt &obj)
    {
        if (this == &obj) return *this;
        len = obj.len;
        p = obj.p;
        return *this;
    }
};
#endif

//LongLongInt.cpp
#include "LongLongInt.h"
ostream & operator<<(ostream &os, const LongLongInt &obj)
{
    for (int i=0;i<obj.len;i++) os << obj.p[i];
    return os;
}
LongLongInt operator+(LongLongInt &i1,LongLongInt &i2)
{
    if (i1.len < i2.len) {
        LongLongInt tmp = i1;
        i1 = i2;
        i2 = tmp;
    }
    LongLongInt i3=i1;
    i3.len = i1.len+1;
    i3.p = new int[i3.len];
    for (int i=0;i<i3.len;i++) i3.p[i] = 0;
    int carry = 0,i=1;
    for (i=1;i<=i2.len;i++) {
        int tmp = (i2.p[i2.len-i]+i1.p[i1.len-i]+carry);
        i3.p[i3.len-i] = tmp % 10;
        carry = tmp / 10;
    }
    while (i <= i1.len) {
        int tmp = (i1.p[i1.len-i]+carry);
        i3.p[i3.len-i] = tmp % 10;
        carry = tmp / 10;
        i++;
    }
    if (carry == 1) i3.p[0] = 1;
    else {i3.len--;for (int j=0;j<i3.len;j++) i3.p[j] = i3.p[j+1];}
    return i3;
}
LongLongInt operator-(const LongLongInt &i1, const LongLongInt &i2)
{
    LongLongInt i3=i1;
    for (int i=0;i<i3.len;i++) i3.p[i] = 0;
    int i=1;
    for (i=1;i<=i2.len;i++) i3.p[i3.len-i] = i1.p[i1.len-i]-i2.p[i2.len-i];
    for (;i<=i1.len;i++) i3.p[i3.len-i] = i1.p[i1.len-i];
    for (i=i3.len;i>=0;i--) {
        if (i3.p[i] < 0) {i3.p[i] += 10;i3.p[i-1]--;}
    }
    i=0;
    while (i3.p[i] == 0 && i != i3.len-1) i++;
    i3.len -= i;
    for (int j=0;j<i3.len;j++) i3.p[j] = i3.p[j+i];
    return i3;
}

//demo.cpp
#include "LongLongInt.h"
#include <iostream>
#include <cstring>
using namespace std;

void demo(char a[],char b[])
{
    LongLongInt aLong(a);
    LongLongInt bLong(b);
    LongLongInt cLong = aLong+bLong;
    cout<<cLong<<endl<<aLong-bLong<<endl;
}
//main.cpp is concealed.



