#include "stdio.h"
#include "stdbool.h"
// Follow up for ”Search in Rotated Sorted Array”: What if duplicates are allowed?
// Would this affect the run-time complexity? How and why?
// Write a function to determine if a given target is in the array.

bool SearchTarNum(int *num, int len, int target)
{
    int first = 0;
    int last = len;

    while (first != last) {
        const int mid = first + (last - first) / 2;
        if (num[mid] == target) {
            return true;
        } else if (num[first] < mid) {
            if (num[first] <= target && target < num[mid]) {
                last = mid;
            } else{
                first = mid + 1;
            }
        } else if (num[first] > mid){
            if (num[mid] > target && target <= num[last - 1]) {
                first = mid + 1;
            } else {
                last = mid;
            }
        } else {
            first++;
        }
    }
    return false;
}

void test_01(void)
{
    int num[6] = {1, 2, 3, 4, 5, 6};
    int target;
    target = SearchTarNum(num, 6, 7);
    printf("test_01 = %d\n", target);
}


int main()
{
    test_01();
    return 0;
}
