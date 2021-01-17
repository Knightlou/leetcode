#include "stdio.h"

// Given a sorted array, remove the duplicates in place such that each element appear only once
// and return the new length.
// Do not allocate extra space for another array, you must do this in place with constant memory.
// For example, Given input array A = [1,1,2],
// Your function should return length = 2, and A is now [1,2].

int RemoveDuplicates(int *num, int len)
{
    int index = 0;
    for (int i = 1; i < len; i++) {
        if (num[index] != num[i])
            num[++index] = num[i];
        }
    return index + 1;
}

void test_01(void)
{
    int num[5] = {1, 1, 2, 2, 3};
    int len;
    len = RemoveDuplicates(num, 5);
    printf("test_01 = %d\n", len);
}


int main()
{
    test_01();
    return 0;
}
