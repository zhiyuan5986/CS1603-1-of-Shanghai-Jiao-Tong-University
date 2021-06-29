1
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >>k;
    const int num = n;
    int array[num+1] = {0};
    for (int i = 2;i <= k;++i) {
        for (int j=1;j<=n/i;++j) array[i*j] = !array[i*j];
    }
    for (int i = 1;i < n+1;++i) {
        if (array[i] == 0) cout << i << ' ';
    }
    return 0;
}

2
#include <iostream>
using namespace std;
//把第一年的3-12月和第二年的1、2月看成一年。
int main()
{
    int array[7] = {0,0,1,0,0,0,1}, year[7] = {2,1,2,2,2,2,1};//{13,44,72,103,133,164,194,225,256,286,317,347}, year1[12] = {13,44,73,104,134,165,195,226,257,287,318,348};
    int n, th=-1;
    cin >> n;
    for (int i = 0;i<=n-1;++i) {
        if ((1900+i)%4 == 0 && (1900+i)%100 != 0 || (1900+i)%400 == 0) {
            th += 2;
            for (int j = 0;j < 7;++j) array[(j+th)%7] += year[j];
        }
        else {
            th += 1;
        for (int j = 0;j < 7;++j) array[(j+th)%7] += year[j];
        }
    }
    array[th%7]--;
    array[(3+th)%7]--;
    for (int k = 1;k<7;++k) cout << array[k] << ' ';
    cout << array[0];
    return 0;
}


3
#include <iostream>
using namespace std;

int main()
{
    int array[1000] = {0}, n=0, x, arr[1000] = {0};
    while (cin >> x) {
        array[n] = x;
        ++n;
    }
    for (int i = 0;i <1000;++i) {
        if (arr[i] == 0 && array[i] != 0) {
            cout << array[i] << ' ';
            for (int j = i;j < 1000;++j) {
                if (array[j] == array[i]) arr[j] = 1;
            }
        }
    }
    return 0;
}

4
#include <iostream>
using namespace std;

int main()
{
    int array[1000] = {0}, n=0, x, sum = 0, k=0;
    while (cin >> x) {
        array[n] = x;
        ++n;
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < i;++j) {
            if (array[i] == array[j]) {array[i] = 0;break;}
        }
    }
    for (int i = 0;i < 1000; ++i) {
        if (array[i]) ++sum;
    }
    cout << sum << ' ';
    for (int i = 0;i < 1000; ++i) if (array[i]) cout << array[i] << ' ';
    return 0;
}

5
#include <iostream>
using namespace std;

int main()
{
    int n, x, lh=0, rh, mid;
    cin >> n;
    int array[n] = {0};
    for (int i = 0;i < n;++i) cin >> array[i];
    cin >> x;
    rh = n;
    while (lh <= rh) {
        if (x < array[0]) {cout << 0;break;}
        if (x > array[n-1]) {cout << n;break;}
        mid = lh + (rh-lh)/2;
        if (array[mid] == x) {cout << mid;break;}
        if (array[mid] < x) lh = mid+1;
        else rh = mid-1;
    }
    if (lh > rh) {
        lh = 0;
        rh = n;
        while (lh <= rh) {
            mid = lh + (rh - lh)/2;
            if (array[mid] < x && array[mid+1] > x) {cout << mid+1;break;}
            if (array[mid] > x && array[mid+1] > x) rh = mid-1;
            if (array[mid] < x && array[mid+1] < x) lh = mid+1;
        }
    }
    return 0;
}

6
#include <iostream>
using namespace std;

int main()
{
    int n, x, lh, rh, mid;
    cin >> n;
    int array[n];
    for (int i = 0;i < n;++i) {
        cin >> array[i];
    }
    cin >>x;
    lh = 0;
    rh = n-1;
    while (lh <= rh) {
        mid = lh + (rh-lh)/2;
        if (array[mid] == x) break;
        if (array[mid] < x) lh = mid+1;
        if (array[mid] > x) rh = mid-1;
    }
    if (lh > rh) cout << -1 << ' ' << -1;
    else {
        lh = rh = 0;
        while (array[mid-lh] == x) ++lh;
        while (array[mid+rh] == x) ++rh;
        cout << mid-lh+1 <<' '<< mid+rh-1;
    }
    return 0;
}

7
#include <iostream>
using namespace std;

int main()
{
    int n, th, tmp;
    cin >> n;
    int array[n];
    int arr[n] = {0};
    for (int i = 0;i < n;++i) cin >> array[i];
    arr[0] = array[0];
    for (int i = 1;i < n;++i) {
        th = 0;
        while (array[i] > arr[th] && arr[th] != 0) ++th;
        for (int j = n-1;j >= th+1;--j) arr[j] = arr[j-1];
        arr[th] = array[i];
    }
    for (int i = 0;i < n;++i) cout << arr[i] << ' ';
    return 0;
}

8
#include <iostream>
using namespace std;

int main()
{
    int L, N, min, max, tmp;
    cin >> N >> L;
    int array[N];
    for (int i=0;i<N;++i) cin >> array[i];
    max = min = L-array[0];
    tmp = array[1];
    for (int i = 0;i < N;i += 2) if (L-array[i] > max ) max = L-array[i];
    for (int i = 1;i < N;i += 2) if (array[i] > tmp) tmp = array[i];
    if (max < tmp) max = tmp;
    for (int i = 0;i < N;i += 2) if (L-array[i] < min ) min = L-array[i];
    for (int i = 1;i < N;i += 2) if (array[i] < tmp) tmp = array[i];
    if (min > tmp) min = tmp;
//    if (N % 2 != 0) {
//        min = L-array[N-1];
//        tmp = array[2];
//        if (min > tmp) min = tmp;
//        max = L+array[(N+1)/2]-array[(N+1)/2-1]-array[(N+1)/2-2];
//    }
//    else {
//
//        min = L - array[N-2];
//        tmp = array[1];
//        if (min > tmp) min = tmp;
//        max = L+array[N/2+1]-array[N/2]-array[N/2-1];
//        tmp = array[N/2-1];
//        if (max < tmp) max = tmp;
//    }
    cout << min << ' ' << max;

    return 0;
}

