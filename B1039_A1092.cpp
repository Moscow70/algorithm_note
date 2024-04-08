#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <map>

using namespace std;

int main () {
    string provided;
    cin >> provided;
    map <char, int> data;
    for (int i = 0; i < provided.size(); i++) {
        data[provided[i]]++;
    }
    string need;
    cin >> need;
    int flag = 1;
    for (int i = 0; i < need.size(); i++) {
        if (data.find(need[i]) == data.end()) {
            data[need[i]] = -1;
            flag = 0;
        }
        else {
            data[need[i]]--;
            if (data[need[i]] < 0) {
                flag = 0;
            }
        }
    }
    int sum = 0;
    map <char, int> :: iterator it;
    for (it = data.begin(); it != data.end(); it++) {
        if (flag == 1) {
            if (it->second > 0) {
                sum = sum + it->second;
            }
        }
        if (flag == 0) {
            if (it->second < 0) {
                sum  = sum + it->second;
            }
        }
    }
    if (flag == 1) {
        cout << "Yes " << sum;
    }
    else {
        cout << "No " << -sum;
    }
    return 0;
}

/*
没坑，跳
*/