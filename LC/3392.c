#include<stdlib.h>
int countSubarrays(int* nums, int numsSize) {
  int cnt=0;
  for (size_t i=0; i<numsSize-2; ++i)
    if (nums[i+1]%2 == 0 && nums[i]+nums[i+2] == nums[i+1]/2) cnt++;
  return cnt;
}
