#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    int time;
    if ((c2 - c1) % 100 >= 50) {
        time = (c2 - c1) / 100 + 1;
    }
    else {
        time = (c2 - c1) / 100;
    }
    int h = time / 3600;
    int m = (time %3600) / 60;
    int s = time % 60;
    printf("%02d:%02d:%02d", h, m, s);
    system("pause");
    return 0;
}