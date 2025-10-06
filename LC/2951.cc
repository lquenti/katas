#include<bits/stdc++.h>
class Solution {
  public:
    std::vector<int> findPeaks(std::vector<int> &mountain) {
      std::vector<int> res;
      for (size_t i{1}; i<mountain.size()-1; ++i) {
        if (mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) {
          res.push_back(i);
        }
      }
      return res;
    }
};
