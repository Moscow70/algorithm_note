#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

string s[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};


int main () {
    string s1, s2, s3, s4;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    cin >> s4;
    int flag = 2;
    int i = 0;
    string day;
    int h, m;
    int beacon;
    for (i = 0; i < s1.size() && i < s2.size(); i++) {
        if (s1[i] == s2[i]) {
            if (s1[i] >= 'A' && s2[i] <= 'G') {
                day = s[s1[i] - 'A'];
                break;
            }
        }
    }
    i++;
    for (; i < s1.size() && i < s2.size(); i++) { 
        if (s1[i] == s2[i]) {
            if (s1[i] >= 'A' && s1[i] <= 'N') {
                h = s1[i] - 'A' + 10;
                break;
            }
            else if (s1[i] >= '0' && s1[i] <= '9') {
                h = s1[i] - '0';
                break;
            }
        }
    }
    // while (flag > 0 && (i < s1.size()) && (i < s2.size())) {
    //     if ((s1[i] == s2[i]) && (s1[i] >= 'A') && (s1[i] <= 'N')) {
    //         if ((s1[i] <= 'G') || ((s1[i] > 'G') && (flag == 1))) {
    //             flag--;
    //         }
    //         if (flag == 1) {
    //             beacon = s1[i] - 'A';
    //             day = s[beacon];
    //         }
    //         if (flag == 0) {
    //             if ((s1[i] >= '0') && (s1[i] <= '9')) {
    //                 h = s1[i] - '0';
    //             }
    //             if ((s1[i] >= 'A') && (s1[i] <= 'N')) {
    //                 h = s1[i] - 'A' + 10;
    //             }
    //         }
    //     }
    //     i++;
    // }

    i = 0;
    flag = 0;
    for (i = 0; i < s3.size() && i < s4.size(); i++) {
        if (s3[i] == s4[i]) {
            if ((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z')) {
                m = i;
                break;
            }
        }
    }
    // while (flag == 0 && i < s3.size() && i < s4.size()) {
    //     if ((s3[i] == s4[i]) && (((s3[i] >= 'A') && (s3[i] <= 'Z')) || ((s3[i] >= 'a') && (s3[i] <= 'z')))) {
    //         flag++;
    //         break;
    //     }
    //     i++;
    // }
    // if (m == 60) {
    //     m = 0;
    //     h++;
    //     // if (h == 24) {
    //     //     h = 0;
    //     //     if (beacon != 6) {
    //     //         day = s[beacon + 1];
    //     //     }
    //     //     else {
    //     //         day = s[0];
    //     //     }
    //     // }
    // }
    cout << day << " " << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << m;
    return 0;
}

/*
首先这题也要保证i<s.size()，说明题目数据并不像其说的一样一定有解，虽然不知道这个情况要求的输出是什么但是这样改答案是对的
然后这题不用考虑24：00是第二天0：00的情况，考虑了反而错
这题有点毛病，我也不知道我的判断方法哪里有问题，反正就是几段最好分开判断，合一起就有问题
*/