1
#include <iostream>
using namespace std;

int main()
{
    int n, m, sum=0;
    cin >> n;
    for (int j=0;j<10;++j) {
        m=n;
        sum=0;
        while (m!=0) {
            n=m%10;
            m/=10;
            sum += n;
        }
        n=sum;
    }
    cout << sum;
    return 0;
}

2
#include <iostream>
using namespace std;

int main()
{
    int n, zheng=0, fu=0;
    do {
        cin >> n;
        if (n<0) ++fu;
        if (n>0) ++zheng;
    } while (n != 0);
    cout << zheng << ' ' << fu;
    return 0;
}


3
#include <iostream>
using namespace std;

int main()
{
    int n, m, tmp;
    cin >> n >> m;
    if (n<m) {
        tmp = n;
        n = m;
        m = tmp;//保证n更大
    }
    while (n%m != 0) {
        tmp = n;
        n = m;
        m = tmp%m;
    }
    cout << m;
    return 0;
}


4
#include <iostream>

using namespace std;
int rev(int &x);

int main()
{
    int n, sum=0;
    cin >> n;
    for (int x=1;x<n;++x) {
        if (rev(x)+x == n) sum++;
   }
   cout <<sum;
    return 0;
}
int rev(int &x)
{
    int m, n, result=0;
    m = n = x;
    while (m != 0) {
        n = m%10;
        m/=10;
        result = result*10+n;
    }
    return result;
}

5
#include <iostream>
using namespace std;

int main()
{
    int n, sum=0;
    cin >> n;
    while (n%3 == 0) {n = n*2/3;++sum;}
    while (n%5 == 0) {n = n*4/5;++sum;}
    while (n%2 == 0) {n /=2;++sum;}
    if (n == 1) cout << sum;
    else cout << -1;
    return 0;
}


6
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n << ' ';
    while (n != 1) {
        if (n%2 == 0) {n /= 2;cout << n << ' ';}
        else {n = 3*n+1;cout << n <<' ';}
    }
    return 0;
}


7
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >>n;
    while (n % 2 == 0) n/=2;
    if (n == 1) cout << "true";
    else cout <<"false";
    return 0;
}


8
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, p, x=1, sum=0;
    cin >> n >>p;
//    for (int i=1;i<=n;++i) {
//            tmp=i;
//            while(tmp%p == 0) {tmp/=p;++sum;}
//    }
    while (pow(p,x) < n) ++x;
    for (int i=1;i<=x;++i) {
        sum += n / pow(p,i);
    }
    cout << sum;
}

9
#include <iostream>
using namespace std;

int main()
{
    int f1=1, f2=2, tmp, n;
    cin >> n;
    if (n == 1) cout << 1;
    if (n == 2) cout << 2;
    if (n >=3) {
        for (int i=1;i<=n-2;++i) {
            tmp = f2;
            f2 = f1+f2;
            f1 = tmp;
        }
    cout << f2;
    }
    return 0;
}


10
#include <iostream>
using namespace std;

int main()
{
    int n, sum=0, min;
    cin >> n;
    min = n;
    for (int i = 0;i <=n/33;++i) {
        for (int j = 0;j <= n/23;++j) {
            for (int k = 0;k <= n/16;++k) {
                for (int l=0;l <= n/5;++l) {
                    for (int m = 0;m <= n;++m) {
                        sum=0;
                        if (33*i+23*j+16*k+5*l+m == n) sum = i+j+k+l+m;
                        if (sum < min && sum != 0) min = sum;
                    }
                }
            }
        }
    }
    cout << min << ' ';
    //贪心
    sum = 0;
    while (n >= 33) {n -= 33;++sum;}
    if (n < 33 && n >= 23) {n -= 23;++sum;}
    if (n < 23 && n >= 16) {n -= 16;++sum;}
    while (n < 16 && n >= 5) {n -= 5;++sum;}
    while (n < 5 && n >= 1) {n -= 1;++sum;}
    cout << sum;
    return 0;
}

