#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

typedef struct student_info {
    int flag;
    int id;
    int mortalpoint;
    int talentpoint;
    int total;
}info;

// void sortforpoints (vector <info> &res) {
//     info temp;
//     for (int i = 0; i < res.size() - 1; i++) {
//         for (int j = 0; j < res.size() - 1 - i; j++) {
//             if ((res[j].mortalpoint + res[j].talentpoint) < (res[j + 1].mortalpoint + res[j + 1].talentpoint)) {
//                 temp = res[j];
//                 res[j] = res[j + 1];
//                 res[j + 1] = temp;
//             }
//             else if ((res[j].mortalpoint + res[j].talentpoint) == (res[j + 1].mortalpoint + res[j + 1].talentpoint)) {
//                 if (res[j].mortalpoint < res[j + 1].mortalpoint) {
//                     temp = res[j];
//                     res[j] = res[j + 1];
//                     res[j + 1] = temp;                    
//                 }
//                 else if (res[j].mortalpoint == res[j + 1].mortalpoint) {
//                     if (res[j].id > res[j + 1].id) {
//                         temp = res[j];
//                         res[j] = res[j + 1];
//                         res[j + 1] = temp;                        
//                     }
//                 }
//             }
//         }
//     }
// }

bool cmp (info a, info b) {
    if (a.flag != b.flag)  {
        return a.flag < b.flag;
    }
    else if (a.total != b.total) {
        return a.total > b.total;
    }
    else if (a.mortalpoint != b.mortalpoint) {
        return a.mortalpoint > b.mortalpoint;
    }
    else {
        return a.id < b.id;
    }
}
int main () {
    int n, L, H;
    cin >> n >> L >> H;
    info temp;
    vector <info> res;
    for (int i = 0; i < n; i++) {
        cin >> temp.id >> temp.mortalpoint >> temp.talentpoint;
        if (temp.mortalpoint < L || temp.talentpoint < L) {
            continue;
        }
        temp.total = temp.mortalpoint + temp.talentpoint;
        if (temp.mortalpoint >= H && temp.talentpoint >= H) {
            temp.flag = 1;
        }
        else if (temp.mortalpoint >= H && temp.talentpoint < H){
            temp.flag = 2;
        }
        else if (temp.mortalpoint < H && temp.talentpoint < H && temp.mortalpoint >= temp.talentpoint) {
            temp.flag = 3;
        }
        else {
            temp.flag = 4;
        }
        res.push_back(temp);
    }
    int total = res.size();
    cout << total << endl;
    if (!res.empty()) {
        sort(res.begin(), res.end(), cmp);
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].id << " " << res[i].mortalpoint << " " << res[i].talentpoint << endl;
    }
    return 0;
}

/*
一次做题：
用冒泡排序超时了，用了太多vector来存
改进：
没有必要用4个vector来存，结构体里加入flag来判定属于哪一类即可
本题需要用系统自带的sort函数，但需要自己编写cmp函数
*/