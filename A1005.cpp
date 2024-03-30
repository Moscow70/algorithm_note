#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>

using namespace std;

string name[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main () {
    string s;
    cin >> s;
    int sum  = 0;
    for (int i = 0; i < s.size(); i++) {
        sum = sum + (s[i] - '0');
    }
    if (sum == 0) {
        cout << "zero";
    }
    vector <int> res;
    res.clear();
    while (sum > 0) {
        int temp = sum % 10;
        res.push_back(temp);
        sum = sum / 10;
    }
    while (!res.empty()) {
        cout << name[res[res.size() - 1]];
        res.pop_back();
        if (res.size() != 0) {
            cout << " ";
        }
    }
    return 0;
}

/*
没坑，过
*/