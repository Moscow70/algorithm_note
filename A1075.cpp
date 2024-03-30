#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct student_info {
    int id;
    int points[5];
    int sum;
    int perfectlysolve;
    int hassubmitted[5];
    int haspasscompile[5];
}info;

bool cmp (info a, info b) {
    if (a.sum != b.sum) {
        return a.sum > b.sum;
    }
    else if (a.perfectlysolve != b.perfectlysolve) {
        return a.perfectlysolve > b.perfectlysolve;
    }
    else {
        return a.id < b.id;
    }
}


int main () {
    int people, problem, submission;
    vector <int> fullpoints;
    fullpoints.clear();
    int temp;
    cin >> people >> problem >> submission;
    for (int i = 0; i < problem; i++) {
        cin >> temp;
        fullpoints.push_back(temp);
    } 
    info student[10001];
    for (int i = 0; i < 10001; i++) {
        student[i].id = 0;
        for (int j = 0; j < 5; j++) {
            student[i].points[j] = 0;
            student[i].hassubmitted[j] = 0;
            student[i].haspasscompile[j] = 0;
        }
        student[i].sum = 0;
        student[i].perfectlysolve = 0;
        
    }
    int ID, problem_id, partial_points;
    for (int i = 0; i < submission; i++) {
        cin >> ID >> problem_id >> partial_points;
        student[ID].id = ID;
        student[ID].hassubmitted[problem_id - 1] = 1;
        if (partial_points >= 0) {
            student[ID].haspasscompile[problem_id - 1] = 1;
        }
        if (partial_points == fullpoints[problem_id - 1] && student[ID].points[problem_id - 1] != fullpoints[problem_id - 1]) {
            student[ID].perfectlysolve++;
        }
        if (partial_points > student[ID].points[problem_id - 1]) {
            student[ID].points[problem_id - 1] = partial_points;
        }
    }
    for (int i = 1; i <= people; i++) {
        for (int j = 0; j < 5; j++) {
            student[i].sum += student[i].points[j];
        }
    }
    sort(student + 1, student + people + 1, cmp);
    int rank = 1;
    for (int i = 1; i <= people; i++) {
        if (i > 1 && student[i].sum == student[i - 1].sum) {
            
        }
        else {
            rank = i;
        }
        int flag = 0;
        for (int j = 0; j < 5; j++) {
            if (student[i].haspasscompile[j] != 0) {
                flag = 1;
                break;
            }
        }
        if (flag != 0) {
            printf ("%d %05d %d", rank, student[i].id, student[i].sum);
            for (int j = 0; j < problem; j++) {
                if (student[i].hassubmitted[j] != 0) {
                    printf (" %d", student[i].points[j]);
                }
                else {
                    printf (" -");
                }
            }
            printf ("\n");
        }
    }
    system("Pause");
    return 0;
}

/*
这题情况其实很多：
1.未提交任何一道题，全为-，不输出
2.全部提交但均未编译成功，全为0，不输出
3.全部提交通过编译但答案错误不得分，全为0，输出
4.有得分的题目，有不得分但通过编译的题目，有未通过编译的题目，有未答的题目，分别为x,0,0,-
只有前两种情况是不用输出的

犯了点傻逼错误，感觉以后变量不要用前缀有相同的东西
*/