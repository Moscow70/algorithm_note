#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct student_info {
    int id;
    int grade[4];
    int bestrank[4];
    char bestsubject;
}info;

int keywordround = 0;

bool cmp (info a, info b) {
    return a.grade[keywordround] > b.grade[keywordround];
}

int main () {
    int n, m;
    cin >> n >> m;
    vector <info> data;
    info temp; 
    for (int i = 0; i < n; i++) {
        cin >> temp.id >> temp.grade[0] >> temp.grade[1] >> temp.grade[2];
        temp.grade[3] = (temp.grade[0] + temp.grade[1] + temp.grade[2]) / 3;
        data.push_back(temp);
    }
    for (keywordround = 0; keywordround < 4; keywordround++) {
        sort(data.begin(), data.end(), cmp);
        for (int i = 0; i < data.size(); i++) {
            if (i > 0 && data[i].grade[keywordround] == data[i - 1].grade[keywordround]) {
                data[i].bestrank[keywordround] = data[i - 1].bestrank[keywordround];
            }
            else {
                data[i].bestrank[keywordround] = i + 1;
            }
        }
    }
    int query;
    for (int i = 0; i < m; i++) {
        cin >> query;
        int flag = 0;
        for (int j = 0; j < data.size(); j++) {
            if (data[j].id == query) {
                flag = 1;
                int best = 1000000;
                if (data[j].bestrank[3] < best) {
                    data[j].bestsubject = 'A';
                    best = data[j].bestrank[3];
                }
                if (data[j].bestrank[0] < best) {
                    data[j].bestsubject = 'C';
                    best = data[j].bestrank[0];
                }
                if (data[j].bestrank[1] < best) {
                    data[j].bestsubject = 'M';
                    best = data[j].bestrank[1];
                }
                if (data[j].bestrank[2] < best) {
                    data[j].bestsubject = 'E';
                    best = data[j].bestrank[2];
                }
                cout << best << " " << data[j].bestsubject << endl;
            }
        }
        if (flag == 0) {
            cout << "N/A" << endl;
        }
    }
    return 0;
}

/*
改进：
这个比较有点过于繁琐了，由于需要多轮比较不同结构体的关键词，故不要做成不同变量而是直接写成数组，靠全局变量来控制sort函数的比较条件
*/