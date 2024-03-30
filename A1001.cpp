#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>


using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    int res = a + b;
    if (res == 0) {
        cout << "0";
    }
    vector <char> reseperate;
    reseperate.clear();
    int flag = 1;
    if (res < 0) {
        flag = 0;
        res = -res;
    }
    int count = 1;
    while (res > 0) {
        reseperate.push_back((res % 10) + '0');
        res = res / 10;
        if (count % 3 == 0 && res != 0) {
            reseperate.push_back(',');
        }
        count++;
    }
    if (flag == 0) {
        cout << "-";
    }
    while (!reseperate.empty()) {
        cout << reseperate[reseperate.size() - 1];
        reseperate.pop_back();
    }
    return 0;
}

/*
0要单独算一下
*/