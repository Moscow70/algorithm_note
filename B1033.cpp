#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <cstring>
#include <set>

using namespace std;

const int MAXL = 100010;

int main () {
    char str[MAXL];
    // string temp;
    set <char> broken;
    cin.getline(str, MAXL);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        broken.insert(str[i]);
    }
    string temp;
    cin >> temp;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] - 'a' >= 0 && temp[i] - 'z' <= 0) {
            char t = temp[i] - 'a' + 'A';
            if (broken.find(t) == broken.end()) {
                cout << temp[i];
            }
        }
        else if (temp[i] - '0' >= 0 && temp[i] - '9' <= 0) {
            if (broken.find(temp[i]) == broken.end()) {
                cout << temp[i];
            }
        }
        else if (temp[i] == '_' || temp[i] == ',' || temp[i] == '.' || temp[i] == '-') {
            if (broken.find(temp[i]) == broken.end()) {
                cout << temp[i];
            }
        }
        else if (temp[i] - 'A' >= 0 && temp[i] - 'Z' <= 0) {
            if (broken.find('+') == broken.end()) {
                if (broken.find(temp[i]) == broken.end()) {
                    cout << temp[i];
                }
            }
        }
        else {

        }
    }
    system("pause");
    return 0;
}

/*
这里第一行输入可能为空格，故cin读不进来
回忆一下怎么用字符数组输入输出
*/
