#include <stdio.h>
int findNumbers(int* nums, int numsSize) {
  int cnt=0;
  for (int i=0; i<numsSize; ++i) {
    int d=0;
    while (nums[i]) {
      d++;
      nums[i]/=10;
    }
    if (d%2==0) cnt++;
  }
  return cnt;
}
