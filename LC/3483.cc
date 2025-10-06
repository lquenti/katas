#include<bits/stdc++.h>
class Solution {
  public:
    int totalNumbers(std::vector<int> &digits) {
      std::unordered_set<int> ds{}; size_t n{digits.size()}; int cnt{0};
      for (size_t i{0}; i<n; ++i) {
        if (!digits[i]) continue;
        for (size_t j{0}; j<n; ++j) {
          if (j==i) continue;
          for (size_t k{0}; k<n; ++k) {
            if (k==i||k==j) continue;
            if (digits[k]%2==0) ds.insert(digits[i]*100+digits[j]*10+digits[k]);
          }
        }
      }
      return ds.size();
    }
};
