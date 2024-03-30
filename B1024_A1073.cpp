#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
    vector <int> num;
    num.clear();
    string s;
    cin >> s;
    if (s.size() != 0) {
        char symbol = s[0];
        num.push_back(s[1] - '0');
        int i = 3;
        while (((s[i] - '0') >= 0 && (s[i] - '0') <= 9) || (s[i] == '.')) {
            if (s[i] != '.') {
                num.push_back(s[i] - '0');
                i++;
            }
        }
        int co = i - 2;
        i++;
        char symexp = s[i];
        i++;
        vector <int> exp;
        exp.clear();
        int expnum = 0;
        for (; i < s.size(); i++) {
            exp.push_back(s[i] - '0');
        }
        int j = 0;
        while (!exp.empty()) {
            int temp = exp[exp.size() - 1];
            expnum = expnum + pow(10, j) * temp;
            j++;
            exp.pop_back();
        }
        if (symbol == '-') {
            cout << symbol;
        }
        if (symexp == '+') {
            if (co > expnum + 1) {
                for (int k = 0; k < co; k++) {
                    cout << num[k];
                    if (k == expnum) {
                        cout << ".";
                    }
                }
            }
            else {
                for (int k = 0; k < co; k++) {
                    cout << num[k];
                }
                for (int k = 0; k < (expnum - (co - 1)); k++) {
                    cout << "0";
                }
            }
        }
        if (symexp == '-') {
            cout << "0.";
            for (int k = 0; k < expnum - 1; k++) {
                cout << "0";
            }
            for (int k = 0; k < co; k++) {
                cout << num[k];
            }
        }
    }
    return 0;
}

/*
没坑，跳
*/