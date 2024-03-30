#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> nums;
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        nums.push_back(temp);
    }
    m = m % n;//m未必比n小，长于n的就不移动了，免得循环
    for (int i = n - m; i < n; i++) {
        printf("%d ", nums[i]);
    }
    for (int i = 0; i < n - m; i++) {
        printf("%d", nums[i]);
        if (i < n - m - 1) {
            printf(" ");
        }
    }
    system("pause");
    return 0;
}