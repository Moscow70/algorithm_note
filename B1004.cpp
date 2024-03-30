#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

typedef struct student_info {
    string name;
    string student_number;
    int point;
}info;

int main() {
    int n;
    scanf("%d", &n);
    info max = {"", "", -1};
    info min = {"", "", 101};
    info temp;
    for (int i = 0; i < n; i++) {
        cin >> temp.name >> temp.student_number >> temp.point;
        if (temp.point < min.point) {
            min.name = temp.name;
            min.student_number = temp.student_number;
            min.point = temp.point;
        }

        if (temp.point > max.point) {
            max.name = temp.name;
            max.student_number = temp.student_number;
            max.point = temp.point;
        }
    }
    cout << max.name << " " << max.student_number << endl;
    cout << min.name << " " << min.student_number;
    return 0;
}