1
#include<iostream>
#include <cmath>
using namespace std;
void printInt(int n, int base);
int main()
{
    int n, base;
    cin >> n >> base;
    printInt(n, base);
	return 0;
}
void printInt(int n, int base)
{
    char result[1000], i=0;
    char array[17] = {"0123456789ABCDEF"};
    while (n != 0) {
        result[i] = array[n%base];
        n /= base;
        i++;
    }
    for (int j=i-1;j>=0;j--) cout << result[j];
}

2
int magic(int m){
    for (int i=1;i<=9;i++) {
        for (int j=0;j<=9;j++) {
            for (int k=0;k<=9;k++) {
                //if (((2*i+2*j+k)%10 == p) && ((2*i+2*k+j)%10+(2*i+2*j+k)/10 == q) && ((i+2*j+2*k+(2*i+2*k+j)/10 == r))) return i*100+j*10+k;
                if ((i+2*j+2*k)*100+(2*i+2*k+j)*10+2*i+2*j+k == m) return i*100+j*10+k;
            }
        }
    }
    return -1;
}

3
#include <iostream>
using namespace std;

int mystrstr(char a[], char b[]);

int main()
{
   char a[81], b[81];
   cin>>a;
   cin>>b;
   cout << mystrstr(a, b);
   return 0;
}
int mystrstr(char a[], char b[])
{
    int i=0, j, lena=0, lenb=0;
    while (a[lena] != '\0') lena++;
    while (b[lenb] != '\0') lenb++;
    for (int i=0;i<lena-lenb;i++) {
        j=0;
        while (a[i+j] == b[j] && j < lenb) j++;
        if (j == lenb) return i;
    }
    return -1;
}



4
#include <iostream>
using namespace std;

const int MAX_LENGTH = 10005;

//你的代码
void maxmin(int array[],int m);
void maxmin(double array[],int n);
int main()
{
    int m, n;
    int arr_int[MAX_LENGTH];
    double arr_double[MAX_LENGTH];

    // 输入m和整型数组
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> arr_int[i];
    }

    // 输入n和浮点型 数组
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr_double[i];
    }
    // 输出结果
    maxmin(arr_int, m);
    maxmin(arr_double, n);
}
void maxmin(int array[],int m)
{
    int max=array[m-1], min=array[0];
    for (int i=0;i<m;i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }
    cout << max << ' ' << min << endl;
}
void maxmin(double array[],int n)
{
    double max=array[n-1], min=array[0];
    for (int i=0;i<n;i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }
    cout << max << ' ' << min;
}

5
#include<iostream>
using namespace std;

int fib()
{
    static int a=0, b=1, tmp;
    tmp = b;
    b += a;
    a = tmp;
    return a;
}

