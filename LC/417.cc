#include<bits/stdc++.h>

class Solution {
  public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights) {
      int m{static_cast<int>(heights.size())}, n{static_cast<int>(heights[0].size())};
      std::vector<std::vector<int>> cnts(m, std::vector<int>(n, 0));

      const std::array<std::pair<int, int>, 4> dirs{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
      // For pacific
      {
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        for (int i{0}; i<m; ++i) { if (!visited[i][0]) {q.push({i, 0}); visited[i][0]=true;} }
        for (int j{0}; j<n; ++j) { if (!visited[0][j]) {q.push({0, j}); visited[0][j]=true;} }
        while (!q.empty()) {
          auto [y,x] = q.front(); q.pop();
          cnts[y][x]++;
          for (auto &[dy, dx]: dirs) {
            if (y+dy>=0 && y+dy<m && x+dx>=0 && x+dx<n && heights[y][x]<=heights[y+dy][x+dx] && !visited[y+dy][x+dx]) {
              visited[y+dy][x+dx]=true;
              q.push({y+dy, x+dx});
            }
          }
        }
      }
      // For atlantic
      {
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        for (int i{0}; i<m; ++i) { if (!visited[i][n-1]) {q.push({i, n-1}); visited[i][n-1]=true;} }
        for (int j{0}; j<n; ++j) { if (!visited[m-1][j]) {q.push({m-1, j}); visited[m-1][j]=true;} }
        while (!q.empty()) {
          auto [y,x] = q.front(); q.pop();
          cnts[y][x]++;
          for (auto &[dy, dx]: dirs) {
            if (y+dy>=0 && y+dy<m && x+dx>=0 && x+dx<n && heights[y][x]<=heights[y+dy][x+dx] && !visited[y+dy][x+dx]) {
              visited[y+dy][x+dx]=true;
              q.push({y+dy, x+dx});
            }
          }
        }
      }
      std::vector<std::vector<int>> res;
      for (int i{0}; i<m; ++i) {
        for (int j{0}; j<n; ++j) {
          if (cnts[i][j]>=2) {
            res.push_back({i,j});
          }
        }
      }
      return res;
    }
  private:
};
