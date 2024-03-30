#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int main() {
    // int iter;
    // scanf("%d", &iter);
    // int order[54];
    // for (int i = 0;i < 54; i++) {
    //     scanf("%d", &order[i]);
    // }
    string kards[54];
    for (int i = 0; i < 13; i++) {
        kards[i] = "S" + i;
    }
    for (int i = 13; i < 26; i++) {
        kards[i] = 'H' + i;
    }
    for (int i = 13; i < 26; i++) {
        kards[i] = 'C' + i;
    }
    for (int i = 13; i < 26; i++) {
        kards[i] = 'D' + i;
    }
    kards[52] = "J1";
    kards[53] = "J2";
    return 0;
}