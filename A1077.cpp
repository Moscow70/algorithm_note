#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n;
    vector <string> res;
    res.clear();
    scanf ("%d", &n);
    getchar();
    int minlen = 256;
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        reverse(str.begin(), str.end());
        if (str.length() < minlen) {
            minlen = str.length();
        }
        res.push_back(str);
    }
    vector <char> ressuffix;
    ressuffix.clear();
    for (int i = 0; i < minlen; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (res[j][i] != res[0][i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            ressuffix.push_back(res[0][i]);
        }
        else {
            break;
        }
    }
    if (ressuffix.empty()) {
        cout << "nai";
    }
    while (!ressuffix.empty()) {
        cout << ressuffix[ressuffix.size() - 1];
        ressuffix.pop_back();
    }
    return 0;
}

/*
看起来有点复杂的居然一遍过了
*/