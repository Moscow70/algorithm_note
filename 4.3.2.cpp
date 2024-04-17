#include <stdio.h>
#include <iostream>

using namespace std;

void recursion (int n) {
    if (n == 0) {
        printf("讲你妹的故事啊！快点去睡觉！！！");
    }
    else {
        printf("从前有座山，山上有座庙\n");
        printf("庙里有一个老和尚和一个小和尚\n");
        printf("睡前老和尚给小和尚讲故事：\n");
        recursion(n - 1);
        printf("\n");
        printf("然后老和尚和小和尚就睡觉啦");
    }
}

int main () {
    int n;
    scanf("%d", &n);
    recursion(n);
    system("pause");
    return 0;
}

/*
没坑，过
*/