#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <set>

using namespace std;

int main () {
    string str1;
    getline(cin, str1);
    string str2;
    getline(cin, str2);
    set <char> letters;
    for (int i = 0; i < str2.size(); i++) {
        letters.insert(str2[i]);
    }
    for (int i = 0; i < str1.size(); i++) {
        if (letters.find(str1[i]) == letters.end()) {
            printf("%c", str1[i]);
        }
    }
    system("pause");
    return 0;
}

/*
没坑，过
*/