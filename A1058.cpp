#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
    long long ga, sa, ka, gb, sb, kb;
    long long a = 0;
    long long b = 0;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &ga, &sa, &ka, &gb, &sb, &kb);
    a = ga * 17 * 29 + sa * 29 + ka;
    b = gb * 17 * 29 + sb * 29 + kb;
    long long res = a + b;
    long long resk = res % 29;
    long long ress = (res / 29) % 17;
    long long resg = res / (17 * 29);
    printf ("%lld.%lld.%lld", resg, ress, resk);
    return 0;
}

/*
这题跟B1037不是一样的么
数据有问题，根本不止10^7
*/