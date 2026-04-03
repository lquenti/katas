#include<bits/stdc++.h>
class Solution {
  public:
    int removeElement(std::vector<int> &nums, int val) {
      size_t l{0}, r{0};
      while (r<nums.size()) {
        if (nums[r] != val) {
          if (r!=l) {
            nums[l]=nums[r];
          }
          l++;
        }
        r++;
      }
      return l;
    }
};
