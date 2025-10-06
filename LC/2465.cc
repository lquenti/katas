#include<bits/stdc++.h>
class Solution {
  public:
    int distinctAverages(std::vector<int>& nums) {
      size_t n{nums.size()};
      std::sort(nums.begin(), nums.end());
      std::unordered_set<double> avgs{};
      for (size_t i{0}; i<n/2; ++i) {
        avgs.insert(static_cast<double>(nums[i]+nums[n-1-i])/2);
      }
      return avgs.size();
    }
};
