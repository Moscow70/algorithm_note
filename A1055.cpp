#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct personal_info {
    string name;
    int age;
    int wealth;
}info;

typedef struct info_filter {
    int output;
    int min;
    int max;
}filter;

// bool cmp_age (info a, info b) {
//     if (a.age != b.age) {
//         return a.age < b.age;
//     }
//     else if (a.wealth != b.wealth) {
//         return a.wealth > b.wealth;
//     }
//     else {
//         return a.name < b.name;
//     }
// }

bool cmp_wealth (info a, info b) {
    if (a.wealth != b.wealth) {
        return a.wealth > b.wealth;
    }
    else {
        return a.age != b.age ? a.age < b.age : a.name < b.name;
    }
}

int min (int a, int b) {
    return a < b ? a : b;
}


int main () {
    int n, m;
    cin >> n >> m;
    vector <info> data;
    vector <filter> tool;
    data.clear();
    info temp;
    for (int i = 0; i < n; i++) {
        cin >> temp.name >> temp.age >> temp.wealth;
        data.push_back(temp);
    }
    filter t;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &t.output, &t.min, &t.max);
        tool.push_back(t);
    }
    sort(data.begin(), data.end(), cmp_wealth);
    vector <info> sector;
    vector <info> data_slime;
    data_slime.clear();
    int count = 0;
    int age[201] = {0};
    // for (int i = 0; i < n; i++) {
    //     if (i > 0 && data[i].age == data[i - 1].age) {
    //         count++;
    //     }
    //     else {
    //         count = 0;
    //     }
    //     if (count <= 100) {
    //         data_slime.push_back(data[i]);
    //     }
    // }
    for (int i = 0; i < n; i++) {
        age[data[i].age]++;
        if (age[data[i].age] <= 100) {
            data_slime.push_back(data[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        sector.clear();
        for (int j = 0; j < data_slime.size(); j++) {
            if (data_slime[j].age >= tool[i].min && data_slime[j].age <= tool[i].max) {
                sector.push_back(data_slime[j]);
            }
        }
        printf ("Case #%d:\n", i + 1);
        if (sector.empty()) {
            printf("None\n");
        }
        else {
            // sort(sector.begin(), sector.end(), cmp_wealth);//这一遍再排序依然会超时，答案不需要这一遍排序
            for (int k = 0; k < min(tool[i].output, sector.size()); k++) {
                cout << sector[k].name << " " << sector[k].age << " " << sector[k].wealth << endl;
            }
        }
    }
    system("pause");
    return 0;
}

/*
问题：
本题如果纯用vector存储，在用自己的预处理方法处理数据时需要按年龄排序，处理完毕后又需要按财富排序，依然会超时
改进：
答案使用数组下标代表年龄，这样年龄自动排好序了，只需一次排序即可
对自己的这个代码，也可以仅在预处理时使用数组，这样便不需要要求年龄已排好序，便可以仅按财富一次性排好序
*/