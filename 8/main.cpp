1
#include <iostream>

using namespace std;
struct Time{
        int hour;
        int minute;
        int second;
    };
void setTime(Time &t)
{
    cin >> t.hour;
    cin >>t.minute;
    cin >> t.second;
}
void increase(Time &t)
{
    t.second++;
    if (t.second >= 60) {t.second -= 60;t.minute++;}
    if (t.minute >= 60) {t.minute -= 60;t.hour++;}
    if (t.hour >= 24) t.hour -= 24;
}
void showTime(Time &t)
{
    if (t.hour >= 10) cout <<t.hour;
    else cout << 0 << t.hour;
    cout << ':';
    if (t.minute >= 10) cout << t.minute;
    else cout << 0 << t.minute;
    cout << ':';
    if (t.second >= 10) cout << t.second;
    else cout << 0 << t.second;
    cout << endl;
}
int main()
{
    Time t1, t2;
    setTime(t1);
    showTime(t1);
    increase(t1);
    showTime(t1);

    setTime(t2);
    showTime(t2);
    increase(t2);
    showTime(t2);


    return 0;
}

2
#include <iostream>

using namespace std;
struct Complex{
    int real;
    int imag;
};

int main()
{
    Complex x,y;
    cin >> x.real >> x.imag >> y.real >> y.imag;
    cout << "x = " << x.real << '+' << x.imag << 'i' << endl;
    cout << "y = " << y.real << '+' << y.imag << 'i' << endl;
    x.real += y.real;
    x.imag += y.imag;
    cout << "x += y; x = " << x.real << '+' << x.imag << 'i' << endl;
    int tmp1 = x.real*y.real-x.imag*y.imag;
    int tmp2 = x.real*y.imag+x.imag*y.real;
    y.real = tmp1;
    y.imag = tmp2;
    cout << "y *= x; y = " << y.real;
    if (y.imag > 0)  cout << '+' << y.imag << 'i' << endl;
    else cout << y.imag << 'i' << endl;
    cout <<"x + y = " << x.real+y.real;
    if (x.imag+y.imag > 0)  cout << '+' << x.imag+y.imag << 'i' << endl;
    else cout << x.imag+y.imag << 'i' << endl;
    cout <<"y * x = " << x.real*y.real-x.imag*y.imag;
    if (x.real*y.imag+x.imag*y.real > 0)  cout << '+' << x.real*y.imag+x.imag*y.real << 'i' << endl;
    else cout << x.real*y.imag+x.imag*y.real << 'i' << endl;
    cout << "x = " << x.real;
    if (x.imag > 0)  cout << '+' << x.imag << 'i' << endl;
    else cout << x.imag << 'i' << endl;
    cout << "y = " << y.real;
    if (y.imag > 0)  cout << '+' << y.imag << 'i' << endl;
    else cout << y.imag << 'i' << endl;

    return 0;
}

3
#include <iostream>

using namespace std;
struct student{
    char name[20];
    int year;
    int month;
    int day;
    char tel[20];
    char address[50];
};

int main()
{
    int n;
    cin >> n;
    student p[10];
    for (int i=0;i<n;i++) {
        cin >> p[i].name >> p[i].year >> p[i].month >> p[i].day >> p[i].tel;
        cin.get();
        cin.getline(p[i].address,50);
    }
    int flag = 0;
    for (int j=0;j<n;j++) {
        int flag = 0;
        for (int k=0;k<n-1;k++) {
            if ((p[k].year < p[k+1].year) || (p[k].year == p[k+1].year && p[k].month < p[k+1].month) || (p[k].year == p[k+1].year && p[k].month == p[k+1].month && p[k].day <= p[k+1].day)) {student tmp = p[k];p[k] = p[k+1];p[k+1] = tmp;flag = 1;}
        }
        if (flag == 0) break;
    }
    for (int i=0;i<n;++i) {cout << p[i].name << ' ' << p[i].year <<' ' << p[i].month << ' ' << p[i].day << ' ' << p[i].tel << ' ' << p[i].address << endl;}
    return 0;
}

4
#include <iostream>

