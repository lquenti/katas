#include<bits/stdc++.h>
class Solution {
  public:
    int findMaxConsecutiveOnes(std::vector<int> &nums) {
      int res{0};
      int curr{0};
      for (int i{0}; i<nums.size(); ++i) {
        if (nums[i]==1) {
          curr++;
          res=std::max(res,curr);
        } else {
          curr=0;
        }
      }
      return res;
    }
};
