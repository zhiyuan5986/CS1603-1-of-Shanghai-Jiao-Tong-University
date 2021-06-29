1
#include <iostream>
using namespace std;

int main()
{
    char *arr = new char[100];
    char *out = new char[10];
    int *p = new int[10];
    cin.getline(arr,100);
    cin >> out;
    int i=0;
    int j=1;
    p[0] = 0;
    while (arr[i] != '\0') {
        if (arr[i] == ' ') {i++;p[j] = i;j++;}
        else i++;
    }
    p[j] = i;
    cout << j << endl;
    for(int k=0;k<j;k++) {
        for(int m=p[out[k]-'0'];m<p[out[k]-'0'+1];++m) cout << arr[m];
        if (out[k]-'0' == j-1) cout << ' ';
        }
    return 0;
}

2
#include <iostream>
#include <cstring>
using namespace std;
void getDate(int &day, int &month, int &year)
{
    char d[3], m[4], y[3];
    char *mstandard[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    cin.getline(d,3,'-');
    cin.getline(m,4,'-');
    cin.getline(y,3);
    int i=0;
    while (d[i] != '\0') {day = day*10+d[i]-'0';i++;}
    i=0;
    while (true) {if (strcmp(m,mstandard[i]) == 0) break;i++;}
    month = i+1;
    i=0;
    while (y[i] != '\0') {year = year*10+y[i]-'0';i++;}
}
int main()
{
    int day=0, month=0, year=0;
    getDate(day, month, year);
    cout << day <<" "<< month<<" " << year << endl;
    return 0;
}

3
#include <iostream>
#include <cstring>
using namespace std;
char* julian(int year, int day)
{
    static char result[10];
    int day1[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int day2[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    char num[] = "0123456789";
    char *mstandard[12] = {"Jan ","Feb ","Mar ","Apr ","May ","Jun ","Jul ","Aug ","Sep ","Oct ","Nov ","Dec "};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        if (day <= 0 || day > 366) return NULL;
        int i=0;
        while (day > day2[i]) {day -= day2[i];i++;}
        for(int j=0;j<3;j++) result[j] = mstandard[i][j];
        result[3] = ' ';
        result[4] = num[day/10];
        result[5] = num[day%10];
        result[6] = '\0';
    }
    else {
        if (day <= 0 || day > 365) return NULL;
        int i=0;
        while (day > day1[i]) {day -= day1[i];i++;}
        for(int j=0;j<3;j++) result[j] = mstandard[i][j];
        result[3] = ' ';
        result[4] = num[day/10];
        result[5] = num[day%10];
        result[6] = '\0';
    }
    return result;
}
int main()
{
    int year,day;
    char* res;
    cin>>year>>day;
    res=julian(year,day);
    cout<<res<<endl;
    delete []res;
    return 0;
}

4
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >>n;
    char **p = new char*[n];
    for (int i=0;i<n;++i) p[i] = new char[100];
    char **q = new char*[n];
    for (int i=0;i<n;++i) q[i] = new char[100];
    for (int i=0;i<n;++i) cin >> p[i];
    char ch;
    cin >>ch;

    for (int i=0;i<n;++i)
    {
        int j=0;
        int k=0;
        while (p[i][j] != '\0') {
            if (p[i][j] != ch) {q[i][k] = p[i][j];j++;k++;}
            else j++;
        }
        q[i][k] = '\0';
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n-1;++j) {
            if (strcmp(q[j],q[j+1]) < 0) {char *x=q[j];q[j] = q[j+1];q[j+1] = x;}
        }
    }
    for(int i=0;i<n;++i) cout << q[i] << endl;
    for (int i=0;i<n;++i) {delete [] p[i];delete [] q[i];}
    delete [] p;
    delete [] q;
    return 0;
}


5
#include <iostream>
using namespace std;

