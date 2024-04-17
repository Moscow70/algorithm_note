#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>

using namespace std;

string str;

void recursion(int i) {
    if (i == str.size() - 1) {
        cout << str[i];
    }
    else {
        recursion(i + 1);
        cout << str[i];
    }
}

int main () {
    cin >> str;
    recursion(0);
    system("Pause");
    return 0;
}