using namespace std;
struct matrix{
    long long int a11=1;
    long long int a12=0;
    long long int a21=0;
    long long int a22=1;
};
int main()
{
    int n;
    cin >> n;
    matrix A,ans;
    cin >> A.a11 >> A.a12 >> A.a21 >> A.a22;
    while (n) {
        if (n % 2) {matrix tmp = ans;
        ans.a11 = (((tmp.a11+1000000007)%1000000007*(A.a11+1000000007)%1000000007)%1000000007+((tmp.a12+1000000007)%1000000007*(A.a21+1000000007)%1000000007)%1000000007)%1000000007;
        ans.a12 = (((tmp.a11+1000000007)%1000000007*(A.a12+1000000007)%1000000007)%1000000007+((tmp.a12+1000000007)%1000000007*(A.a22+1000000007)%1000000007)%1000000007)%1000000007;
        ans.a21 = (((tmp.a21+1000000007)%1000000007*(A.a11+1000000007)%1000000007)%1000000007+((tmp.a22+1000000007)%1000000007*(A.a21+1000000007)%1000000007)%1000000007)%1000000007;
        ans.a22 = (((tmp.a21+1000000007)%1000000007*(A.a12+1000000007)%1000000007)%1000000007+((tmp.a22+1000000007)%1000000007*(A.a22+1000000007)%1000000007)%1000000007)%1000000007;
        if (ans.a11 < 0) ans.a11 += 1000000007;
        if (ans.a12 < 0) ans.a12 += 1000000007;
        if (ans.a21 < 0) ans.a21 += 1000000007;
        if (ans.a22 < 0) ans.a22 += 1000000007;
        }
        matrix tmp = A;
        A.a11 = (((tmp.a11+1000000007)%1000000007*(tmp.a11+1000000007)%1000000007)%1000000007+((tmp.a12+1000000007)%1000000007*(tmp.a21+1000000007)%1000000007)%1000000007)%1000000007;
        A.a12 = (((tmp.a11+1000000007)%1000000007*(tmp.a12+1000000007)%1000000007)%1000000007+((tmp.a12+1000000007)%1000000007*(tmp.a22+1000000007)%1000000007)%1000000007)%1000000007;
        A.a21 = (((tmp.a21+1000000007)%1000000007*(tmp.a11+1000000007)%1000000007)%1000000007+((tmp.a22+1000000007)%1000000007*(tmp.a21+1000000007)%1000000007)%1000000007)%1000000007;
        A.a22 = (((tmp.a21+1000000007)%1000000007*(tmp.a12+1000000007)%1000000007)%1000000007+((tmp.a22+1000000007)%1000000007*(tmp.a22+1000000007)%1000000007)%1000000007)%1000000007;
        if (A.a11 < 0) ans.a11 += 1000000007;
        if (A.a12 < 0) ans.a12 += 1000000007;
        if (A.a21 < 0) ans.a21 += 1000000007;
        if (A.a22 < 0) ans.a22 += 1000000007;
        n /= 2;
    }
    if (ans.a11 < 0) cout << ans.a11+1000000007 << ' ';
    else cout << ans.a11 << ' ';
    if (ans.a12 < 0) cout << ans.a12+1000000007 << endl;
    else cout << ans.a12 << endl;
    if (ans.a21 < 0) cout << ans.a21+1000000007 << ' ';
    else cout << ans.a21 << ' ';
    if (ans.a22 < 0) cout << ans.a22+1000000007 << endl;
    else cout << ans.a22 << endl;
    // cout << ans.a11 << ' ' << ans.a12 <<endl;
    // cout << ans.a21 << ' ' << ans.a22;
    return 0;
}

5
#include <iostream>
using namespace std;

struct List
{
    int num;
    List *next;
};

int main()
{
    List *head,*p,*q;
    int num;

    head = NULL;
    //cout << "请输入若干个正整数（-1结束）\n";
    cin >> num;
    while(num != -1)
    {
        p = new List;
        p->num = num;
        p->next = head;
        head = p;
        cin >> num;
    }

    //cout << "按照输入顺序逆序输出\n";
    for(p = head; p->next != NULL; p = p->next)
    {
        cout << p->num << " ";
    };
    cout << p->num;
    cout << endl;

    for(p = head; p != NULL; p = q)
    {
        q = p->next;
      delete p;
    }

    return 0;
}

