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
    //�����������ļ����ļ����ɺ�������ָ��
    ofstream fio(filename);
    int m;
    //�Ӽ��̶���ѧ������m
    cin >> m;
    cin.get();
    //�Ӽ��̶���ÿ��ѧ��ѧ��ID[12],����name[20],��������birth[7],�绰phone[12]����д���ļ�
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
    //�ر��ļ�
    fio.close();
    //fio.clear();
    //���´��ļ���������������n(0<=n<m)������ļ��е�n����¼
    fstream fio1(filename);
    int n;
    cin >> n;
    fio1.seekg(sizeof(Stu)*n);
    Stu *tmp = new Stu;
    fio1.read(reinterpret_cast<char*>(tmp),sizeof(Stu));
    cout << tmp->ID << ' ' << tmp->name << ' ' << tmp->birth <<' ' << tmp->phone << endl;
    //��������һ��ID���ҵ���ѧ�����ü���������µ绰�����滻��ԭ�е绰����
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
    //�ر��ļ�
    fio1.close();
}

