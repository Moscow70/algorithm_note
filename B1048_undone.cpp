#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    string a,b;
    a.clear();
    b.clear();
    cin >> a >> b;
    int len;
    if (!a.empty() && !b.empty()) {
        len = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
    }
    else {
        len = 0;
    }

    int isodd = 1;
    vector <char> res;
    res.clear();
    char tempres;
    for (int i = 0; i < len; i++) {
        if (i >= a.size()) {
            a[i] = '0';
        }
        if (i >= b.size()) {
            b[i] = '0';
        }
        if (isodd == 1) {
            int temp = ((a[i] - '0') + (b[i] - '0')) % 13;
            switch (temp) {
                case 10:
                    tempres = 'J';
                    break;
                case 11:
                    tempres = 'Q';
                    break;
                case 12:
                    tempres = 'K';
                    break;
                default:
                    tempres = temp + '0';
                    break;
            }
        }
        if (isodd == -1) {
            int temp = (b[i] - a[i]);
            if (temp < 0) {
                temp = temp + 10;
            }
            tempres = temp + '0';
        }
        isodd = isodd * -1;
        res.push_back(tempres);
    }
    while (!res.empty()) {
        cout << res[res.size() - 1];
        res.pop_back();
    }
    return 0;
}

/*
这题也不说清楚，B如果比A长，超过A的部分要用0补齐A的位数，并以0进行运算（实际上题中的加密方法如果A位上为0就是不加密）
然后先试试，如果A比B长，是只需要加密完B还是B也要补0加密
看来是需要补0的

不是，运行时错误是什么东西，啊？
*/