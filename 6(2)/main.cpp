1
#include<iostream>
using namespace std;

int gcd(int a, int b);
int main()
{
    int a, b;
    cin >> a >>b;
    if (a < b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    cout <<  gcd(a,b);
	return 0;
}
int gcd(int a, int b) {
    if (a % b == 0) return b;
    int tmp = b;
    b = a % b;
    a = tmp;
    return gcd(a,b);
}

2
#include<iostream>
using namespace std;

int fun(int n);
int main()
{
    int n;
    cin>>n;
    cout<<fun(n);
	return 0;
}
int fun(int n)
{
    if (n == 1) return 10;
    return fun(n-1)+2;
}

3
 #include<iostream>
using namespace std;

void Insert_Sort(int A[],int n)
 {
    if(n>1)
    {
        Insert_Sort(A,n-1); //递归将前面n-1个元素排序好
        // 你的代码，把第n个元素插入到前面n-1个元素中
        int i=0, tmp = A[n-1];
        while (A[i] < A[n-1]) i++;
        for (int j=n-2;j>=i;--j) A[j+1] = A[j];
        A[i] = tmp;
    }
}

int main()
{
    int n,num[1000];
    cin>>n;

    // 你的代码
    for (int i=0;i<n;++i) cin >> num[i];
    Insert_Sort(num,n);
    for (int i=0;i<n;++i) cout << num[i] << ' ';
	return 0;
}

4
#include <iostream>
using namespace std;

long long quickPow(int n, int k)
{
    if (k == 0) return 1;
    if (k == 1) return n;
    if (k == 2) return n*n;
    if (k > 2) {
        long long int tmp = quickPow(n,k/2);
        if (k % 2 == 0) return tmp*tmp;
        else return n*tmp*tmp;
    }
}

int main()
{
  int n, k;
  cin >> n >> k;

  cout << quickPow(n, k);
  return 0;
}

