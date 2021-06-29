1
//score.cpp
#include <iostream>
#include <fstream>
using namespace std;
void score(char *in,char *out)
 {
    ifstream fin(in);
    ofstream fout(out);
    char **number = new char*[10000];
    int *chinese = new int[10000];
    int *math = new int[10000];
    int *english = new int[10000];
    int *total = new int[10000];
    int n,th = 0;
    number[th] = new char;
    while (fin.get(number[th],15,' ')) {
        fin.get();
        fin >> chinese[th] >> math[th] >> english[th];
        total[th] = chinese[th]+math[th]+english[th];
        th++;
        number[th] = new char;
        fin.get();
    }
    for (int i=0;i<th;i++) {
        for (int j=0;j<th-1;j++) if (total[j] < total[j+1]) {
            int tmp = total[j];
            total[j] = total[j+1];
            total[j+1] = tmp;

            tmp = chinese[j];
            chinese[j] = chinese[j+1];
            chinese[j+1] = tmp;

            tmp = math[j];
            math[j] = math[j+1];
            math[j+1] = tmp;

            tmp = english[j];
            english[j] = english[j+1];
            english[j+1] = tmp;

            char *tmp1 = number[j];
            number[j] = number[j+1];
            number[j+1] = tmp1;
        }
    }
    for (int i=0;i<th;i++) {
        fout << number[i] << ' ' << chinese[i] << ' ' << math[i] << ' ' << english[i] << ' ' << total[i] << endl;
        //cout << number[i] << ' ' << chinese[i] << ' ' << math[i] << ' ' << english[i] << ' ' << total[i] << endl;
    }
    fout.close();
    fin.close();
 }

2
//filecount.cpp
#include <iostream>
#include <fstream>
using namespace std;
void demo(char *fname)
{
    int para=0, word=0, eng=0;
    char ch,ch1,ch2;
    bool flag1 = 0,flag3 = 0;
    // ifstream fin("3/test/7_in.txt");
    // while (fin.get(ch))
    // cout << ch;
    ifstream fin(fname);
    fin.get(ch1);
    ch = ch1;
    while (true) {
        if ((ch == ' ' || ch == ',' || ch == '.') && flag3 == 1) {word++;flag3 = 0;}
        else if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {eng++;flag1 = 0;flag3 = 1;}
        else if (ch == '\n') {if (flag1 == 0) {para++;flag1 = 1;} if (flag3 == 1) {word++;flag3 = 0;}}
        ch2 = ch;
        if ((ch = fin.get()) == EOF) break;
    }
    if (ch1 == '\n') para--;
    if (flag1 == 1) para--;
    para++;
    if (ch2 >= 'a' && ch2 <= 'z' || ch2 >= 'A' && ch2 <= 'Z') word++;
    fin.close();
    cout << para << endl << word << endl << eng;
}
