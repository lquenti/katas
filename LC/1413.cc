#include<bits/stdc++.h>
class Solution {
  public:
    int minStartValue(std::vector<int>& nums) {
      int min=std::numeric_limits<int>::max(), curr{0};
      for (int n:nums) {
        curr+=n;
        min=std::min(min, curr);
      }
      return ((min>=0) ? 0 : -min)+1;
    }
};
