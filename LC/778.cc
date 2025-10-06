#include<bits/stdc++.h>
class Solution {
public:
    int swimInWater(std::vector<std::vector<int>> &grid) {
      // note: square and unique
      std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;
      std::set<int> visited{};
      int n{static_cast<int>(grid.size())};
      int start{grid[0][0]}, goal{grid[n-1][n-1]};
      int maxv{start};
      pq.push({start, 0, 0});

      std::array<std::pair<int,int>, 4> dirs{{{0,1}, {1,0}, {0,-1}, {-1,0}}};
      while (!pq.empty()) {
        auto [val, y, x]{pq.top()}; pq.pop();
        // std::cout << val  << ", " << maxv << std::endl;
        maxv = std::max(maxv, val);

        if (val == goal) {
          return maxv;
        }

        for (auto [dy, dx] : dirs) {
          if (y+dy>=0 && y+dy<n && x+dx>=0 && x+dx<n && !visited.contains(grid[y+dy][x+dx])) {
            visited.insert(grid[y+dy][x+dx]);
            pq.push({grid[y+dy][x+dx], y+dy, x+dx});
          }
        }
      }
      std::abort(); // should be unreachable
    }
};
int main() {
  std::vector<std::vector<int>> xs{{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
  Solution s{};
  std::cout << "res " << s.swimInWater(xs) << std::endl;
}
