1
//account.h
#ifndef saving_h
#define saving_h
#include <iostream>
#include <iomanip>
using namespace std;
class SavingAccount {
    float rate;
    static int total;
    double savingNum;
    int ID;
public:
    SavingAccount(int s) {total++;ID = total;savingNum = s;rate=0.05;}
    void display();
    void calculate() {
        savingNum = savingNum*(1+rate);
    }
    void changerate(float new_rate)
    {
        rate = new_rate;
    }
};
#endif

//account.cpp
#include "account.h"
int SavingAccount::total=0;
void SavingAccount::display(){
    cout<<ID<<" ";
    cout<<fixed<<setprecision(2);
    cout<<savingNum<<" "<<rate<<endl;
}

//main.cpp
#include "account.h"
#include <iostream>
using namespace std;

int main()
{
    // 1st month
    int first_money, second_money;
    cin>>first_money>>second_money;
    SavingAccount first(first_money);
    SavingAccount second(second_money);
    first.display();
    second.display();

    // 2nd month
    float new_rate;
    cin>>new_rate;
    first.calculate();
    first.display();
    second.calculate();
    second.display();
    first.changerate(new_rate);
    second.changerate(new_rate);

    // 3rd month
    int third_money;
    cin>>third_money;
    first.calculate();
    first.display();
    second.calculate();
    second.display();
    SavingAccount * p = new SavingAccount(third_money);

    // 4th month
    first.calculate();
    first.display();
    second.calculate();
    second.display();
    p->calculate();
    p->display();

    delete p;
    return 0;
}


2

//LongLongInt.h
#ifndef bigint_h
#define bigint_h
#include <iostream>
using namespace std;
class bigInt
{
    friend bigInt sum(const bigInt &i1, const bigInt &i2);
public:
    char *p;
    bigInt() {p = new char [1000];}
    void read();
    void show();
};
#endif

//LongLongint.cpp
#include "LongLongInt.h"
void bigInt::read()
{
    cin >> p;
}
void bigInt::show()
{
    cout << p;
}
bigInt sum(const bigInt &i1, const bigInt &i2)
{
    int l1=0,l2=0;
    while (*(i1.p+l1) != '\0') l1++;
    while (*(i2.p+l2) != '\0') l2++;
    char *q = new char [1000],num[11]="0123456789";
    int l=1, w=0;
    while (l1-l>=0 && l2-l>=0) {
        int tmp = (i1.p[l1-l]-'0')+(i2.p[l2-l]-'0')+w;
        q[l-1] = num[tmp%10];
        w = tmp/10;
        l++;
    }
    l--;
    if (l1 == l && l2 == l) {if (w == 1) {q[l] = '1';q[l+1] = '\0';} else q[l]='\0';}
    else if (l1 == l && l2 != l) {
        while (l2 != l) {
            int tmp = (i2.p[l2-l-1]-'0')+w;
            q[l]=num[tmp%10];
            w = tmp/10;
            l++;
        }
        if (w == 1) {q[l] = '1';q[l+1]='\0';}
        else q[l]='\0';
    }
    else if (l1 != l && l2 == l) {
        while (l1 != l) {
            int tmp = (i1.p[l1-l-1]-'0')+w;
            q[l]=num[tmp%10];
            w = tmp/10;
            l++;
        }
        if (w == 1) {q[l] = '1';q[l+1]='\0';}
        else q[l]='\0';
    }
    bigInt i3;
    int i=0;
    while (q[i] != '\0') i++;
    i--;
    for (int j=0;j<=i;j++) i3.p[j] = q[i-j];
    i3.p[i+1]= '\0';
    return i3;
}

//main.cpp
#include <iostream>
#include "LongLongInt.h"


using namespace std;

int main(){

    bigInt x1;
    bigInt x2;
    x1.read();
    x2.read();
    sum(x1,x2).show();
    return 0;
}


3
//mystack.h
#ifndef stack_h
#define stack_h
class mystack {

public:
    static int total;
    static int top;
    static int now;
    static int arr[100];
    mystack(int n) {total += n;}
    //~mystack() {total--;}
    bool isempty() {if (now == 0) return 1;else return 0; }
    bool isfull() {if (total == now) return 1;else return 0;}
    bool push(int i) {
        if (now >= total) return 0;
        else {mystack::arr[now] = i;now++;return 1;}
    }
    bool pop(int &data) {
        if (now == 0) return 0;
        else {data = mystack::arr[now-1];now--;return 1;}
    }
};
#endif

//mystack.cpp
#include "mystack.h"
int mystack::total=0;
int mystack::top=0;
int mystack::now=0;
int mystack::arr[100] = {};
