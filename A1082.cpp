#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>

using namespace std;

string name[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

string bytename[5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

int main () {
    string s;
    cin >> s;
    vector <string> res;
    res.clear();
    int flag0 = 0;
    int wansum = 0;
    if (s[0] == '-') {
        res.push_back("Fu");
        s.erase(0, 1);
    }
    if (s[0] != '-') {
        if (s.length() == 9) {
            res.push_back(name[s[0] - '0']);
            res.push_back(bytename[4]);
            s.erase(0, 1);
        }
        if (s.length() == 8) {
            wansum = wansum + (s[0] - '0');
            if (s[0] == '0') {
                flag0 = 1;
                res.push_back(name[0]);
            }
            else {
                flag0 = 0;
                res.push_back(name[s[0] - '0']);
                res.push_back(bytename[2]);
            }
            s.erase(0, 1);
        }
        if (s.length() == 7) {
            wansum = wansum + (s[0] - '0');
            if (s[0] == '0') {
                if (flag0 != 1) {
                    flag0 = 1;
                    res.push_back(name[0]);
                }
            }
            else {
                flag0 = 0;
                res.push_back(name[s[0] - '0']);
                res.push_back(bytename[1]);
            }
            s.erase(0, 1);
        }
        if (s.length() == 6) {
            wansum = wansum + (s[0] - '0');
            if (s[0] == '0') {
                if (flag0 != 1) {
                    flag0 = 1;
                    res.push_back(name[0]);
                }
            }
            else {
                flag0 = 0;
                res.push_back(name[s[0] - '0']);
                res.push_back(bytename[0]);
            }
            s.erase(0, 1);
        }
        if (s.length() == 5) {
            wansum = wansum + (s[0] - '0');
            if (s[0] == '0') {
                if (flag0 != 1) {
                    flag0 = 1;
                    res.push_back(name[0]);
                }
            }
            else {
                flag0 = 0;
                res.push_back(name[s[0] - '0']);
            }
            if (res[res.size() - 1] == name[0]) {
                res.pop_back();
            }
            if (wansum != 0) {
                res.push_back(bytename[3]);
            }
            s.erase(0, 1);
        } 
        if (s.length() == 4) {
            if (s[0] == '0') {
                flag0 = 1;
                res.push_back(name[0]);
            }
            else {
                flag0 = 0;
                res.push_back(name[s[0] - '0']);
                res.push_back(bytename[2]);
            }
            s.erase(0, 1);
        } 
        if (s.length() == 3) {
            if (s[0] == '0') {
                if (flag0 != 1) {
                    flag0 = 1;
                    res.push_back(name[0]);
                }
            }
            else {
                flag0 = 0;
                res.push_back(name[s[0] - '0']);
                res.push_back(bytename[1]);
            }
            s.erase(0, 1);
        } 
        if (s.length() == 2) {
            if (s[0] == '0') {
                if (flag0 != 1) {
                    flag0 = 1;
                    res.push_back(name[0]);
                }
            }
            else {
                flag0 = 0;
                res.push_back(name[s[0] - '0']);
                res.push_back(bytename[0]);
            }
            s.erase(0, 1);
        } 
        if (s.length() == 1) {
            if (s[0] == '0') {
                // if (flag0 != 1) {
                //     flag0 = 1;
                //     res.push_back(name[0]);
                // }
                // else {
                //     res.pop_back();
                // }
            }
            else {
                flag0 = 0;
                res.push_back(name[s[0] - '0']);
            }
            if (res.empty()) {
                res.push_back(name[0]);
            }
            else {
                if (res[res.size() - 1] == name[0]) {
                    res.pop_back();
                }
            }
            s.erase(0, 1);
        }                   
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << " ";
        }
    }
    return 0;
}

/*
纯纯枚举法，你妈的
甚至还没考虑完整，但是题目过了，例如800000008这种万部分全0的结果会输出ba Yi Wan ling ba，属于是出题人自己都考虑不全情况
已修改，现在这个代码完全对了
答案这一坨分析感觉更麻烦，虽然确实应该分析
*/