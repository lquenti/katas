#include <stdint.h>
#include <stdio.h>
int subsetXORSum(int* nums, int numsSize) {
  int ret = 0;
  for (uint32_t bitmask=1; bitmask<(1<<numsSize); ++bitmask) {
    int curr = -1;
    for (int i=0; i<numsSize; ++i) {
      if (!(bitmask & (1<<i))) {
        continue;
      }
      if (curr == -1) {
        curr = nums[i];
      } else {
        curr ^= nums[i];
      }
    }
    ret += curr;
  }

  return ret;
}


int main() {
  int arr1[] = {1,3};
  printf("%d\n", subsetXORSum(arr1, 2));
  int arr2[] = {5,1,6};
  printf("%d\n", subsetXORSum(arr2, 3));
  int arr3[] = {3,4,5,6,7,8};
  printf("%d\n", subsetXORSum(arr3, 6));
}
