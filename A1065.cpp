#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <iostream>


using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        long long temp = a + b;
        if (a > 0 && b > 0 && temp <= 0) {
            printf("Case #%d: true", i + 1);
        }
        else if (a < 0 && b < 0 && temp >=0) {
            printf("Case #%d: false", i + 1);
        }
        else {
            if (a + b > c) {
                printf("Case #%d: true", i + 1);
            }
            else {
                printf("Case #%d: false", i + 1);
            }
        }
        if (i < n - 1) {
            printf("\n");
        }
        // if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
        //     if (temp > c) {
        //         res.push_back(1);
        //     }
        //     else {
        //         res.push_back(0);
        //     }
        // }
        // else if (a > 0 && b > 0) {
        //     if (temp < 0) {
        //         res.push_back(1);
        //     }
        //     else {
        //         if (temp > c) {
        //             res.push_back(1);
        //         }
        //         else {
        //             res.push_back(0);
        //         }
        //     }
        // }
        // else if(a < 0 && b < 0) {
        //     if(temp >= 0) {
        //         res.push_back(0);
        //     }
        //     else {
        //         if (temp > c) {
        //             res.push_back(1);
        //         }
        //         else {
        //             res.push_back(0);
        //         }
        //     }
        // }
    }
    // for (int i = 0; i < n; i++) {
    //     if (res[i] == 1) {
    //         printf("Case #%d: true", i + 1);
    //     }
    //     else {
    //         printf("Case #%d: false", i + 1);
    //     }
    //     if(i < n - 1) {
    //         printf("\n");
    //     }
    // }
    return 0;
}