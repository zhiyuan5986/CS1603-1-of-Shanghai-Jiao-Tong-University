1
#include <iostream>
using namespace std;

int main()
{
    int R, tmp1 = 0, tmp2 = 0;
    cin >> R;
    int array[R+1][R+1] = {0};
    for (int i = 1;i < R+1;i++) {
        for (int j = 1;j <= i;j++) cin >> array[i][j];
    }
    //arr[1][1] = array[1][1];
    for (int i = 1;i <= R-1;++i) {
        for (int j = 1;j <= i+2;++j) {
            tmp1 = array[i][j-1];
            tmp2 = array[i][j];
            if (tmp1 < tmp2) array[i+1][j] += tmp2;
            else array[i+1][j] += tmp1;
        }
    }
    tmp1 = array[R][1];
    for (int i = 1;i < R+1;i++) {
        if (tmp1 < array[R][i]) tmp1 = array[R][i];
    }
    cout << tmp1;
    return 0;
}

2
#include <iostream>
using namespace std;

int main()
{
    int m, n, tmp = 0, flag = 1;
    cin >> m >>n;
    int mat[m][n], maxm[m], minn[n];//每行，每列的最大值储存
    for (int i = 0;i < m;++i) {
        for (int j = 0;j < n; ++j) cin >> mat[i][j];
    }
    for (int i = 0;i < m;++i) {
        tmp = mat[i][0];
        for (int j = 0;j < n;++j) {
            if (tmp < mat[i][j]) tmp = mat[i][j];
        }
        maxm[i] = tmp;
    }
    for (int j = 0;j < n; ++j) {
        tmp = mat[0][j];
        for (int i = 0;i < m; ++i) {
            if (tmp > mat[i][j]) tmp = mat[i][j];
        }
        minn[j] = tmp;
    }
    for (int i = 0;i < m;++i) {
        for (int j = 0;j < n;++j) {
            if (mat[i][j] == maxm[i] && mat[i][j] == minn[j]) {cout << "mat[" << i << "][" << j << "]=" << mat[i][j] << endl;flag = 0;}
        }
    }
    if (flag) cout <<"Not Found";
    return 0;
}

3
#include <iostream>
using namespace std;

int main()
{
    int n, last = 0, i = 0;
    cin >> n;
    int array[n][n];
    for (int i=0;i < n;++i)
        for (int j = 0;j < n;++j) cin >> array[i][j];
    for (int j = 0;j < n;j++) {
        for (i = 0;i < n;i++) {
            if (array[i][j]) {last = i;break;}
        }
        if (i == n || j == n-1) {cout << last;break;}
    }
    return 0;
}

4
#include <iostream>
using namespace std;

int main()
{
    int count = 26, tmp = 0, flag = 0,x;
    int array[7][7] = {0},arr[6] = {},array1[7][7] ={};
    for (int i = 1;i < 6;i++) {
        for (int j = 1;j < 6; j++) {
            if (cin.get() == '1') array[i][j] = array1[i][j] = 1;
            else array[i][j] = array1[i][j] = 0;
        }
        x = cin.get();
    }
    for (int a = 0;a < 2;a++) {
        for (int b = 0;b < 2;b++) {
            for (int c = 0;c < 2; c++) {
                for (int d = 0;d < 2;d++) {
                    for (int e = 0;e < 2;e++) {
                        for (int i = 1;i < 6;++i) {
                            for (int j = 1;j < 6;++j) {
                                array[i][j] = array1[i][j];
                            }
                        }
                        flag = 0;
                        tmp = 0;
                        arr[1] = a;
                        arr[2] = b;
                        arr[3] = c;
                        arr[4] = d;
                        arr[5] = e;
                        for (int f = 1;f < 6;f++) {
                            if (arr[f] == 1) {++tmp;array[0][f] = 1-array[0][f];array[1][f] = 1-array[1][f];array[2][f] = 1-array[2][f];array[1][f-1] = 1-array[1][f-1];array[1][f+1] = 1-array[1][f+1];}
                        }
                        for (int i = 2;i < 6;i++) {
                            for (int j = 1;j < 6;j++) {
                                 if (array[i-1][j] == 0) {++tmp;array[i-1][j] = 1-array[i-1][j];array[i][j] = 1-array[i][j];array[i+1][j] = 1-array[i+1][j];array[i][j-1] = 1-array[i][j-1];array[i][j+1] = 1-array[i][j+1];}
                            }
                        }
                        for (int n = 1;n < 6;++n) {
                            if (array[5][n] == 0) {flag = 1;break;}
                        }
                        if (tmp < count && flag == 0) count = tmp;
                        }
                    }
                }
            }
        }
    if (count == 26) cout << -1;
    else cout << count;
    return 0;
}
