#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      for (size_t i{0}; i<nums.size()-1;) {
        if (nums[i] == nums[i+1]) {
          for (size_t j{i}; j<nums.size()-1; ++j) {
            nums[j] = nums[j+1];
          }
          nums.pop_back();
        } else {
          i++;
        }
      }
      return nums.size();
    }
};
