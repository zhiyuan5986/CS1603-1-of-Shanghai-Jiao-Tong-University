//student.h
struct Stu
{
  char ID[12],name[20],birth[7],phone[12];
};

void demo(char* s);

//student.cpp
#include <iostream>
#include "student.h"
#include <cstring>
#include <fstream>
using namespace std;

void demo(char *filename)
{
    //创建二进制文件，文件名由函数参数指定
    ofstream fio(filename);
    int m;
    //从键盘读入学生人数m
    cin >> m;
    cin.get();
    //从键盘读入每个学生学号ID[12],姓名name[20],出生年月birth[7],电话phone[12]，并写入文件
    fio.seekp(0);
    for (int k=0;k<m;k++) {
        Stu* st = new Stu;
        //char IDtmp[12],nametmp[20],birthtmp[7],phonetmp[12];
        cin.getline(st->ID,12,' ');
        cin.getline(st->name,20,' ');
        cin.getline(st->birth,7,' ');
        cin.getline(st->phone,12,'\n');
        //cin >> st->ID >> st->name >> st->birth >> st->phone;
        //cout << st->ID <<' ' << st->name << ' ' << st->birth <<' ' << st->phone <<endl;
        fio.write(reinterpret_cast<char*>(st),sizeof(Stu));
    }
    //关闭文件
    fio.close();
    //fio.clear();
    //重新打开文件，键盘输入整数n(0<=n<m)，输出文件中第n个记录
    fstream fio1(filename);
    int n;
    cin >> n;
    fio1.seekg(sizeof(Stu)*n);
    Stu *tmp = new Stu;
    fio1.read(reinterpret_cast<char*>(tmp),sizeof(Stu));
    cout << tmp->ID << ' ' << tmp->name << ' ' << tmp->birth <<' ' << tmp->phone << endl;
    //键盘输入一个ID，找到该学生，用键盘输入的新电话号码替换其原有电话号码
    char find[12],phone1[12];
    cin >> find;
    cin >> phone1;
    fio1.seekg(0);
    int i=0;
    while (i<m) {
        fio1.read(reinterpret_cast<char*>(tmp),sizeof(Stu));
        //cout <<tmp.ID;
        if (strcmp(tmp->ID,find) == 0) {strcpy(tmp->phone,phone1);fio1.seekp(i*sizeof(Stu));break;}
        i++;
    }
    //cout <<tmp.phone;
    fio1.write(reinterpret_cast<char*>(tmp),sizeof(Stu));
    //关闭文件
    fio1.close();
}

