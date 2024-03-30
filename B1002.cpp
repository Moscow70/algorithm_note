#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>

using namespace std;
string pingyin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main () {
    string s;
    cin >> s;
    int i = 0;
    int sum = 0;
    while (s[i] != '\0') {
        sum = sum + (s[i] - '0');
        i++;
    }
    vector <string> res;
    res.clear();
    while (sum > 0) {
        int temp = sum % 10;
        res.push_back(pingyin[temp]);
        sum = sum / 10;
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
        if (i != 0) {
            cout << " ";
        }
    }
    return 0;
}

/*
vscode求你别抽风了，string数组就是这样定义的你报个锤子错
*/