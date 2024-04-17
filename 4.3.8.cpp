#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>

using namespace std;

string str;
bool recursion(string str) {
    if (str.size() == 1) {
        return true;
    }
    else if (str.size() == 2) {
        if (str[0] == str[1]) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        bool resup = recursion(str.substr(1, str.size() - 2));
        bool resnow;
        if (str[0] != str[str.size() - 1]) {
            resnow = false;
        }
        else {
            resnow = true;
        }
        return (resup && resnow);
    }
}

int main () {
    cin >> str;
    bool res = recursion(str);
    if (res == true) {
        printf("Yes");
    }
    else {
        printf("No");
    }
    system("pause");
    return 0;
}

/*
略微思考了一下怎么写，想出来了，还行
*/