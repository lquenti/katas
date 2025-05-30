#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      array<pair<int, int>, 2001> xs{};
      for (int i=0; i<2001; ++i) {
        xs[i].first = i-1000;
      }
      for (const int n:nums) {
        xs[n+1000].second++;
      }
      std::sort(xs.begin(), xs.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
      });
      vector<int> ret;
      for (int i=0; i<k; ++i) {
        ret.push_back(xs[i].first);
      }
      return ret;
    }
};

