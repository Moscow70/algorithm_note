#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int resdec = a + b;
    int res[31] = {0};
    int i = 0;
    while (resdec > 0) {
        res[i] = resdec % d;
        i++;
        resdec = resdec / d;
    }
    if (i == 0) {
        printf("0");
    }
    else {
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", res[j]);
        }
    }

    return 0;
}

/*
要理解什么是D进制，也即加到D就要归零进1，那么一个一个加即可。而十进制不能加成D进制，故十进制数先相加再换算
上述思路完全错了，所以本题写不出来

换算D进制，模D得某一位的值，除D得换算完一位的结果
要注意，由于给出了数据范围，最低的二进制用31位也可以存完，故开31位数组即可
结果为0时，j<0不会进入输出，但要输出结果0，所以要单列这种情况
*/