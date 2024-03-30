#include <stdio.h>

using namespace std;

int max2(int a, int b) {
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int max3(int a, int b, int c) {
    return max2(max2(a, b), c);
}

int main() {
    int n;
    scanf("%d", &n);
    int freqA[3] = {0, 0, 0};
    int freqB[3] = {0, 0, 0};
    int winA = 0;
    int winB = 0;
    int loseA = 0;
    int loseB = 0;
    int neuA = 0;
    int neuB = 0;
    char a, b;
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c", &a, &b);      
        if (a == 'B' && b == 'C') {
            winA++;
            loseB++;
            freqA[0]++;
        }
        else if (a == 'C' && b == 'J') {
            winA++;
            loseB++;
            freqA[1]++;
        }
        else if (a == 'J' && b == 'B') {
            winA++;
            loseB++;
            freqA[2]++;
        }
        else if (b == 'B' && a == 'C') {
            winB++;
            loseA++;
            freqB[0]++;
        }
        else if (b == 'C' && a == 'J') {
            winB++;
            loseA++;
            freqB[1]++;
        }
        else if (b == 'J' && a == 'B') {
            winB++;
            loseA++;
            freqB[2]++;
        }
        else {
            neuA++;
            neuB++;
        }

    }
    printf("%d %d %d\n", winA, neuA, loseA);
    printf("%d %d %d\n", winB, neuB, loseB);
    int maxA;
    int maxB;
    char resA;
    char resB;
    if (freqA[0] >= freqA[1]) {
        if (freqA[0] >= freqA[2]) {
            resA = 'B';
        }
        else {
            resA = 'J';
        }
    }
    else {
        if (freqA[1] >= freqA[2]) {
            resA = 'C';
        }
        else {
            resA = 'J';
        }
    }
    if (freqB[0] >= freqB[1]) {
        if (freqB[0] >= freqB[2]) {
            resB = 'B';
        }
        else {
            resB = 'J';
        }
    }
    else {
        if (freqB[1] >= freqB[2]) {
            resB = 'C';
        }
        else {
            resB = 'J';
        }
    }    
    printf("%c %c", resA, resB);
    return 0;
}