#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>

using namespace std;

typedef struct student_info {
    int id;
    int rank;
    int ge;
    int gi;
    int sum;
    int volun[5];
}info;

bool cmp (info a, info b) {
    if (a.sum != b.sum) {
        return a.sum > b.sum;
    }
    else if (a.ge != b.ge) {
        return a.ge > b.ge;
    }
    else {
        return a.id < b.id;
    }
}

bool cmp_id (info a, info b) {
    return a.id < b.id;
}


int main () {
    int applicant, school, choice;
    cin >> applicant >> school >> choice;
    vector <int> quota;
    for (int i = 0; i < school; i++) {
        int temp;
        cin >> temp;
        quota.push_back(temp);
    }
    vector <info> data;
    for (int i = 0; i < applicant; i++) {
        info temp;
        cin >> temp.ge >> temp.gi;
        temp.id = i;
        temp.sum = temp.ge + temp.gi;
        for (int j = 0; j < choice; j++) {
            cin >> temp.volun[j];
        }
        for (int j = choice; j < 5; j++) {
            temp.volun[j] = -1;
        }
        data.push_back(temp);
    }
    sort (data.begin(), data.end(), cmp);
    for (int i = 0; i < applicant; i++) {
        if (i > 0 && data[i].sum == data[i - 1].sum && data[i].ge == data[i - 1].ge) {
            data[i].rank = data[i - 1].rank;
        }
        else {
            data[i].rank = i;
        }
    }
    vector <vector <info>> volunteer;
    for (int i = 0; i < school; i++) {
        vector <info> temp;
        temp.clear();
        volunteer.push_back(temp);
    }
    for (int i = 0; i < applicant; i++) {
        for (int j = 0; j < choice; j++) {
            if (quota[data[i].volun[j]] > volunteer[data[i].volun[j]].size()) {
                volunteer[data[i].volun[j]].push_back(data[i]);
                break;
            }
            else {
                if (data[i].rank == volunteer[data[i].volun[j]][volunteer[data[i].volun[j]].size() - 1].rank) {
                    volunteer[data[i].volun[j]].push_back(data[i]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < volunteer.size(); i++) {
        sort (volunteer[i].begin(), volunteer[i].end(), cmp_id);
        for (int j = 0; j < volunteer[i].size(); j++) {
            cout << volunteer[i][j].id;
            if (j != volunteer[i].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    system("Pause");
    return 0;
}

/*
不算太有坑，注意只要录取了（无论是按顺序还是破格）都要break
*/