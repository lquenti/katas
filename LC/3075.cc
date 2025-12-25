#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
      std::sort(happiness.begin(), happiness.end());
      long long sum{0};
      long long neg_count{0};
      for (long long i=happiness.size()-1; k; --i, neg_count++, k--) {
        happiness[i] -= neg_count;
        if (happiness[i]<0) happiness[i] = 0;
        sum+=happiness[i];
      }
      return sum;
    }
};
