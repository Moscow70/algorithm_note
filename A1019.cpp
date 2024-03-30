#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
    int decn, b;
    scanf("%d%d", &decn, &b);
    int res[30] = {0};
    int i = 0;
    while (decn > 0) {
        res[i] = decn % b;
        i++;
        decn = decn / b;
    }
    int flag = 1;
    for (int j = 0; j < i / 2; j++) {
        if (res[j] != res[i - 1 - j]) {
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        printf ("Yes\n");
    }
    else {
        printf ("No\n");
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", res[j]);
        if (j != 0) {
            printf (" ");
        }
    }
    return 0;
}

/*
没坑，过
*/