#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

int main () {
    string temp;
    cin >> temp;
    int data[6] = {0};
    int num = 0;
    for (int i = 0; i < temp.size(); i++) {
        switch (temp[i])         {
        case 'P':
            data[0]++;
            break;
        case 'A':
            data[1]++;
            break;
        case 'T':
            data[2]++;
            break;
        case 'e':
            data[3]++;
            break;
        case 's':
            data[4]++;
            break;
        case 't':
            data[5]++;
            break;
        default:
            break;
        }
    }
    num = data[0] + data[1] + data[2] + data[3] + data[4] + data[5];
    for (int i = 0; i < num; i++) {
        if (data[0] > 0) {
            cout << "P";
            data[0]--;
        }
        if (data[1] > 0) {
            cout << "A";
            data[1]--;
        }
        if (data[2] > 0) {
            cout << "T";
            data[2]--;
        }
        if (data[3] > 0) {
            cout << "e";
            data[3]--;
        }
        if (data[4] > 0) {
            cout << "s";
            data[4]--;
        }
        if (data[5] > 0) {
            cout << "t";
            data[5]--;
        }
    }
    system("pause");
    return 0;
}

/*
没坑，过
*/