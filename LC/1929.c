#include <stdlib.h>
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
  int *ret = malloc(2*numsSize  * sizeof(int));
  for (int i=0; i<numsSize; ++i) {
    ret[i] = nums[i];
    ret[numsSize+i] = nums[i];
  }
  *returnSize = 2*numsSize;
  return ret;
}
