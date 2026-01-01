#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
#if 0
    /* Trivial N^2 solution */
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

    /* can also be solved in linear time using linear space with a (sorted) std::set */
#endif

    /* two pointer solution */
    int removeDuplicates(vector<int>& nums) {
      size_t l{0}, r{0};
      while (r<nums.size()) {
        nums[l] = nums[r];
        while (r < nums.size() && nums[r] == nums[l]) {
          r++;
        }
        l++;
      }
      return static_cast<int>(l);
    }
};
