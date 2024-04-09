#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<char, int> p;

bool cmp (p& a, p& b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
}

int main () {
    string temp;
    getline(cin, temp);
    map <char, int> data;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] - 'A' >= 0 && temp[i] - 'Z' <= 0) {
            temp[i] = temp[i] - 'A' + 'a';
        }
        if (temp[i] - 'a' >= 0 && temp[i] - 'z' <= 0) {
            data[temp[i]]++;
        }
    }
    vector <p> letter_num(data.begin(), data.end());
    sort(letter_num.begin(), letter_num.end(), cmp);
    if (!letter_num.empty()) {
        cout << letter_num[0].first << " " << letter_num[0].second;
    }
    system("pause");
    return 0;
}

/*
没坑，过
*/