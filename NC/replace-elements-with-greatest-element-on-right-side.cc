#include<bits/stdc++.h>
class Solution {
  public:
    std::vector<int> replaceElements(std::vector<int> &arr) {
      for (size_t i{0}; i<arr.size()-1; ++i) {
        int best{-1};
        for (size_t j{i+1}; j<arr.size(); ++j) {
          best=std::max(best,arr[j]);
        }
        arr[i]=best;
      }
      arr[arr.size()-1]=-1;
      return arr;
    }
};
