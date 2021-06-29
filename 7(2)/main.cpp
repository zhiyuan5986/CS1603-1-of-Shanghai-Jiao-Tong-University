1
#include <iostream>
using namespace std;

//此处填补2行代码
int myfun(int* a, int* b);
int myfun(int &a, int &b);
int main() {
    int x, y;
    cin >> x >> y;
    cout << myfun(x, y) << ' ';
    cout << x << ' ' << y;
    return 0;
}
int myfun(int* a, int* b) {
    int c = *a - *b;
    *a *= 2;
    *b *= 3;
    return c;
}

//此处定义一个函数
int myfun(int &a, int &b)
{
    int c = (a-b)%10;
    a *= 3;
    b *= 2;
    return c;
}


2
#include <iostream>
using namespace std;

const char* strrchr(const char* str, char ch)
{
    int len=0;
    while (str[len] != '\0') len++;
    while (str[len] != ch && len != 0) len--;
    if (len != 0) {const char *p = str+len;return p;}
    else return NULL;

}

int main()
{
    char arr[50], ch;
    const char *p;
    cin >> arr;
    cin >> ch;
    if ((p = strrchr(arr,ch)) != NULL) {int i=0;while (*(p+i) != '\0') {cout << *(p+i);i++;}}
    else cout << "no";
    return 0;
}

3
#include <iostream>
using namespace std;
char *oddstr(char *a)
{
    char *p = new char[200];
    int len = 0;
    while (*a != '\0' && *(a+1) != '\0') {p[len] = *(a+1);a += 2;len++;}
    p[len+1] = '\0';
    return p;

}
int main() {
    char str[200];
    cin >> str;
    char *odd = oddstr(str);
    cout << odd << endl;
    delete [] odd;
    return 0;
}

