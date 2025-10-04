#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxArea(vector<int>& height) {
      int res{0};
      int n=height.size();

      int l{0}, r{n-1};
      while (l!=r) {
        res = std::max(res, (r-l)*min(height[r],height[l]));
        if (height[r]<height[l]) {
          r--;
        } else {
          l++;
        }
      }

      return res;
    }
};
