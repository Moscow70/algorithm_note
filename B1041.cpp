#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

typedef struct student_info{
    string stu_num;
    int quiz_num; 
}info;

int main() {
    int n;
    scanf("%d", &n);
    string s;
    int t_num;
    info stu[1001] = {"", 0};
    for (int i = 0; i < n; i++) {
        cin >> s;
        scanf("%d", &t_num);
        scanf("%d", &stu[t_num].quiz_num);
        stu[t_num].stu_num = s;
        
    }
    int m;
    scanf("%d", &m);
    int temp;
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        cout << stu[temp].stu_num << " " << stu[temp].quiz_num;
        if (i != m) {
            printf("\n");
        }
    }
    return 0;
}