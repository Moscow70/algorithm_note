#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>

using namespace std;

int main () {
    string s;
    cin >> s;
    int left,right,bottom;
    int length = s.length() + 2;
    switch (length % 3)
    {
    case 0:
        left = length / 3;
        left--;
        right = left;
        bottom = s.length() - left - right;
        break;
    case 1:
        left = (length - 1) / 3;
        left--;
        right = left;
        bottom = s.length() - left - right;
        break;
    case 2:
        left = (length - 2) / 3;
        left--;
        right = left;
        bottom = s.length() - left - right;
        break;
    default:
        break;
    }
    for (int i = 0; i < left; i++) {
        cout << s[i];
        for (int j = 0; j < bottom - 2; j++) {
            cout << " ";
        }
        cout << s[s.length() - 1 - i] << endl;
    }
    for (int i = left; i < left + bottom; i++) {
        cout << s[i];
    }
    return 0;
}

/*
没啥坑
*/