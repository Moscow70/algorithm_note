#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> res;
    long long a, b, c;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a + b > c) {
            res.push_back(1);
        }
        else {
            res.push_back(0);
        }
    }
    for (int i = 0; i < n; i++) {
        if (res[i] == 1) {
            printf("Case #%d:true", i);
        }
        else {
            printf("Case #%d:false", i);
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
    system("pause");
    return 0;
}