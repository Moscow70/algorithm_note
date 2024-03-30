#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> distance;
    vector<int> totaldistance;
    totaldistance.push_back(0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        distance.push_back(temp);
        sum = sum + temp;
        temp = totaldistance[i] + temp;
        totaldistance.push_back(temp);
    }
    // for (int i = 0; i < n; i++) {
    //     if (sum - totaldistance[i] < totaldistance[i]) {
    //         totaldistance[i] = sum - totaldistance[i];
    //     }
    // }
    int m;
    scanf("%d", &m);
    int q = m;
    vector<int> res;
    int a, b;
    int temp = 0;
    while (q > 0) {
        // int ldis = 0;
        // int rdis = 0;        
        scanf("%d%d", &a, &b);
        if (b - a < 0) {
            int t = b;
            b = a;
            a = t;
        }
        int dis = totaldistance[b - 1] - totaldistance[a - 1];
        int andis = sum - dis;
        // temp = a;
        // while (temp < b) {
        //     ldis = distance[temp - 1] + ldis;
        //     temp++;
        // } 
        // temp = a - 1;
        // while (temp > 0) {
        //     rdis = rdis + distance[temp - 1];
        //     temp--;
        // }
        // temp = n;
        // while (temp >= b) {
        //     rdis = rdis + distance[temp - 1];
        //     temp--;
        // }
        if (dis >= andis) {
            res.push_back(andis);
        }
        else {
            res.push_back(dis);
        }        
        q--;
    }
    for (int i = 0; i < m; i++) {
        printf("%d", res[i]);
        if (i < m - 1) {
            printf("\n");
        }
    }
    system("pause");
    return 0;
}