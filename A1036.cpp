#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

typedef struct student_info {
    string name;
    string gender;
    string ID;
    int score;
}info;

int main () {
    int n;
    scanf("%d", &n);
    info temp;
    int flagm = 0;
    int flagf = 0;
    info lowestm = {"", "", "", 100};
    info highestf = {"", "", "", 0};

    for (int i = 0; i < n; i++) {
        cin >> temp.name >> temp.gender >> temp.ID >> temp.score;
        if (temp.gender == "M") {
            flagm = 1;
        }
        if (temp.gender == "F") {
            flagf = 1;
        }
        if (temp.gender == "M" && temp.score < lowestm.score) {
            lowestm = temp;
        }
        if (temp.gender == "F" && temp.score > highestf.score) {
            highestf = temp;
        }
    }
    int dif = highestf.score - lowestm.score;
    if (flagf == 1) {
        cout << highestf.name << " " << highestf.ID << endl;
    }
    else {
        cout << "Absent" << endl;
    }
    if (flagm == 1) {
        cout << lowestm.name << " " << lowestm.ID << endl;
    }
    else {
        cout << "Absent" << endl;
    }
    if (flagf == 1 && flagm == 1) {
        cout << dif;
    }
    else {
        cout << "NA";
    }
    return 0;
}

/*
没坑，过
*/