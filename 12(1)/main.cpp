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
    LongLongInt() {len=0;p = new int;}
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
#include "LLIComplex.h"
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


//LLIComplex.h
#ifndef longlongintcomplex_h
#define longlongintcomplex_h
#include <iostream>
#include <cstring>
#include "LongLongInt.h"
using namespace std;
class longlongintcomplex {
    friend ostream & operator<<(ostream &os, const longlongintcomplex &obj);
    friend longlongintcomplex operator+(longlongintcomplex &i1, longlongintcomplex &i2);
    LongLongInt r;
    LongLongInt c;
public:
    longlongintcomplex(char a[],char b[]):r(a),c(b) {}
    longlongintcomplex() {}
};
#endif

//LLIComplex.cpp
#include "LLIComplex.h"
#include "LongLongInt.h"
ostream & operator<<(ostream &os, const longlongintcomplex &obj)
{
    if (obj.c.p[0] == 0 && obj.c.len == 1) {
        os << obj.r;
    }
    else if (obj.r.p[0] == 0 && obj.r.len == 1) os << obj.c << 'i';
    else os << obj.r << '+' << obj.c << 'i';
    return os;
}
longlongintcomplex operator+(longlongintcomplex &i1,longlongintcomplex &i2)
{
    longlongintcomplex tmp;
    tmp.r = i1.r+i2.r;
    tmp.c = i1.c+i2.c;
    return tmp;
}
