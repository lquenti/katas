#include<bits/stdc++.h>
class Solution {
  public:
    std::vector<int> replaceElements(std::vector<int> &arr) {
      int best_val{-1};
      int curr;
      for (int i=arr.size()-1; i>=0; --i) {
        curr=arr[i];
        arr[i]=best_val;
        best_val=std::max(best_val, curr);
      }
      return arr;
    }
};
