#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    long long a, b;
    int da, db;
    long long a1 = 0;
    long long b1 = 0;
    scanf("%lld%d%lld%d", &a, &da, &b, &db);
    while (a > 0) {
        if (a % 10 == da) {
            a1 = a1 * 10 + (a % 10);
        }
        a = a / 10;
    }
    while (b > 0) {
        if (b % 10 == db) {
            b1 = b1 * 10 + (b % 10);
        }
        b = b / 10;
    }
    long long res;
    res = a1 + b1;
    printf("%d\n", res);
    system("pause");
    return 0;
}