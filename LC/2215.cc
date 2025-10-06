#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      std::set s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
      std::vector<std::vector<int>> ret(2, std::vector<int>{});
      std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(ret[0]));
      std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), std::back_inserter(ret[1]));
      return ret;
    }
};
