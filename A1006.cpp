#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>

using namespace std;

typedef struct sign{
    string id;
    int sign_in;
    int sign_out;
}info;

int main () {
    int n;
    scanf("%d", &n);
    info temp;
    string id_temp;
    int hh,mm,ss;
    int min_sign_in = 23 * 3600 + 59 * 60 + 59;
    int max_sign_out = 0;
    string min_sign_in_id;
    string max_sign_out_id;
    for(int i = 0; i < n; i++) {
        cin >> id_temp;
        temp.id = id_temp;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        temp.sign_in = hh * 3600 + mm * 60 + ss;
        if (temp.sign_in < min_sign_in) {
            min_sign_in = temp.sign_in;
            min_sign_in_id = temp.id;
        }
        scanf("%d:%d:%d", &hh, &mm, &ss);
        temp.sign_out = hh * 3600 + mm * 60 + ss;
        if (temp.sign_out > max_sign_out) {
            max_sign_out = temp.sign_out;
            max_sign_out_id = temp.id;
        }
    }
    cout << min_sign_in_id << " " << max_sign_out_id;
    return 0;
}

/*
一遍过，没有坑
*/