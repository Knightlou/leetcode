#include "stdio.h"
#include "stdbool.h"
// Given an array of integers, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, where
// index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not
// zero-based.
// 2.1 ᪟㏳ 11
// You may assume that each input would have exactly one solution.
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2
typedef struct Num{
    int value;
    int index;
} NumStru;

NumStru g_arry[1000] = {0,0};
int result[2];

int* SearchTarNum(int *num, int len, int target)
{
    int diff;
    // for (int i = 0; i < len; i++) {
    //     diff = target - num[i];
    //     for (int j = 0; j < len; j++) {
    //         if (num[j] == diff) {
    //             result[0] = i;
    //             result[1] = j;
    //             return result; 
    //         }
    //     }
    // }
    for (int i = 0; i< len; i++) {
        g_arry[num[i]].value = 1;
        g_arry[num[i]].index = i;
    }
    for (int i = 0; i < len; i++) {
        diff = target - num[i];
        if (g_arry[diff].value == 1) {
            result[0] = i;
            result[1] = g_arry[diff].index;
            return result;  
        }
    }
    return NULL;
}

void test_01(void)
{
    int num[6] = {100, 4, 5, 0, 7, 6};
    int* target;
    target = SearchTarNum(num, 6, 9);
    printf("test_01 = %d  %d\n", target[0], target[1]);
}


int main()
{
    test_01();
    return 0;
}
