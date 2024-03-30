#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef struct game_rate {
    double W;
    double T;
    double L;
}info;

int maxodd (double w, double t, double l) {
    int res;
    if (w > t) {
        if (w > l) {
            res = 1;
        }
        else {
            res = 3;
        }
    }
    else {
        if (t > l) {
            res = 2;
        }
        else {
            res = 3;
        }
    }
    return res;
}

int main () {
    info board;
    double oddrate[3] = {0};
    char game[3] = {""};
    int maxid = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%lf%lf%lf", &board.W, &board.T, &board.L);
        maxid = maxodd(board.W, board.T, board.L);
        switch (maxid) {
            case 1:
                oddrate[i] = board.W;
                game[i] = 'W';
                break;
            case 2:
                oddrate[i] = board.T;
                game[i] = 'T';
                break;
            case 3:
                oddrate[i] =board.L;
                game[i] = 'L';
                break;
            default:
                break;
        }
    }
    double money = (oddrate[0] * oddrate[1] * oddrate[2] * 0.65 - 1) * 2;
    printf("%c %c %c %.2lf", game[0], game[1], game[2], money);
    return 0;
}

/*
没啥好说的，一遍过
*/