#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique
// triplets in the array which gives the sum of zero.
// Note:
// • Elements in a triplet (a, b, c) must be in non-descending order. (ie, a ≤ b ≤ c) • The solution set must not contain duplicate triplets.
// For example, given array S = {-1 0 1 2 -1 -4}.
// A solution set is:
// (-1, 0, 1)
// (-1, -1, 2)

int result[3];

int Cmp( const void *a, const void *b) 
{
    return *((int *)a) - *((int *)b);
}

int* SearchTarNum(int *num, int len)
{
    const int target = 0;
    // 先排序
    qsort(num, len, sizeof(int), Cmp);
    // 采用左右夹逼法
    int last = len - 1;
    for(int i = 0; i < len - 2; i++) {
        int next = i + 1;
        if(i> 0 && num[i] == num[i - 1]) {
            i += 1;
            continue;
        }
        while(next < last) {
            if(num[i] + num[next] + num[last] > target) {
            last -= 1;
            while ( (next < last) && (num[last] == num[last + 1])) {
                last -= 1; // 去重
            }
        } else if ( num[i] + num[next] + num[last] < target) {
            next += 1;
            while ((next < last) && (num[next] == num[next - 1])) {
                next += 1; // 去重
            }
        } else {
            result[0] = num[i];
            result[1] = num[next];
            result[2] = num[last];
            next += 1;
            last -= 1;
            while ((next < last) &&(num[next] == num[next - 1]) && (num[last] == num[last + 1]))  {
                next += 1;
            }
        }
        }
       
    }
    return result;
}

void test_01(void)
{
    int num[6] = {-1,0,1,2,-1,-4};
    int* target;
    target = SearchTarNum(num, 6);
    printf("test_01 = %d %d %d\n", target[0], target[1],target[2]);
}


int main()
{
    test_01();
    return 0;
}
