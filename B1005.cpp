#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool cmp (int a, int b) {
    return a > b;
}

int main () {
    int n;
    cin >> n;
    // vector <set <int>> data;
    // int flag = 0;
    // for (int i = 0; i < n; i++) {
    //     int nownum;
    //     cin >> nownum;
    //     flag = 0;
    //     for (int j = 0; j < data.size(); j++) {
    //         if (data[j].find(nownum) != data[j].end()) {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 1) {
    //         continue;
    //     }
    //     set <int> isunique;
    //     isunique.insert(nownum); 
    //     while (nownum != 1) {
    //         if (nownum % 2 == 0) {
    //             nownum = nownum / 2;
    //         }
    //         else {
    //             nownum = (nownum * 3 + 1) / 2;
    //         }
    //         isunique.insert(nownum);
    //     }
    //     for (int j = 0; j < data.size(); j++) {
    //         if (isunique.find(data[j]))
    //     }
    // }
    set <int> hashmap;
    vector <int> data;
    vector <int> res;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        data.push_back(temp);
        while (temp != 1) {
            if (temp % 2 == 0) {
                temp = temp / 2;
            }
            else {
                temp = (temp * 3 + 1) / 2;
            }
            hashmap.insert(temp);
        }
    }
    for (int i = 0; i < n; i++) {
        if (hashmap.find(data[i]) == hashmap.end()) {
            res.push_back(data[i]);
        }
    }
    sort (res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++) {
        printf ("%d", res[i]);
        if (i != res.size() - 1) {
            printf (" ");
        }
    }
    return 0;
}

/*
这题完全是想复杂了，即使先计算的数会被后计算的数覆盖到也不需要特殊方法来判断，只要把所有能算到的数全算到就可以了，
最后在所有输入的数中不在这个集合里的就是答案
*/