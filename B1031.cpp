#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>

using namespace std;

const int br[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const char zm[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main () {
    int n;
    scanf("%d", &n);
    vector <string> error;
    error.clear();
    int flag = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int j = 0;
        sum = 0;
        flag = 1;
        while (j < 17) {
            if ((s[j] - '0' > 9) || (s[j] - '0' < 0)) {
                flag = 0;
                error.push_back(s);
                break;
            }
            else {
                sum = sum + br[j] * (s[j] - '0');
            }
            j++;
        }
        int check = sum % 11;
        if ((j == 17) && (zm[check] != s[17])) {
            flag = 0;
            error.push_back(s);
        }
    }

    if (!error.empty()) {
        for (int i = 0; i < error.size(); i++) {
            cout << error[i] << endl;
        }
    }
    else {
        cout << "All passed";
    }
    return 0;

}

/*
这些判断状态的参数一定要注意有没有复原，以及不要重复判定是否非法
*/