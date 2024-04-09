#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct number {
    int data;
    int rank;
    int times;
}num;


int main () {
    int n;
    cin >> n;
    num data[100001] = {0, 0, 0};
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        data[temp].data = temp;
        if (data[temp].times == 0) {
            data[temp].rank = i;
        }
        data[temp].times = data[temp].times + 1;
    }
    int firstrank = 100001;
    int uniquenumber = -1;
    for (int i = 1; i < 100001; i++) {
        if (data[i].times == 1) {
            if (data[i].rank < firstrank) {
                firstrank = data[i].rank;
                uniquenumber = data[i].data;
            }
        }
    }
    if (uniquenumber > 0) {
        printf ("%d", uniquenumber);
    }
    else {
        printf ("None");
    }
    system("pause");
    return 0;
}

/*
没坑，但是好像它的数据不一定在它给的范围内，数组要开大一点
*/