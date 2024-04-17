#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>

using namespace std;

int main () {
    int n, m;
    vector <int> data;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        data.push_back(temp);
    }
    sort (data.begin(), data.end());
    int flag = 0;
    int left = 0;
    int right = data.size() - 1;
    while (left < right) {
        if (data[left] + data[right] > m) {
            right--;
        }
        else if (data[left] + data[right] < m) {
            left++;
        }
        else if (data[left] + data[right] == m) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        cout << data[left] << " " << data[right];
    }
    else {
        cout << "No Solution";
    }
    system("pause");
    return 0;
}

/*
犯了点低级错误，不应该在双指针的时候用for循环
*/