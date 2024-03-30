#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>


using namespace std;

int main () {
    string s;
    vector <string> res;
    while (cin >> s) {
        res.push_back(s);
    }
    while (!res.empty()) {
        cout << res[res.size() - 1];
        res.pop_back();
        if (res.size() != 0) {
            cout << " ";
        }
    }
    return 0;    
}

/*
用到输入流的终止，但不知道为啥vscode又报错
*/