#include <stdlib.h>
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
  int *ret = malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;
  size_t ret_i=0;

  for (int i=0; i<numsSize; ++i) {
    if (nums[i] < pivot) {
      ret[ret_i] = nums[i];
      ret_i++;
    }
  }
  for (int i=0; i<numsSize; ++i) {
    if (nums[i] == pivot) {
      ret[ret_i] = nums[i];
      ret_i++;
    }
  }
  for (int i=0; i<numsSize; ++i) {
    if (nums[i] > pivot) {
      ret[ret_i] = nums[i];
      ret_i++;
    }
  }
  return ret;
}
