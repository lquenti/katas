#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
      auto n{edges.size()};
      std::vector<int> ds1 = bfs(edges, node1), ds2 = bfs(edges, node2);
      int res = -1;
      int cnt = INT_MAX;
      for (int i=0; i<n; ++i) {
        if (ds1[i] != -1 && ds2[i] != -1) {
          int my_max = max(ds1[i], ds2[i]);
          if (cnt > my_max || (cnt == my_max && i < res)) {
            cnt = my_max;
            res = i;
          }
        }
      }
      return res;
    }
  private:
    vector<int> bfs(vector<int> &edges, int starting_node) {
      auto n{edges.size()};
      vector<int> distances(n, -1);
      vector<bool> visited(n);

      queue<int> q;
      q.push(starting_node);
      visited[starting_node] = true;
      distances[starting_node] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();

        int v = edges[u];
        if (v != -1 && !visited[v]) {
          distances[v] = distances[u]+1;
          q.push(v);
          visited[v]=true;
        }
      }
      return distances;
    }
};
