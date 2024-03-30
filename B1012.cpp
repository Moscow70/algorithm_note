#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
    vector<int> a1;
    vector<int> a2;
    vector<int> a3;
    vector<int> a4;
    vector<int> a5;
    vector<int> nums;
    int temp;
    int n;
    scanf("%d", &n);
    while (n > 0) {
        scanf("%d", &temp);
        nums.push_back(temp);
        n--;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 5 == 0) {
            a1.push_back(nums[i]);
        }
        if (nums[i] % 5 == 1) {
            a2.push_back(nums[i]);
        }
        if (nums[i] % 5 == 2) {
            a3.push_back(nums[i]);
        }
        if (nums[i] % 5 == 3) {
            a4.push_back(nums[i]);
        }
        if (nums[i] % 5 == 4) {
            a5.push_back(nums[i]);
        }
    }
    int A1 = 0;
    int A2 = 0;
    int A3 = 0;
    double A4 = 0;
    int A5 = 0;
    if (a1.size() != 0) {
        for (int i = 0; i < a1.size(); i++) {
            if (a1[i] % 2 == 0) {
                A1 = A1 + a1[i];
            }
        } 
        printf("%d ", A1);
    }
    else {
        printf("N ");
    }
    if (a2.size() != 0) {
        for (int i = 0; i < a2.size(); i++) {
            if (i % 2 == 1) {
                A2 = A2 - a2[i];
            }
            else {
                A2 = A2 + a2[i];
            }
        }
        printf("%d ", A2);
    }
    else {
        printf("N ");
    }
    if (a3.size() != 0) {
        A3 = a3.size();
        printf("%d ", A3);
    }
    else {
        printf("N ");
    }
    
    if (a4.size() != 0) {
        for (int i = 0; i < a4.size(); i++) {
            A4 = A4 + a4[i];
        }
        A4 = A4 / a4.size();
        printf("%.1lf ", A4);
    }
    else {
        printf("N ");
    }
    if (a5.size() != 0) {
        for (int i = 0; i < a5.size(); i++) {
            if (a5[i] > A5) {
                A5 = a5[i];
            }
        }
        printf("%d", A5);
    }
    else {
        printf("N");
    }
    system("pause");
    return 0;
}