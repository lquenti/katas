int minimumOperations(int* nums, int numsSize) {
  int cnt=0;
  for (int i=0; i<numsSize; i+=3, ++cnt) {
    int hasDuplicate=0;
    for (int j=i; j<numsSize; ++j) {
      for (int k=j+1; k<numsSize; ++k) {
        if (nums[j] == nums[k]) {
          hasDuplicate = 1;
        }
      }
    }
    if (!hasDuplicate) {
      break;
    }
  }
  return cnt;
}
int main() {
}
