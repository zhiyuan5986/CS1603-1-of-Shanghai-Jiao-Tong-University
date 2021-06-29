1
#include <iostream>
#include <cstring>
using namespace std;

bool func(char *array, int len) {
	//此处填补几行代码
    if (len == 1) return 1;
    if (len == 2 || *array == *array+1) return 1;
    if (*array == *(array+len-1)) return func(array+1,len-2);
    else return 0;
}


int main() {
    char ch[20];
    bool result;

    cin >> ch;

	//此处填补几行代码
    result = func(ch,strlen(ch));
    if (result) cout << "Yes";
    else cout << "No";
    return 0;
}


2
#include <iostream>

using namespace std;
void compare(int a[], int n, int &max1, int &max2);
int main()
{
    int n, max1,max2;
    cin >> n;
    int *p = new int [n];
    for (int i=0;i<n;i++) cin >> p[i];
    compare(p,n,max1,max2);
    cout << max1 <<' ' <<max2;

    return 0;
}
void compare(int a[],int n,int &max1, int &max2)
{
    int m1,m2,n1,n2,num;
    switch(n)
    {
        case 1:max1 = max2 = a[0];return;
        case 2:if (a[0] > a[1]) {max1 = a[0];max2 = a[1];}
                else {max1 = a[1];max2 = a[0];}
                return;
        case 3:{int tmp1 = a[0],tmp2 = a[1], tmp3 = a[2];
                if (tmp1 < tmp2) {int tmp = tmp1;tmp1 = tmp2;tmp2 = tmp;}
                if (tmp1 < tmp3) {int tmp = tmp1;tmp1 = tmp3;tmp3 = tmp;}
                if (tmp2 < tmp3) {int tmp = tmp2;tmp2 = tmp3;tmp3 = tmp;}
                max1 = tmp1;max2 = tmp2;return;}
        default:compare(a,n/2,m1,m2);
                compare(a+n/2,n-n/2,n1,n2);
                if (m1 < n1) {max1 = n1;num = m1;}
                else {max1 = m1;num = n1;}
                if (m2 < n2) max2 = n2;
                else max2 = m2;
                if (max2 < num) max2 = num;
    }
}
