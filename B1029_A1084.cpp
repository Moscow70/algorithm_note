#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <map>

using namespace std;

typedef pair<char, int> p;

bool cmp (p& a, p& b) {
    return a.second < b.second;
}

int main () {
    map <char, int> data;
    string temp;
    cin >> temp;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] - 'a' >= 0 && temp[i] - 'a' < 26) {
            temp[i] = temp[i] - 'a' + 'A';
        }
        if (data.find(temp[i]) == data.end()) {
            data[temp[i]] = i + 1;
        }
    }
    cin >> temp;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] - 'a' >= 0 && temp[i] - 'a' < 26) {
            temp[i] = temp[i] - 'a' + 'A';
        }
        if (data.find(temp[i]) != data.end()) {
            data[temp[i]] = 0;
        }
    }
    vector <p> name_score(data.begin(), data.end());
    sort(name_score.begin(), name_score.end(), cmp);
    for (int i = 0; i < name_score.size(); i++) {
        if (name_score[i].second != 0) {
            cout << name_score[i].first;
        }
    }
    return 0;
}

/*
用map不能按照发现顺序输出，map会自动按照ACSII码排好顺序

找到排序map的方式就可以了
*/