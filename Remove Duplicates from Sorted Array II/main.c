#include "stdio.h"

// Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
// For example, Given sorted array A = [1,1,1,2,2,3],
// Your function should return length = 5, and A is now [1,1,2,2,3]

int RemoveDuplicates(int *num, int len)
{
    int index = 2;
    for (int i = 2; i < len; i++) {
        if (num[index - 2] != num[i])
            num[++index] = num[i];
        }
    return index;
}

void test_01(void)
{
    int num[6] = {1, 1, 1, 2, 2, 3};
    int len;
    len = RemoveDuplicates(num, 6);
    printf("test_01 = %d\n", len);
}


int main()
{
    test_01();
    return 0;
}
