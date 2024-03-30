#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector <string> account;
    vector <string> pwd;
    account.clear();
    pwd.clear();
    int flag = 1;
    for (int i = 0; i < n; i++) {
        flag = 1;
        string acc, password;
        cin >> acc >> password;
        for (int j = 0; j < password.size(); j++) {
            if (password[j] == '1') {
                password[j] = '@';
                flag = 0;
            }
            if (password[j] == '0') {
                password[j] = '%';
                flag = 0;
            }
            if (password[j] == 'l') {
                password[j] = 'L';
                flag = 0;
            }
            if (password[j] == 'O') {
                password[j] = 'o';
                flag = 0;
            }
        }
        if (flag == 0) {
            account.push_back(acc);
            pwd.push_back(password);
        }
    }
    if (account.size() == 0) {
        if (n == 1) {
            cout << "There is 1 account and no account is modified";
        }
        else {
            cout << "There are " << n << " accounts and no account is modified";
        }
    }
    else {
        cout << account.size() << endl;
        for (int i = 0; i < account.size(); i++) {
            cout << account[i] << " " << pwd[i];
            if (i != account.size() - 1) {
                cout << endl;
            }
        }
    }
    return 0;
}

/*
没坑，跳
这题可以用用结构体，熟练一下
*/