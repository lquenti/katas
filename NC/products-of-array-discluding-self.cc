#include<bits/stdc++.h>
class Solution {
  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {
      std::vector<int> res(nums.size(), 1);

      // left side of it
      int acc{1};
      for (size_t i{1}; i<nums.size(); ++i) {
        acc*=nums[i-1];
        res[i]=acc;
      }

      // mult right side
      acc=1;
      for (int i=nums.size()-1; i>=0; --i) {
        acc*=nums[i];
        if (i > 0) {
          res[i-1]*=acc;
        }
      }

      return res;
    }
};

