#include<bits/stdc++.h>
class Solution {
  public:
    std::vector<int> avoidFlood(std::vector<int>& rains) {
      int n = rains.size();
      std::vector<int> ans(n);
      std::unordered_map<int, int> last_rain_day;
      std::set<int> dry_days;
      for (int i = 0; i < n; ++i) {
        int lake_id = rains[i];
        if (lake_id > 0) {
          if (last_rain_day.count(lake_id)) {
            int last_rain_index = last_rain_day[lake_id];
            auto it = dry_days.upper_bound(last_rain_index);
            if (it == dry_days.end()) {
              return {};
            }
            int dry_day_index = *it;
            ans[dry_day_index] = lake_id;
            dry_days.erase(it);
          }
          ans[i] = -1;
          last_rain_day[lake_id] = i;
        } else {
          dry_days.insert(i);
          ans[i] = 1; // 1. lake will always be valid, if not overwritten
        }
      }
      return ans;
    }
};
