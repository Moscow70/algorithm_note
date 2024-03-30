#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct student_info {
    string name;
    string id;
    int points;
}info;

bool cmp (info a, info b) {
    return a.points != b.points ? a.points > b.points : a.name < b.name;
}

int main () {
    int n;
    cin >> n;
    vector <info> data;
    data.clear();
    info temp;
    for (int i = 0; i < n; i++) {
        cin >> temp.name >> temp.id >> temp.points;
        data.push_back(temp);
    }
    int min, max;
    cin >> min >> max;
    sort (data.begin(), data.end(), cmp);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].points >= min && data[i].points <= max) {
            cout << data[i].name << " " << data[i].id << endl;
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "NONE";
    }
    system ("pause");
    return 0;
}

/*
easy,跳
*/