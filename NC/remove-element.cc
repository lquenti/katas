#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      size_t i{0}, offset{0};
      while (i+offset < nums.size()) {
        nums[i] = nums[i+offset];
        if (nums[i] == val) {
          offset++;
        } else {
          i++;
        }
      }
      nums.resize(i);
      return static_cast<int>(i)+1;
    }
};
