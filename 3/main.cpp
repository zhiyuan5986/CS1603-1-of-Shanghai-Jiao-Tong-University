1
#include <iostream>
using  namespace std;
int main()
{
    int g, scale;
    cin >> g;
    scale = g/10;
    switch (scale) {
        case 10:
        case 9: cout << 'A'; break;
        case 8: cout << 'B'; break;
        case 7: cout << 'C'; break;
        case 6: cout << 'D'; break;
        default: cout << "F";
    }
    return 0;
}

2
#include <iostream>
using  namespace std;
int main()
{
    char c;
    cin >> c;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cout << "vowel";
    else cout << "consonant";
    return 0;
}

3
#include <iostream>
using  namespace std;
int main()
{
    int a, b, c, tmp = 0;
    cin >> a >> b >> c;
    if (a < b) {tmp = a; a = b; b = tmp;}
    if (b < c) {tmp = b; b = c; c = tmp;}
    if (a < c) {tmp = a; a = c; c = tmp;}
    cout << a << ' ' << b << ' ' << c;
    return 0;
}

4
#include <iostream>
using  namespace std;
int main()
{
    int num, reverse;
    cin >> num;
    reverse = num/10000+(num-num/10000*10000)/1000*10+(num-num/1000*1000)/100*100+(num-num/100*100)/10*1000+(num-num/10*10)*10000;
    cout << (reverse == num ? "Yes" : "No");
    return 0;
}

5
#include <iostream>
using  namespace std;
int main()
{
    char c, c1;
    cin >> c;
    if ('a' <= c && c <= 'z') {c1 = c-'a'+'A';cout << c1;}
        else if ('A' <= c && c <= 'Z') {c1 = c-'A'+'a';cout << c1;}
        else cout << c;
    return 0;
}

6
#include <iostream>
using  namespace std;
int main()
{
    char type;
    int enter, exit, time;
    cin >> type >> enter >> exit;
    time = exit - enter;
    if (type == 'c') {
        if (time <= 3) cout << 5*time;
        else cout << 10*time-15;
    }
    else if (type == 'b') {
        if (time <= 2) cout << 10*time;
        else cout << 15*time-10;
    }
    else {
        if (time <= 1) cout << 10*time;
        else cout << 15*time-5;
    }
    return 0;
}

7
#include <iostream>
using  namespace std;
int main()
{
    double x, y, d1, d2, d3, d4;
    cin >> x >> y;
    d1 = (x-2)*(x-2)+(y-2)*(y-2);
    d2 = (x-2)*(x-2)+(y+2)*(y+2);
    d3 = (x+2)*(x+2)+(y-2)*(y-2);
    d4 = (x+2)*(x+2)+(y+2)*(y+2);
    if (d1 <= 1 || d2 <= 1 || d3 <= 1 || d4 <= 1) cout << 10;
    else cout << 0;
    return 0;
}

8
#include <iostream>
using  namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (a > 11 && a-b>2 || b > 11 && b-a>2 || a < 0 || b < 0) cout << "Illegal";
    else if (b <=9 && a == 11 || a-b == 2 && a > 11) cout << "A win";
    else if (a <=9 && b == 11 || b-a == 2 && b > 11) cout << "B win";
    else cout << "In progress";
    return 0;
}

9
#include <iostream>
using  namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a+b>c && b+c>a && a+c>b) {
        cout << "yes" << endl;
        if (a*a+b*b == c*c || a*a+c*c == b*b || b*b+c*c == a*a) cout << "yes";
        else cout << "no";
    }
    else cout << "no";
    return 0;
}

10
#include <iostream>
using  namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if (m>=2*n) cout << 2*n-m/2 << " " << m/2-n;
    else cout << "no solution";
    return 0;
}

11
#include <iostream>
using  namespace std;
int main()
{
    int y, m, d, flag=1;
    cin >> y >> m >> d;
    if (m>12 || d > 31) {cout << "Illegal";flag=0;}
    if (m <= 12 && d <= 31) {
        switch (m) {
        case 2: if (y%4 == 0 && y%100 != 0 || y%400 == 0){
                    if (d>29) {cout << "Illegal";flag=0;break;}
                }
                else {
                    if (d>28) {cout << "Illegal";flag=0;break;}
                }
        case 4:
        case 6:
        case 9:
        case 11:if (d > 30) {cout << "Illegal";flag=0;}
        }
    }
    if (flag) {
        if (m <= 2) cout << 31*(m-1)+d;
        else cout << ((y%4 == 0 && y%100 != 0 || y%400 == 0) ? 31*(m-1)+d-(4*m+23)/10+1 : 31*(m-1)+d-(4*m+23)/10);
    }
    return 0;
}

12
#include <iostream>
using  namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    if (2147483647-a < b && a>0 && b>0 || a < -2147483648-b && a<0 && b<0) cout << "error";
    else cout << a+b;
    return 0;
}
