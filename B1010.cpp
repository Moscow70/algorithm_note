#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    int count = 0;
    vector<int> res;
    while (scanf("%d%d", &a, &b) != EOF) {
        if(b != 0) {
            a = a * b;
            b = b - 1;
            res.push_back(a);
            res.push_back(b);
            count++;
        }

    }
    if (count == 0) {
        printf("0 0");
    }
    for (int i = 0; i < 2 * count; i++) {
        printf("%d", res[i]);
        if (i < 2 * count - 1) {
            printf(" ");
        }
    }
    return 0;
}