6
#include <iostream>
#include <cstring>
using namespace std;
struct student{
    long long int id=0;
    char name[50];
    int grade1=0;
    int grade2=0;
    int grade3=0;

};

int main()
{
    student p[1000];
    int n,i=0;
    cin >> n;
    while (n != 0) {
        if (n == 1)
        {cin >> p[i].id >> p[i].grade1 >> p[i].grade2 >> p[i].grade3;
            cin.get();
            cin.getline(p[i].name,50);
            int flag = 0;
            for (int j=0;j<i;j++) {
                if (p[i].id == p[j].id) {
                    strcpy(p[j].name,p[i].name);
                    p[j].grade1 = p[i].grade1;
                    p[j].grade2 = p[i].grade2;
                    p[j].grade3 = p[i].grade3;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) i += 1;
            }
        else if (n == 2)
        {long long int idtmp;cin >> idtmp;int j=0;
            while (p[j].id != idtmp && j != i) j++;
            if (j == i+1) goto gg;
            else {
            cin >> p[j].grade1 >> p[j].grade2 >> p[j].grade3;
            cin.get();
            cin.getline(p[j].name,50);
            goto gg;
            }
            }
        else if (n == 3)
        {long long int idtmp;cin >> idtmp;int j=0;
            while (j != i+1 && p[j].id != idtmp) j++;
            if (j == i+1) goto gg;
            else {
            for (;j<i;j++) p[j] = p[j+1];
            i--;
            goto gg;
            }
            }
        else if (n == 4)
        {long long int idtmp;cin >> idtmp;int j=0;
            while (j!= i+1 && p[j].id != idtmp) j++;
            if (j == i+1) goto gg;
            else
            cout << p[j].id << ' ' << p[j].name << ' ' << p[j].grade1 << ' ' << p[j].grade2 << ' ' << p[j].grade3 << ' ' << endl;
            }
        else if (n == 5)
        {int q[10];char nametmp[50];cin.get();
            cin.getline(nametmp,50);
            int k=0;
            for (int j=0;j<i;j++) if (strcmp(nametmp,p[j].name) == 0) {q[k] = j;k++;}
            if (k == 0) goto gg;
            else {
            for (int m=0;m<k;m++) {
                for (int r=0;r<k-1;r++) if (p[q[r]].id > p[q[r+1]].id) {int tmp = q[r];q[r] = q[r+1];q[r+1] = tmp;}
            }
            for (int m=0;m<k;m++) cout << p[q[m]].id << ' ' << p[q[m]].name << ' ' << p[q[m]].grade1 << ' ' << p[q[m]].grade2 << ' ' << p[q[m]].grade3 << ' ' << endl;
            }
        }
        else if (n == 6)
        {
                int q[1000] = {0,1,2,3,4,5,6,7,8,9};
                for (int t=0;t<1000;t++) q[t] = t;
                for (int m=0;m<i;m++) {
                    for (int r=0;r<i-1;r++) {
                        if (p[q[r]].id > p[q[r+1]].id) {int tmp = q[r];q[r] = q[r+1];q[r+1] = tmp;}
                    }
                }
                for (int j=0;j<i;j++) cout << p[q[j]].id << ' ' << p[q[j]].name << ' ' << p[q[j]].grade1 << ' ' << p[q[j]].grade2 << ' ' << p[q[j]].grade3 << ' ' << endl;
            }
        else if (n == 7)
        {
                int q[1000] = {0,1,2,3,4,5,6,7,8,9};
                for (int t=0;t<1000;t++) q[t] = t;
                for (int m=0;m<i;m++) {
                    for (int r=0;r<i-1;r++){
                    if ((p[q[r]].grade1+p[q[r]].grade2+p[q[r]].grade3) < (p[q[r+1]].grade1+p[q[r+1]].grade2+p[q[r+1]].grade3)) {int tmp = q[r];q[r] = q[r+1];q[r+1] = tmp;}
                    else if ((p[q[r]].grade1+p[q[r]].grade2+p[q[r]].grade3) == (p[q[r+1]].grade1+p[q[r+1]].grade2+p[q[r+1]].grade3) && p[q[r]].id > p[q[r+1]].id) {int tmp = q[r];q[r] = q[r+1];q[r+1] = tmp;}
                    }
                }
                for (int j=0;j<i;j++) cout << p[q[j]].id << ' ' << p[q[j]].name << ' ' << p[q[j]].grade1 << ' ' << p[q[j]].grade2 << ' ' << p[q[j]].grade3 << ' ' << endl;
            }
        gg:cin >> n;
    }

    return 0;
}


7
#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};


ListNode* reverseList(ListNode* head) {
    /********* Begin *************/
    ListNode *p = head;
    if (head == NULL) return head;
    ListNode *end = new ListNode;
    end->next = NULL;
    while (p != NULL) {
        ListNode *q = new ListNode;
        q->val = p->val;
        q->next = end;
        end = q;
        p = p->next;
    }
    ListNode *q=end;
    while (q->next->next != NULL) q = q->next;
    q->next = NULL;
    return end;
    /********* End *************/
}



ListNode* createList() {
    int x;
    ListNode head;
    ListNode* p = &head; head.next = NULL;
    while (cin >> x) {
        p->next = new ListNode; p->next->val = x; p->next->next = NULL;
        p = p->next;
    }
    return head.next;
}

void disp(ListNode* p) {
    while (p)
    {
        cout<<p->val<<" -> ";
        p = p->next;
    }
    cout<<"nullptr\n";
}

int main()
{
    ListNode* L1 = createList(); disp(L1);
    ListNode* L2 = reverseList(L1); disp(L2);

    return 0;
}

8
#include<iostream>
using namespace std;

struct Node {
  int order, coeff;
  Node *nxt;
};

Node* add_poly(Node* a, Node* b)
{
    Node *head = new Node;
    head->nxt = NULL;
    Node *p=head;
    while (a != NULL || b != NULL){
        Node *q = new Node;q->nxt=NULL;
        if (a != NULL && b == NULL || a->order > b->order) {
            if (a->coeff != 0) {q->order = a->order;q->coeff = a->coeff;p->nxt = q;a = a->nxt;p=q;}
            else a = a->nxt;
        }
        else if (b != NULL && a == NULL || a->order < b->order) {
            if (b->coeff != 0) {q->order = b->order;q->coeff = b->coeff;p->nxt=q;b = b->nxt;p=q;}
            else b = b->nxt;
        }
        else {
            if (a->coeff+b->coeff != 0) {q->order = b->order;q->coeff = a->coeff+b->coeff;p->nxt = q;a = a->nxt;b = b->nxt;p=q;}
            else {a = a->nxt;b = b->nxt;}
        }
    }
    if (head->nxt == NULL) {head->coeff = 0;head->order = 0;return head;}
    else return head->nxt;
}

int main()
{
  Node *a = NULL, *pa = NULL, *b = NULL, *pb = NULL;
  int coef, orde;
  cin >> coef >> orde;
  while (orde >= 0) {
    Node* na = new Node;
    na->order = orde;
    na->coeff = coef;
    na->nxt = NULL;
    if (pa) pa->nxt = na;
    pa = na;
    if (a == NULL) a = pa;
    cin >> coef >> orde;
  }
  cin >> coef >> orde;
  while (orde >= 0) {
    Node* nb = new Node;
    nb->order = orde;
    nb->coeff = coef;
    nb->nxt = NULL;
    if (pb)  pb->nxt = nb;
    pb = nb;
    if (b == NULL) b = pb;
    cin >> coef >> orde;
  }
  Node* c = add_poly(a, b);

  while (c != NULL) {
    cout << c->coeff << ' '<< c->order << endl;
    c = c->nxt;
  }

  //要不要补上a,b,c三个链表的删除？
  return 0;
}
//参考SJTU数据结构教材
