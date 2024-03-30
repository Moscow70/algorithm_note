#include <stdio.h>
#include <iostream>

using namespace std;


char* changedectoradix (int n) {
    static char res[2];
    int i = 1;
    int temp;
    while (n > 0) {
        temp = n % 13;
        switch (temp) {
            case 10: 
                res[i] = 'A';
                break;
            case 11:
                res[i] = 'B';
                break;
            case 12:
                res[i] = 'C';
                break;
            default:
                res[i] = temp + '0';
                break;
        }
        i--;
        n = n / 13;
    }
    if (i == 0) {
        res[0] = '0';
    }
    if (i == 1) {
        res[0] = '0';
        res[1] = '0';
    }
    return res;
} 

int main () {
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    char res[7];
    res[0] = '#';
    char* temp = changedectoradix(r);
    for (int i = 1; i < 3; i++) {
        res[i] = temp[i - 1];
    }
    temp = changedectoradix(g);
    for (int i = 3; i < 5; i++) {
        res[i] = temp[i - 3];
    }
    temp = changedectoradix(b);
    for (int i = 5; i < 7; i++) {
        res[i] = temp[i - 5];
    }
    for (int i = 0; i < 7; i++) {
        cout << res[i];
    }
    return 0;
}

/*
写复杂了，先写好一个字符数组，然后就可以将数字与字符一一对应，不用在+'0'将数字转换成字符数字
*/