#include "stdio.h"
#include "stdbool.h"
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
// For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1,
// 2, 3, 4]. Return its length: 4.
// Your algorithm should run in O(n) complexity.

//定义一个大数组用来HASH

int g_arry[10000] = {0};
int SearchTarNum(int *num, int len)
{
    int maxLen;
    int data = 0;
    for (int i = 0; i < len; i++) {
        g_arry[num[i]] = 1;
    }
    for (int i = 0; i < len; i++) {
        maxLen = 1;
        for (int j = num[i] + 1; j < 10000 && g_arry[j] == 1; j++) {
            maxLen += 1;
        }

        for (int j = num[i] - 1; j > 0 &&  g_arry[j] == 1; j--) {
            maxLen += 1;
        }
        data = data > maxLen ? data:maxLen;
    }
    return data;
}

void test_01(void)
{
    int num[6] = {100, 5, 5, 4, 7, 6};
    int target;
    target = SearchTarNum(num, 6);
    printf("test_01 = %d\n", target);
}


int main()
{
    test_01();
    return 0;
}
