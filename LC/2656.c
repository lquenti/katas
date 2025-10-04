int maximizeSum(int* nums, int numsSize, int k) {
  int max=0;
  for (int i=0; i<numsSize; ++i) {
    if (max<nums[i]) max=nums[i];
  }
  int ret=0;
  for (int i=0;i<k;++i) {
    ret+=max;
    max++;
  }
  return ret;
}
