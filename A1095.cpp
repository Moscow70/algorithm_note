#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef struct car_info {
    string id;
    int time[5];
    int status;

    bool operator == (const string &x) {
        return (this->id == x);
    }
}info;

typedef struct query_detail {
    int time[4];
}qinfo;



bool cmp (info a, info b) {
    if (a.id != b.id) {
        return a.id < b.id;
    }
    else {
        return a.time[3] < b.time[3];
    }
}

bool cmp_res (info a, info b) {
    return a.time[4] != b.time[4]? a.time[4] > b.time[4] : a.id < b.id;
}

int main () {
    int record, query;
    scanf ("%d %d", &record, &query);
    vector <info> data;
    info temp;
    map <string, int> parktime;
    for (int i = 0; i < record; i++) {
        cin >> temp.id;
        scanf("%d:%d:%d", &temp.time[0], &temp.time[1], &temp.time[2]);
        temp.time[3] = temp.time[2] + temp.time[1] * 60 + temp.time[0] * 60 * 60;
        temp.time[4] = 0;
        string state;
        cin >> state;
        if (state == "in") {
            temp.status = 0;
        }
        else {
            temp.status = 1;
        }
        data.push_back(temp);
    }
    sort (data.begin(), data.end(), cmp);
    vector <info> data_valid;
    vector <info> data_for_time;
    int maxtime = -1;
    // cout << "-----------------------" << endl;
    // cout << "Current valid data :" << endl;
    // for (int i = 0; i < data.size(); i++) {
    //     cout << data[i].id << " " << data[i].status << " " << data[i].time[0] << ":" << data[i].time[1] << ":" << data[i].time[2] << endl;
    // }
    // cout << endl;


    for (int i = 0; i < record; i++) {
        if (i > 0 && data[i].id == data[i - 1].id) {
            if (data[i].status == 1 && data[i - 1].status == 0) {
                if (parktime.find(data[i].id) == parktime.end()) {
                    parktime[data[i].id] = 0;
                }
                parktime[data[i].id] += (data[i].time[3] - data[i - 1].time[3]);
                if (maxtime < parktime[data[i].id]) {
                    maxtime = parktime[data[i].id];
                }
                // auto it = find (data_for_time.begin(), data_for_time.end(), data[i].id);
                // if (it != data_for_time.end()) {
                //     it->time[4] = it->time[4] + (data[i].time[3] - data[i - 1].time[3]);
                // }
                // else {
                //     data_for_time.push_back(data[i]);
                //     data_for_time[data_for_time.size() - 1].time[4] = data[i].time[3] - data[i - 1].time[3];
                // }
                data_valid.push_back(data[i - 1]);
                data_valid.push_back(data[i]);
            }
        }
    }
    sort (data_for_time.begin(), data_for_time.end(), cmp_res);
    qinfo t;
    int num = 0;
    for (int i = 0; i < query; i++) {
        num = 0;
        scanf("%d:%d:%d", &t.time[0], &t.time[1], &t.time[2]);
        t.time[3] = t.time[2] + t.time[1] * 60 + t.time[0] * 60 * 60;
        for (int j = 1; j < data_valid.size(); j = j + 2) {//是这里循环次数太多了，它一定是两个一组，所以循环次数可以减半
            if (t.time[3] < data_valid[j].time[3] && data_valid[j].status == 1) {
                if (j > 0 && t.time[3] >= data_valid[j - 1].time[3] && data_valid[j - 1].status == 0) {
                    num++;
                }
            }
        }
        printf ("%d\n", num);
    }
    // if (!data_for_time.empty()) {
    //     cout << data_for_time[0].id << " ";
    //     data_for_time[0].time[0] = data_for_time[0].time[4] / (60 * 60);
    //     data_for_time[0].time[1] = (data_for_time[0].time[4] % 3600) / 60;
    //     data_for_time[0].time[2] = data_for_time[0].time[4] % 60;
    // }
    map <string, int> :: iterator it;
    for (it = parktime.begin(); it != parktime.end(); it++) {
        if (it->second == maxtime) {
            cout << it->first << " ";
        }
    }
    // for (int i = 1; i < data_for_time.size(); i++) {
    //     if (data_for_time[i].time[4] == data_for_time[i - 1].time[4]) {
    //         cout << data_for_time[i].id << " ";
    //     }
    // }
    // if (!data_for_time.empty()) {
    //     printf ("%02d:%02d:%02d", data_for_time[0].time[0], data_for_time[0].time[1], data_for_time[0].time[2]);
    // }
    printf ("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
    // cout << endl;
    // cout << "-----------------------" << endl;
    // cout << "Current valid data :" << endl;
    // for (int i = 0; i < data_valid.size(); i++) {
    //     cout << data_valid[i].id << " " << data_valid[i].status << " " << data_valid[i].time[0] << ":" << data_valid[i].time[1] << ":" << data[i].time[2] << endl;
    // }
    system("pause");
    return 0;
}


/*
这题要用map或者find函数，但是find函数可能会超时（应该是这里超时了
md，不是这超时

是循环找车辆数量的时候超时了，但是它答案按时间来找怎么不超时呢，时间不是循环更多么
哦不对，答案里有需要小于有效条数，那就是我这里循环次数减半
*/