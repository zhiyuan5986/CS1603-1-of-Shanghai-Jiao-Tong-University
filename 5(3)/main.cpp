1
#include <iostream>
using namespace std;

int main()
{
    char a[80], b;
    cin.getline(a,80);
    b = cin.get();
    int i=0, max=-1;
    while (a[i] != '\0') {
        if (a[i] == b) max = i;
        i++;
    }
    if (max == -1) cout << "Not Found";
    else cout << max;
    return 0;
}

2
#include <iostream>
using namespace std;

int main()
{
    char a[80],tmp;
    int j, k=1;
    cin.getline(a,80);
    for (int i = 0;i < 80;++i) {
        j = 1;
        while (a[j] != '\0') {
            if (a[j-1] < a[j]) {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
            j++;
        }
    }
    cout << a[0];
    while (a[k] != '\0') {
        if (a[k] != a[k-1]) cout << a[k];
        k++;
    }
    return 0;
}

3
#include <iostream>
using namespace std;

int main()
{
    char a[80];
    int tmp=0;
    cin.getline(a,80);
    while (a[tmp] != '\0') {tmp++;}
    for (int i=1;i<tmp;i += 2) cout << a[i];
    return 0;
}

4
#include <iostream>
using namespace std;

int main()
{
    int c=0, b=0, tmp=0;
    char a[80], flag;
    cin.getline(a,80);
    while (a[tmp] != '+' && a[tmp] != '-' && a[tmp] != '*' && a[tmp] != '/') {c = c*10+a[tmp]-'0';tmp++;}
    flag = a[tmp];
    tmp++;
    while (a[tmp] != '\0') {b = b*10+a[tmp]-'0';tmp++;}
    switch (flag) {
        case '+':{cout << c << '+' << b << '=' << c+b;break;}
        case '-':{cout << c << '-' << b << '=' << c-b;break;}
        case '*':{cout << c << '*' << b << '=' << c*b;break;}
        case '/':cout << c << '/' << b << '=' << c/b;
    }
    return 0;
}

5
#include <iostream>
using namespace std;

int main()
{
    int n, num1=0, num2=0, num3=0, j=0;
    cin >> n;
    n *= 80;
    char a[n], b;
    while (cin >> b) {
        a[j] = b;
        j++;
    }
    a[j] = '\0';
    j = 0;
    while (a[j] != '\0') {
        if (a[j] != ' ' && a[j] != '\n') {
            if (a[j] <= 'Z' && a[j] >= 'A' || a[j]<= 'z' && a[j] >= 'a') num1++;
            else if (a[j] >= '0' && a[j] <= '9') num2++;
            else num3++;
        }
        j++;
    }
    cout << "??????????" << num1 << endl;
    cout << "??????" << num2 <<endl;
    cout << "??????????" << num3;
}
//     char a[n][80];
//     for (int i=0;i<n;++i) cin.getline(a[i],80);
//     for (int i=0;i<n;++i) {
//         j=0;
//         while (a[i][j] != '\0') {
//             if (a[i][j] != ' ') {
//                 if (a[i][j] <= 'Z' && a[i][j] >= 'A' || a[i][j]<= 'z' && a[i][j] >= 'a') num1++;
//                 else if (a[i][j] >= '0' && a[i][j] <= '9') num2++;
//                 else num3++;
//             }
//             j++;
//         }
//     }
//     cout << "??????????" << num1 << endl;
//     cout << "??????" << num2 <<endl;
//     cout << "??????????" << num3;
//     return 0;
// }

6
#include <iostream>
using namespace std;

int main()
{
    char str1[160], str2[160];
    cin.getline(str1,160);
    cin.getline(str2,160);
    int i=0, j=0, flag = 0;
    while (str1[i] != '\0') {
        if (str1[i] == str2[0]) {
            j=0;
            flag = 0;
            while (str2[j] != '\0') {
                if (str1[i+j] != str2[j]) {flag = 1;break;}
                j++;
            }
            if (flag) {i++;continue;}
            else {cout << i;return 0;}
        }
        i++;
    }
    cout << -1;
    return 0;
}

7
#include <iostream>
using namespace std;
bool isalpha1(char ch);
int main()
{
    int j=0, a=0, b=0, len, flag = 0, sum=0, max=0, m, n;
    char str[10000], c;
    while (cin) {cin.get(c);
    str[j] = c;
    j++;
    }
    len = j-1;
    str[j] = '\0';
    for (int i=0;i<len;i++) {
        for (int j=1;j<=len;j++) {
            if ((isalpha1(str[i]) == false) || (isalpha1(str[j]) == false)) continue;
            a = i;
            b = j;
            flag = 0;
            sum = 0;
            while (a<=b) {
                while (isalpha1(str[a]) == false || str[a] == '\n') a++;
                while (isalpha1(str[b]) == false || str[b] == '\n') b--;
                if ((str[a] == str[b] || str[a] == str[b]+'A'-'a' || str[b] == str[a]+'A'-'a') && a < b) {a++;b--;sum += 2;}
                else if (a == b) {sum++;break;}
                else if (a > b) break;
                else {flag = 1;break;}
            }
            if (flag == 1) continue;
            if (sum > max) {max = sum;m = i;n = j;}
        }
    }
    cout << max << endl;
    for (int i = m;i <= n; ++i) cout << str[i];
    return 0;
}
bool isalpha1(char ch)
{
    return (ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a');
}


8
#include <iostream>

using namespace std;

int main()
{
    int max=0, len=0, array[26] = {0}, n, j;
    char arr[100];
    cin.getline(arr,100);
    while (arr[len] != '\0') len++;
    for (int i=0;i<len;++i) {
        for (int p=0;p<26;++p) array[p] = 0;
        n=arr[i]-'a';
        array[n]++;
        j=i+1;
        while (j<=len) {
            n = arr[j]-'a';
            if (array[n] == 0) array[n]++;
            else {if (max < j-i) max = j-i;break;}
            j++;
        }
    }
    cout << max;
    return 0;
}
