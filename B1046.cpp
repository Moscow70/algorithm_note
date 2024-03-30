#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a1, a2, b1, b2;
    int counta = 0;
    int countb = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        if (a2 == a1 + b1 && b2 != a1 + b1) {
            countb++;
        }
        else if (a2 != a1 + b1 && b2 == a1 + b1) {
            counta++;
        }
        else {

        }
    }
    printf("%d %d", counta, countb);
    system("pause");
    return 0;
}