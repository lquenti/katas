#include<bits/stdc++.h>
class Solution {
  public:
    int minLengthAfterRemovals(std::vector<int> &nums) {
      std::unordered_map<int, int> counts;
      for (int num : nums) {
        counts[num]++;
      }
      std::priority_queue<int> pq;
      for (auto &pair : counts) {
        pq.push(pair.second);
      }

      while (pq.size() >= 2) {
        int freq1 = pq.top(); pq.pop();
        int freq2 = pq.top(); pq.pop();
        freq1--;freq2--;
        if (freq1 > 0) {
          pq.push(freq1);
        }
        if (freq2 > 0) {
          pq.push(freq2);
        }
      }

      int res{0};
      while (!pq.empty()) {
        res += pq.top(); pq.pop();
      }
      return res;
    }
};
