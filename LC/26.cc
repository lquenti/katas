#include<bits/stdc++.h>
class Solution {
  public:
    int removeDuplicates(std::vector<int>& nums) {
      size_t i=0;
      while (i<nums.size()-1) {
        if (nums[i]==nums[i+1]) {
          nums.erase(nums.begin()+i+1);
        } else {
          ++i;
        }
      }
      return nums.size();
    }
};
