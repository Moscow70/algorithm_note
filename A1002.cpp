#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n1, n2;
    int e;
    double c;
    scanf("%d", &n1);
    double p[1010] = {0};
    int max1, max2;
    for (int i = 0; i < n1; i++) {
        scanf("%d%lf", &e, &c);
        p[e] = p[e] + c;
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d%lf", &e, &c);
        p[e] = p[e] + c;
    }
    int count = 0;
    for (int i = 0; i <= 1000; i++) {
        if (p[i] != 0) {
            count++;
        }
    }
    printf("%d", count);
    for (int i = 1000; i >= 0; i--) {
        if (p[i] != 0) {
            printf(" %d %.1lf", i, p[i]);
        }
    }
    return 0;
}