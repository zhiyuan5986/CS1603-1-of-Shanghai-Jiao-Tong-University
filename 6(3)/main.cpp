1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int time1(int *lh,int *rh,int n)
{
    if (n == 3) return *lh+*(lh+1)+*rh;
    if (n == 2) return *lh+*rh;
    return 2*(*(lh+1))+*lh+*rh+time1(lh,rh-2,n-2);
}
int time2(int *lh,int *rh,int n)
{
    if (n == 3) return *lh+*(lh+1)+*rh;
    if (n == 2) return *lh+*rh;
    return 2*(*lh)+*(rh-1)+*rh+time2(lh,rh-2,n-2);
}

int main()
{
    int n, t1, t2;
    cin >> n;
    int array[n];
    for (int i=0;i<n;++i) cin >> array[i];
    sort(array,array+n);
    t1 = time1(array,array+n-1,n);
    t2 = time2(array,array+n-1,n);
    if (t1 > t2) cout <<t2;
    else cout <<t1;
	return 0;
}

2
#include <iostream>
using namespace std;

long long quickPow(int n, int k)
{
    if (k == 0) return 1;
    if (k == 1) return n;
    if (k == 2) return n*n;
    long long int tmp = quickPow(n,k/2);
    if (k%2 == 0) return tmp*tmp;
    else return tmp*tmp*n;
}

int main()
{
  int n, k;
  cin >> n >> k;

  cout << quickPow(n, k);
  return 0;
}

3
#include<iostream>
using namespace std;
static int B[100];
void sort(int A[],int lh,int rh)
{
    if (rh-lh>1)
    {
        sort(A,lh,rh-1);
        int tmp = A[rh-1];
        int i=lh;
        while (A[i] < tmp) i++;
        for (int j=rh-2;j>i-1;--j) A[j+1]=A[j];
        A[i] = tmp;
    }
}
void merge(int A[],int low,int mid,int high)
{

    int i=0;
    for (i=low;i<high;i++) B[i] = A[i];
    sort(B,low,high);
}
void merge_Sort(int A[],int n)
{
    if (n == 1);
    else {
        int high = n;
        int low = 0;
        if (high-low>0) {
            int mid = (high+low)/2;
            sort(A,low,mid);
            sort(A,mid+1,high);
            merge(A,low,mid,high);
        }
    }
}

int main()
{
    int n,num[100];

    cin>>n;

    // ÄãµÄ´úÂë
    for (int i=0;i<n;++i) cin >> num[i];
    merge_Sort(num,n);
    for (int i=0;i<n;++i) cout << B[i] <<' ';
	return 0;
}

4
#include <iostream>
using namespace std;
int V[2000][2000] = {0};
int knapsack(int n, int s[], int v[], int C) {
  // Please fill the code
    if (V[n][C]) return V[n][C];
    if (n <= 0 || C <= 0) return 0;
    if (n > 0 && s[n] > C) {V[n][C] = knapsack(n-1, s, v, C);return V[n][C];}
    if (n > 0 && s[n] <= C) {
            int tmp1 = knapsack(n-1, s, v, C);
            int tmp2 = knapsack(n-1, s, v, C-s[n])+v[n];
        if (tmp1 < tmp2) V[n][C]=tmp2;
        else V[n][C] = tmp1;
    }
//    for (int i=0;i<=n;++i) {
//        cout << endl;
//        for (int j=0;j<=C;++j) {
//                cout << V[i][j] <<' ';
//            }
//    }
    return V[n][C];
}
//
//int main()
//{
//  int n, C,s[2000], v[2000];
//  cin >> C >> n;
//
//  for (int i = 1; i <= n; i++)
//    cin >> s[i] >> v[i];
//
//  cout << knapsack(n, s, v, C) << endl;
//  return 0;
//}

//#include <iostream>
//using namespace std;
//
//int knapsack(int n, int s[], int v[], int C) {
//  // Please fill the code
//    int V[200][200];
//    for (int i=0;i<=n;i++) {
//        for (int j=0;j<=C;j++) {
//            if (i == 0 || j == 0) V[i][j] = 0;
//            if (i > 0 && s[i] > j) V[i][j] = V[i-1][j];
//            if (i > 0 && s[i] <= j) {
//                if (V[i-1][j] < V[i-1][j-s[i]]) V[i][j]=V[i-1][j-s[i]]+v[i];
//                else V[i][j] = V[i-1][j]+v[i];
//            }
//        }
//    }
//
//    return V[n][C];
//}

int main()
{
  int n, C,s[2000], v[2000];
  cin >> C >> n;

  for (int i = 1; i <= n; i++)
    cin >> s[i] >> v[i];

  cout << knapsack(n, s, v, C) << endl;
  return 0;
}

