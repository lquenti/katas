#include <stdlib.h>
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
  int *ret = malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;
  for (int i=0; i<n; ++i) {
    ret[2*i] = nums[i];
    ret[2*i+1] = nums[n+i];
  }
  return ret;
}
