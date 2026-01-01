#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      // edge case because I'm lazy: All are 9
      bool all_nine{true};
      for (size_t i{0}; i<digits.size() && all_nine; ++i) {
        if (digits[i] != 9) {
          all_nine = false;
        }
      }
      if (all_nine) {
        std::vector<int> res;
        res.push_back(1);
        for (size_t i{0}; i<digits.size(); ++i) {
          res.push_back(0);
        }
        return res;
      }

      // easy case, no extra digit
      for (int i=digits.size()-1; i>=0; --i) {
        digits[i]++;
        if (digits[i] == 10) {
          digits[i] = 0;
        } else {
          break;
        }
      }
      return digits;
    }
};
