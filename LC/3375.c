#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static int intcmp(const void *p1, const void *p2) {
  return (*((int *)p1)) - (*((int *)p2));
}
int minOperations(int* nums, int nums_size, int k) {
  // is it impossible?
  for (int i=0; i<nums_size; ++i) {
    if (nums[i] < k) {
      return -1;
    }
  }

  qsort(nums, nums_size, sizeof(int), intcmp);

  // is it already perfect
  int i=0;
  while (i<nums_size && nums[i] == k) {
    i++;
  }
  if (i>=nums_size) {
    return 0;
  }

  // for the rest, check how many unique there are (at least 1)
  int cnt=1, last_val = nums[i];
  i++;
  for (; i<nums_size; ++i) {
    if (nums[i] != last_val) {
      cnt++;
      last_val = nums[i];
    }
  }
  return cnt;
}

int main() {
  int nums[] = {1};
  int res = minOperations(nums, 1, 1);
  printf("%d\n", res);
}
