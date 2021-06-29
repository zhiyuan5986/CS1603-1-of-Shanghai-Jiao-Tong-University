1
//myStack.h
#ifndef stack_h
#define stack_h
#include <iostream>
using namespace std;

template <class T> class mystack;

template <class T>
class mystack {
    int scale;
    int now;
    T *p;
public:
    mystack(int s) {
        p = new T[s];scale = s;now=0;

    }
    void push(T a) {
        if (now >= scale) {T *q = new T[scale*2];for (int i=0;i<scale;i++) q[i] = p[i];delete p;p=q;scale *= 2;}
        p[now] = a;
        now++;
    }
    T pop() {if (now != 0) now--;return p[now];}
    bool isEmpty() {if (now != 0) return false;else return true;}
    //~mystack {if (p) delete p;}
};
#endif

2
//myQueue.h
#ifndef myqueue_h
#define myqueue_h
#include <iostream>
using namespace std;

template <class T> class Node;
template <class T> class myQueue;
template <class T> ostream& operator<<(ostream &os, const Node<T> &obj);
template <class T> ostream& operator<<(ostream &os, const myQueue<T> &obj);

template <class T>
class Node {
    friend class myQueue<T>;
    friend ostream& operator<< <T>(ostream &os, const Node<T> &obj);

public:
    Node<T> *next;
    T data;
    Node(T d):next(NULL),data(d) {}
    Node():next(NULL) {}
};

template <class T>
class myQueue {
    friend ostream& operator<< <T>(ostream &os,const myQueue<T> &obj);

public:
    Node<T> *f;
    Node<T> *now;
    myQueue() {
        f = new Node<T>;
        now = f;
    }
    void push(T a) {
        Node<T> *q = new Node<T>(a);
        now->next = q;
        now = q;
    }
    T pop() {
        T a = f->next->data;
        Node<T> *tmp = f;
        f = f->next;
        delete tmp;
        return a;
    }
    Node<T> &first() {
        return *(f->next);
    }

};
template <class T>
ostream& operator<<(ostream &os,const Node<T> &obj)
{
    os << obj.data;
    return os;
}
template <class T>
ostream & operator<<(ostream &os,const myQueue<T> &obj)
{
    Node<T> *tmp = new Node<T>;
    for (tmp = obj.f->next;tmp != obj.now;tmp = tmp->next) os << tmp->data << ' ';
    os << obj.now->data;
    return os;
}
#endif

3
//myQueue.h
//line指的是当前某一个窗口的人还需要的时间
//flag指的是当前窗口有人/无人
#ifndef queue_h
#define queue_h
#include <iostream>
using namespace std;

template <class T> class Node;
template <class T> class linkList;
template <class T> class Queue;

template <class T>
class Node{
    friend class linkList<T>;
    T data;
    Node<T> *next;
public:
    Node(T d):data(d),next(NULL) {}
    Node():next(NULL) {}
};

template <class T>
class linkList {
    Node<T> *head;
    Node<T> *now;
public:
    linkList() {head = new Node<T>;now = head;}
    void in(T a) {
        Node<T> *q = new Node<T>(a);
        now->next = q;
        now = q;
    }
    bool out(int &f) {
        if (f == 0 && head != now) {
            f = head->next->data;
            head = head->next;
            return true;
        }
        else return false;
    }
};

template <class T>
class Queue:public linkList<T> {

};
#endif
