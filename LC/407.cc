#include <bits/stdc++.h>
using ValIdx = std::tuple<int, int, int>;
class Solution {
  public:
    int trapRainWater(std::vector<std::vector<int>> &height_map) {
      int res{0};
      int dirs[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
      int n = height_map.size(), m = height_map[0].size();

      std::priority_queue<ValIdx, std::vector<ValIdx>, std::greater<ValIdx>> min_heap;
      std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

      // fill initial boundary
      for (int i{0}; i<n; ++i) {
        min_heap.push({height_map[i][0], i, 0});
        visited[i][0] = true;
        min_heap.push({height_map[i][m-1], i, m-1});
        visited[i][m-1] = true;
      }
      for (int j{1}; j<m-1; ++j) {
        min_heap.push({height_map[0][j], 0, j});
        visited[0][j] = true;
        min_heap.push({height_map[n-1][j], n-1, j});
        visited[n-1][j] = true;
      }

      while (!min_heap.empty()) {
        auto [val, x, y] = min_heap.top();
        min_heap.pop();
        for (auto &d: dirs) {
          int x2{x+d[0]}, y2{y+d[1]};
          if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m || visited[x2][y2]) {
            continue;
          }
          visited[x2][y2] = true;
          int val2 = height_map[x2][y2];
          res += std::max(0, val-val2);
          min_heap.push({std::max(val,val2), x2, y2});
        }
      }
      return res;
    }
};
