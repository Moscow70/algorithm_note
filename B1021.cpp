#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int main () {
    int current;
    string s;
    cin >> s;
    int i = 0;
    int res[10] = {0};
    while (s[i] != '\0') {
        res[(s[i] - '0')]++;
        i++;
    }
    for (i = 0; i < 10; i++) {
        if (res[i] != 0) {
            printf("%d:%d\n", i, res[i]);
        }
    }
    return 0;
}

/*
没坑，过
*/