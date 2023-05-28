#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double num;
    int sysnum;
    int fsysnum;
    int wnum;
    int wnum10 = 0;
    double dnum;
    int i;
    int s;
    int m;
    int wnumf = 0;
    double fnum;
    double fnum10 = 0;
    double fnumf = 0;
    int sh;
    int op;
    int flag = 0;
    cout << "Enter any number, numeral system and final numeral system" << endl;
    cin >> num >> sysnum >> fsysnum;
    cout << "Enter number after point in your number"<< endl;
    cin >> sh;
    cout << "How many numbers do you want to see after point"<< endl;
    cin >> op;
    try {
        if (num < 0) {
            num = abs(num);
            flag = 1;
        }
        int count = 0;
        wnum = int(num);
        while (wnum > 0) {
            i = wnum % 10;
            if (i >= sysnum){
                throw 1;
            }
            wnum10 += i * pow(sysnum, count);
            wnum = wnum / 10;
            count++;
        }
        count = 0;
        while (wnum10 > 0) {
            s = wnum10 % fsysnum;
            wnum10 = wnum10 / fsysnum;
            wnumf += s * pow(10, count);
            count++;
        }
        count = 1;
        fnum = num - int(num);
        int ch = 0;
        while (ch < sh) {
            fnum *= 10;
            if (ch + 1 == sh) {
                m = int(fnum) + 1;
            } else {
                m = int(fnum);
            }
            if (m >= sysnum){
                throw 2;
            }
            fnum10 += m * 1 / pow(sysnum, count);
            fnum = fnum - m;
            count++;
            ch++;
        }
        ch = 0;
        count = -1;
        while ((ch < op + 1) && (fnum10 != 0)) {
            fnum10 *= fsysnum;
            s = int(fnum10);
            fnumf += s * pow(10, count);
            fnum10 = fnum10 - s;
            count--;
            ch++;
        }
        fnumf = round(fnumf * pow(10, op)) / pow(10, op);
        fnumf += wnumf;
        if (flag == 1) {
            fnumf = 0 - fnumf;
        }
        cout << fnumf << endl;
    }
    catch(int){ cout << "your number is not acceptable in your system" << endl;}

}