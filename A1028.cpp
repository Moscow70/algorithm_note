#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

typedef struct student_info {
    int id;
    string name;
    int points;
}info;

int condition = 0;

bool cmp (info a, info b) {
    switch (condition) {
        case 1:
            return a.id < b.id;
            break;
        case 2:
            return a.name != b.name ? a.name < b.name : a.id < b.id;
            break;
        case 3:
            return a.points != b.points ? a.points < b.points : a.id < b.id;
            break;
        default:
            return false;
            break;
    }
}

int main () {
    int n, c;
    cin >> n >> c;
    condition = c;
    vector <info> res;
    info temp;
    for (int i = 0; i < n; i++) {
        cin >> temp.id >> temp.name >> temp.points;
        res.push_back(temp);
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++) {
        printf ("%06d ", res[i].id);
        cout << res[i].name << " " << res[i].points << endl;
    }
    return 0;
}

/*
cmp函数不能加别的参数，要通过某一条件判断使用全局变量即可
*/