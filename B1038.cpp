#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int hashmap[101] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        hashmap[temp]++;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        cout << hashmap[temp];
        if (i != k - 1) {
            cout << " ";
        }
    }
    return 0;
}

/*
没坑，跳
*/