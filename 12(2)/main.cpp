//signLongLongInt.h
#ifndef signLLI_h
#define signLLI_h
#include <iostream>
#include <cstring>
using namespace std;

class signLLI {
    friend signLLI operator+(const signLLI &i1,const signLLI &i2);
    friend signLLI operator-(const signLLI &i1,const signLLI &i2);
    friend signLLI add(const signLLI &tmp1,const signLLI &tmp2);
    friend signLLI sub(const signLLI &tmp1,const signLLI &tmp2);
    friend ostream & operator<<(ostream &os, const signLLI &obj);
public:
    int *p;
    int len;
    bool flag;
    signLLI(char a[]) {
        if (a[0] == '-') flag=1;
        else flag = 0;
        len = strlen(a)-flag;
        p = new int[len];
        for (int i=0;i<len;i++) {p[i] = (a[i+flag]-'0');}
    }
    signLLI() {len=0;flag=0;p = new int;}
    signLLI(const signLLI &obj)
    {
        len = obj.len;
        flag = obj.flag;
        p = new int[len];
        for (int i=0;i<len;i++) p[i] = obj.p[i];
    }
    signLLI &operator=(const signLLI &obj)
    {
        if (this == &obj) return *this;
        len = obj.len;
        flag = obj.flag;
        delete [] p;
        p = new int[len];
        for (int i=0;i<len;i++) p[i] = obj.p[i];
        return *this;
    }
    ~signLLI() {if (p) delete [] p;}
};
#endif


//signLongLongInt.cpp
#include "signLongLongInt.h"
ostream & operator<<(ostream &os, const signLLI &obj)
{
    if (obj.flag == 1) os << '-';
    for (int i=0;i<obj.len;i++) os << obj.p[i];
    return os;
}
signLLI add(const signLLI &tmp1,const signLLI &tmp2)
{
    signLLI i1,i2;
    if (tmp1.len < tmp2.len) {
        i1 = tmp2,i2 = tmp1;
    }
    else {i1 = tmp1,i2 = tmp2;}
    signLLI i3=i1;
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
signLLI sub(const signLLI &tmp1,const signLLI &tmp2)
{
    signLLI i1,i2;
    if (tmp1.len < tmp2.len) {
        i1 = tmp2;
        i2 = tmp1;
        i1.flag = 1-i1.flag;
        i2.flag = 1-i2.flag;
    }

    else {i1 = tmp1,i2 = tmp2;}
    signLLI i3=i1;
    for (int i=0;i<i3.len;i++) i3.p[i] = 0;
    int i=1;
    for (i=1;i<=i2.len;i++) {i3.p[i3.len-i] = i1.p[i1.len-i]-i2.p[i2.len-i];}
    for (;i<=i1.len;i++) i3.p[i3.len-i] = i1.p[i1.len-i];
    int j=0;
    while (i3.p[j] == 0) j++;
    if (i3.p[j] > 0) {
        for (i=i3.len-1;i>=0;i--) {
            if (i3.p[i] < 0) {i3.p[i] += 10;i3.p[i-1]--;}
        }
    }
    else {
        for (i=i3.len-1;i>=0;i--) {
            if (i3.p[i] > 0) {i3.p[i] -= 10;i3.p[i-1]++;}
        }
        for (int k=0;k<i3.len;k++) i3.p[k] = -i3.p[k];
        i3.flag = 1-i3.flag;
    }
    i=0;
    while (i3.p[i] == 0 && i != i3.len-1) i++;
    i3.len -= i;
    for (int j=0;j<i3.len;j++) i3.p[j] = i3.p[j+i];
    return i3;
}
signLLI operator+(const signLLI &i1,const signLLI &i2)
{
    if (i1.flag == 1 && i2.flag == 0) {signLLI tmp1 = i1,tmp2 = i2;tmp1.flag = 0;return sub(tmp2,tmp1);}
    if (i1.flag == 0 && i2.flag == 1) {signLLI tmp1 = i1,tmp2 = i2;tmp2.flag = 0;return sub(tmp1,tmp2);}
    return add(i1,i2);
}
signLLI operator-(const signLLI &i1,const signLLI &i2)
{
    if (i1.flag == 1 && i2.flag == 0) {signLLI tmp1 = i1,tmp2 = i2;tmp2.flag = 1;return add(tmp1,tmp2);}
    if (i1.flag == 0 && i2.flag == 1) {signLLI tmp1 = i1,tmp2 = i2;tmp2.flag = 0;return add(tmp1,tmp2);}
    return sub(i1,i2);
}
