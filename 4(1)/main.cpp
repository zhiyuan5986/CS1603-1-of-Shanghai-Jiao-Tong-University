1
#include <iostream>
using namespace std;
int main()
{
    int a, b, c=0, d=4, array[5] = {1, 153, 370, 371, 407};
    cin >> a >> b;
    while (a > array[c]) c++;
    while (b < array[d]) d--;
    if (c < d) {
        for (int i = c; i <= d; i++) cout << array[i] << ' ';
    }
    else cout <<"no";
    return 0;

}

2
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, n, sum=0;
    cin >> a >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) sum += a*pow(10,j);
    }
    cout << sum;
    return 0;
}


3
#include <iostream>
using namespace std;

int main()
{
    int n, f0 = 0, f1 = 1, sum=0, tmp;
    cin >> n;
    if (n == 0) cout << 0;
    if (n == 1) cout << 1;
    if (n >= 2) {
        for (int i = 0;i <= n-2;++i) {
            sum = f0+f1;
            tmp = f1;
            f1 = f1+f0;
            f0 = tmp;
        }
        cout << sum;
    }
    return 0;
}


4
#include <iostream>
using namespace std;

int main()
{
    int n, max, max_, tmp;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    max = array[0];
    for (int i = 0;i<n;++i) {
        if (max < array[i]) {
            tmp = max;
            max = array[i];
            array[i] = tmp;
        }
    }
    max_ = array[0];
    for (int i = 0;i<n;++i) {
        if (array[i] <= max && array[i] >= max_) {
            tmp = max_;
            max_ = array[i];
            array[i] = tmp;
        }
    }
    cout << max_;
    return 0;
}


5
#include <iostream>
using namespace std;
int main()
{
    int n,flag = 0;
    cin >> n;
    int array[n];
    for (int i = 0;i<n;++i) cin >> array[i];
    for (int i = 0;i<=n;++i) {
        flag = 0;
        for (int j = 0;j<n;++j) {
            if (array[j] == i) {flag = 1;break;}
        }
        if (flag == 0) {cout << i;break;}
    }
}

6
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        if (n%i == 0) cout << i << ' ';
    }
    return 0;
}


7
#include <iostream>
using namespace std;

int main()
{
    int m, n, sum = 0, num = 0;
    cin >> m >> n;
    if (m == 1 || m == 2) {m = 3;num++;}
    for (int i = m; i<=n;++i) {
        sum = 0;
        for (int j = 2; j <= i; ++j) {
            if (i%j == 0) sum++;
        }
        if (sum == 1) num++;
    }
    cout << num;
    return 0;
}


8
#include <iostream>
using namespace std;

int main()
{
    int n, m=2;
    cin >> n;
    if (n >= 1000 && n <= 1000000){
        while (m <= n/100) {
        if (n%m == 0 && n/m >= 100 && n/m <= 999) {cout << n/m; return 0;}
        m++;
        }
        cout << "Not found!";
    }
    else cout << "Input error!";
    return 0;
}


9
#include <iostream>
using namespace std;

int main()
{
    int m,n,sum = 0,num;
    cin >> m >> n;
    for (int i = m; i<=n;++i) {
        num = 0;
        for (int j = 1;j<i;++j) {
            if (i%j == 0) num += j;
        }
        if (num == i) {cout << i << ' ';sum++;}
    }
    if (sum == 0) cout << -1;
    return 0;
}


10
#include <iostream>
using namespace std;

int main()
{
    int n, d, m, sum=0;
    cin >> n >> d;
    m = n;
    while (m != 0) {
        n = m % 10;
        m = m / 10;
        if (n == d) sum++;
    }
    cout << sum;
    return 0;
}


11
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i<=n;++i) {
        for (int j = 1; j<=n-i;++j) cout << ' ';
        for (int k = 1;k<=2*i-1;++k) cout << '+';
        cout << '\n';
    }
    for (int i = n-1;i >= 1;--i) {
        for (int j = 1; j<=n-i;++j) cout << ' ';
        for (int k = 1;k<=2*i-1;++k) cout << '+';
        cout << '\n';
    }
    return 0;
}