void add_float(char* a, char* b,char*res) {
    char num[] = "0123456789";
    char *p = new char[128], *res1;
    p[127] = '\0';
    int i=0,j=0,i1=0,j1=0;
    while (a[i] != '.' && a[i] != '\0') i++;//小数点位置
    while (b[j] != '.' && b[j] != '\0') j++;
    while (a[i1] != '\0') i1++;//'\0'位置
    while (b[j1] != '\0') j1++;//no problem
    if (i1-i < j1-j) {char *tmp = a;a=b;b=tmp;int tmp1 = i1;i1 = j1;j1 = tmp1;int tmp2 = i;i=j;j=tmp2;}
    int k=0;
    for (;k<i1+j-i-j1;++k) p[126-k] = a[i1-k-1];//no problem
    //cout << p[125] << p[126] << k;
    int tmp=0;
    for (int m=1;m<j1-j;++m) {
            if  ((a[i1-k-m]-'0')+(b[j1-m]-'0')+tmp < 10) {p[127-k-m] = num[(a[i1-k-m]-'0')+(b[j1-m]-'0')+tmp];tmp=0;}
            else {p[127-k-m] = num[(a[i1-k-m]-'0')+(b[j1-m]-'0')+tmp-10];tmp=1;}
    }
    p[127-i1+i] = '.';
    int m=0;
    while (m != i && m != j) {
        if ((a[i-m-1]-'0')+(b[j-m-1]-'0')+tmp < 10) {p[126-i1+i-m]  = num[(a[i-m-1]-'0')+(b[j-m-1]-'0')+tmp];tmp=0;m++;}
        else {p[126-i1+i-m]  = num[(a[i-m-1]-'0')+(b[j-m-1]-'0')+tmp-10];tmp=1;m++;}
    }
    if (m == i && m != j) {
//        if (tmp == 1) {p[126-i1+i-m] = num[(b[j-m-1]-'0')+tmp];m++;}
//        else {p[126-i1+i-m] = num[(b[j-m-1]-'0')];m++;}
        while (m != j) {
                if ((b[j-m-1]-'0')+tmp < 10){
                    p[126-i1+i-m] = num[(b[j-m-1]-'0')+tmp];
                    tmp = 0;
                }
                else {p[126-i1+i-m] = num[(b[j-m-1]-'0')+tmp-10];
                tmp = 1;
                }
                m++;}
        if (tmp == 1) {p[126-i1+i-m] = '1';res1 = p+126-i1+i-m;}
        else res1 = p+127-i1+i-m;
    }
    else if (m == i && m == j) {
        if (tmp == 1) {p[126-i1+i-m] = '1';res1 = p+126-i1+i-m;}
        else res1 = p+127-i1+i-m;
    }
    else if (m != i && m == j) {
        while (m != i) {
                if ((a[i-m-1]-'0')+tmp < 10){
                    p[126-i1+i-m] = num[(a[i-m-1]-'0')+tmp];
                    tmp = 0;
                }
                else {p[126-i1+i-m] = num[(a[i-m-1]-'0')+tmp-10];
                tmp = 1;
                }
        m++;
        }
        if (tmp == 1) {p[126-i1+i-m] = '1';res1 = p+126-i1+i-m;}
        else res1 = p+127-i1+i-m;
    }
    //cout << p[122] << p[123] << p[124] << p[125];
    while (*res1 == '0') res1++;
    char *q = p+126;
    while (*q == '0') q--;
    *(q+1) = '\0';
    int n=0;
    while (res1[n] != '\0') {res[n] = res1[n];n++;}
    res[n] = '\0';
    delete [] p;
    //cout << res;
    //cout << (p+120);
}


int main()
{
    char num1[128], num2[128], res[128];
    cin >> num1;
    cin >> num2;
    add_float(num1, num2, res);
    cout << res << endl;
    return 0;
}


6
#include <iostream>
#include <cstring>
using namespace std;

// 写出两个函数的声明
char *&funA(char **&p);
char *funB(char *b,char **&p);
int main()
{
    char a[100], b[100];
    for(int i = 0; i < 3; ++i)
    {
        char **p;
        cin >> a;
        funA(p) = a;
        cout << funB(b, p) << endl;
        delete p;
    }
    return 0;
}


// 写出两个函数的定义
char* &funA(char **&p)
{
    p = new char*;
    return *p;
}
char* funB(char *b,char **&p)
{
    int i=0;
    while (*(*p+i) != '\0') {
        if (*(*p+i) <= 'z' && *(*p+i) >= 'a') b[i]=*(*p+i)-'a'+'A';
        else b[i] = *(*p+i);
        i++;
    }
    b[i]='\0';
    return b;
}

7
#include <iostream>
using namespace std;

int main()
{
    char *str = new char[9];
    int n;
    cin >> str;
    cin >> n;

    int num1[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int num2[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    char num[] = "0123456789";
    int year=0;
    for (int i=0;i<=3;++i) year = year*10+str[i]-'0';
    int month=str[5]-'0'+10*(str[4]-'0');
    int day = str[7]-'0'+10*(str[6]-'0');
    while (n >= 366) {
        if (((year+1) % 4 == 0 && (year+1) % 100 != 0 || (year+1) % 400 == 0) && month > 2) {n -= 366;year++;}
        else {n -= 365;year++;}
    }
    if (n == 365 && !(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {year++;n=0;}
    day = day+n;
    if (year >= 10000) {cout << "out of limit!";return 1;}
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        int *p = num2;
        while (day > p[month-1]) {
            day -= p[month-1];
            if (month == 12) {year++;month=1;p = num1;}
            else month++;
        }
    }
    else {
        int *p = num1;
        while (day > p[month-1]) {
            day -= p[month-1];
            if (month == 12) {year++;month=1;if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) p=num2;}
            else month++;
            }
    }
    for (int i=3;i >= 0;i--) {str[i] = num[year%10];year /= 10;}
    str[5] = num[month%10];
    str[4] = num[month/10];
    str[7] = num[day%10];
    str[6] = num[day/10];
    cout << str;
    return 0;
}

8
#include <iostream>
using namespace std;

int main()
{
    char str1[20],str2[20];
    char c,*cp;
    //不得再增加其它任何变量
    cin >> str1;
    cin >> str2;
    cp = str2;
    c = '0';
    while (*(str1+(c-'0')) != '\0' && *cp != '\0') {cout << *cp;++cp;c = (c-'0'+1)+'0';}
    if (*cp == '\0') {
        while (*(str1+(c-'0')) != '\0') {cout << *(str1+(c-'0'));c = (c-'0'+1)+'0';}
    }
    cout << endl;
    c = '0';
    cp = str1;
    while (*(str2+(c-'0')) != '\0' && *cp != '\0') {cout << *cp;++cp;c = (c-'0'+1)+'0';}
    if (*cp == '\0') {
        while (*(str2+(c-'0')) != '\0') {cout << *(str2+(c-'0'));c = (c-'0'+1)+'0';}
    }
    return 0;
}
