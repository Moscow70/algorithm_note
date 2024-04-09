#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <map>

using namespace std;

int main () {
    int n;
    cin >> n;
    map <int, int> data;
    int team, num, score;
    for (int i = 0; i < n; i++) {
        scanf("%d-%d %d", &team, &num, &score);
        if (data.find(team) == data.end()) {
            data[team] = 0;
        }
        data[team] = data[team] + score;
    }
    map <int, int> :: iterator it;
    int maxteam = -1;
    int maxscore = 0;
    for (it = data.begin(); it != data.end(); it++) {
        if (it->second > maxscore) {
            maxteam = it->first;
            maxscore = it->second;
        }
    }
    printf ("%d %d", maxteam, maxscore);
    return 0;
}

/*
没坑，跳
*/