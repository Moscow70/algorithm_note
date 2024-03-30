#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct personal_info {
    string id;
    int points;
    int location;
    int local_ranking;
    int global_ranking;
}info;

bool cmp (info a, info b) {
    if (a.points != b.points) {
        return a.points > b.points;
    }
    else {
        return a.id < b.id;
    }
}

int main () {
    int location_number;
    cin >> location_number;
    vector <info> res;
    res.clear();
    for (int i = 0; i < location_number; i++) {
        int row = 0;
        cin >> row;
        vector <info> temp;
        info t;
        temp.clear();
        for (int j = 0; j < row; j++) {
            cin >> t.id >> t.points;
            t.location = i + 1;
            temp.push_back(t);
        }
        sort(temp.begin(), temp.end(), cmp);
        for (int j = 0; j < temp.size(); j++) {
            if (j > 0 && temp[j].points == temp[j - 1].points) {
                temp[j].local_ranking = temp[j - 1].local_ranking;
            }
            else {
                temp[j].local_ranking = j + 1;
            }
            res.push_back(temp[j]);
        }
    }
    sort(res.begin(), res.end(), cmp);
    for (int j = 0; j < res.size(); j++) {
        if (j > 0 && res[j].points == res[j - 1].points) {
            res[j].global_ranking = res[j - 1].global_ranking;
        }
        else {
            res[j].global_ranking = j + 1;
        }
    }
    cout << res.size() << endl;
    for (int j = 0; j < res.size(); j++) {
        cout << res[j].id << " " << res[j].global_ranking << " " << res[j].location << " " << res[j].local_ranking << endl;
    }
    return 0;
}

/*
这题就是直接读进来分别排序然后压到一起再一起排序，跟不能不涉及什么merge和排序算法
*/