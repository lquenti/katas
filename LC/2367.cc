#include<bits/stdc++.h>
class Solution {
  public:
    int arithmeticTriplets(std::vector<int>& nums, int diff) {
      std::unordered_map<int, size_t> xs;
      for (int i{0}; i<nums.size(); ++i) {
        xs[nums[i]]=i;
      }
      int cnt{0};
      for (int i{0}; i<nums.size(); ++i) {
        auto mid = xs.find(nums[i]+diff);
        auto end = xs.find(nums[i]+diff+diff);
        if (mid!=xs.end() && end!=xs.end() && mid->second > i && end->second > mid->second) {
          cnt++;
        }
      }
      return cnt;
    }
};
