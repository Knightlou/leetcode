#include "stdio.h"

// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.

int SearchTarNum(int *num, int len, int target)
{
    // for(int i = 0; i < len; i++) {
    //     if (target == num[i]) {
    //         return i;
    //     }
    // }
    int first = 0;
    int last = len;

    while (first != last) {
        const int mid = first + (last - first) / 2;
        if (num[mid] == target) {
            return mid;
        } else if (num[first] <= mid) {
            if (num[first] <= target && target < num[mid]) {
                last = mid;
            } else {
                first = mid + 1;
            }
        } else {
            if (num[mid] > target && target <= num[last - 1]) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
    }
    return -1;
}

void test_01(void)
{
    int num[6] = {1, 2, 3, 4, 5, 6};
    int target;
    target = SearchTarNum(num, 6, 3);
    printf("test_01 = %d\n", target);
}


int main()
{
    test_01();
    return 0;
}
