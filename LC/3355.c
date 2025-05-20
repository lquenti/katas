#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
  int *zeros = calloc(numsSize+1, sizeof(int));
  for (int i=0; i<queriesSize; ++i) {
    zeros[queries[i][0]]--;
    zeros[queries[i][1]+1]++;
  }
  int offset=0;
  for (int i=0; i<numsSize; ++i) {
    offset += zeros[i];
    assert(offset <= 0);
    if (nums[i]+offset > 0) {
      return false;
    }
  }
  free(zeros);
  return true;
}
