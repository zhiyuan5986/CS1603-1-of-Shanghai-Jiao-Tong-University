1
#include <iostream>
using  namespace std;
int main()
{
	int a,b;
    cin>>a>>b;
    //输入你的代码
    cout << a << "+" << b << "=" << a+b << endl;
    cout << a << "*" << b << "=" << a*b << endl;
    cout << a << "/" << b << "=" << a/b << endl;
    cout << a << "%" << b << "=" << a%b;
    return 0;
}

2
#include <iostream>
#include <iomanip>
using  namespace std;
int main()
{
    //输入你的代码
    int a, b, c, d;
    double result;
    cin >> a >> b >> c >> d;
    result = (a+b+c+d)/4.0;
	cout<<fixed<<setprecision(2)<<result<<endl;
	return 0;
}

3
#include <iostream>
using  namespace std;
int main()
{
    //输入你的代码
    int num, a, b, c;
    cin >> num;
    a = num/100;
    b = (num-a*100)/10;
    c = num-a*100-b*10;
    cout << a << " " << b << " " << c;
    return 0;
}

4
#include <iostream>
using  namespace std;
int main()
{
    //输入你的代码
    char a, b, c, d;
    int num;
    cin >> num;
    a = num/1000+12+'A';
    b = (num-num/1000*1000)/100+12+'A';
    c = (num-num/100*100)/10+12+'A';
    d = (num-num/10*10)+12+'A';
    cout << a << b << c << d;
    return 0;
}

5
#include <iostream>
#include <iomanip>
#include <cmath>
using  namespace std;
int main()
{
    //输入你的代码
    double a, b, c, d, distance;
    cin >> a >> b >> c >> d;
    distance = sqrt((c-a)*(c-a)+(d-b)*(d-b));
    cout << setiosflags(ios::fixed) << setprecision(2) << distance;
    return 0;
}

6
#include <iostream>
using  namespace std;
int main()
{
    //输入你的代码
    int second;
    cin >> second;
    cout << second/3600 << "小时" << (second-second/3600*3600)/60 << "分" << second-second/60*60 << "秒";
    return 0;
}

7
#include <iostream>
#include <iomanip>
using  namespace std;
int main()
{
    //输入你的代码
    int r;
    cin >> r;
    cout << "半径为" << r <<"的球体积为" << setiosflags(ios::fixed) << setprecision(1) << 4.0/3*3.14*r*r*r << endl;
    cout << "半径为" << r << "的球体表面积为" << 4*3.14*r*r;
    return 0;
}

8
#include <iostream>
using  namespace std;
int main()
{
    //输入你的代码
    int n, m, a, b, c, d;
    cin >> n >> m;
    cout << ((n-n/100*100)/10+7)%10*1000+(n/1000+7)%10*10+((n-n/1000*1000)/100+7)%10+(n-n/10*10+7)%10*100 << " ";
    a = (m-m/100*100)/10-7;//1
    b = m-m/10*10-7;
    c = m/1000-7;
    d = (m-m/1000*1000)/100-7;
    if (a < 0) a += 10;
    if (b < 0) b += 10;
    if (c < 0) c += 10;
    if (d < 0) d += 10;
    cout << a*1000+b*100+c*10+d;
    return 0;
}

9
#include <iostream>
using  namespace std;
int main()
{
    //输入你的代码
    long int du;
    cin >> du;
    cout << du * 6 / 10 << " " << du * 6 % 10;
    return 0;
}


