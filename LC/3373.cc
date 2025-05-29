#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
      int n = edges1.size(), m = edges2.size();
      vector<int> res(n+1);

      vector<vector<int>> adj1(n+1);
      for (auto& edge : edges1) {
        adj1[edge[0]].push_back(edge[1]);
        adj1[edge[1]].push_back(edge[0]);
      }
      vector<vector<int>> adj2(m+1);
      for (auto& edge : edges2) {
        adj2[edge[0]].push_back(edge[1]);
        adj2[edge[1]].push_back(edge[0]);
      }

      int max_two = max(evenodd_bfs(adj2, 0, false), evenodd_bfs(adj2, adj2[0][0], false));

      // fuck it redundant code, its a 2color coloring problem
      vector<int> evens = {1+evenodd_bfs(adj1, 0, true), 1+evenodd_bfs(adj1, adj1[0][0], true)};
      unordered_set<int> visited;
      queue<int> q;
      int evens_idx = 0;
      q.push(0);
      visited.insert(0);
      while (!q.empty()) {
        int qsize = q.size();
        for (int i=0; i<qsize; ++i) {
          int curr = q.front();
          q.pop();
          res[curr] = evens[evens_idx] + max_two;

          for (int other: adj1[curr]) {
            if (visited.find(other) == visited.end()) {
              visited.insert(other);
              q.push(other);
            }
          }
        }
        evens_idx = (evens_idx + 1)%2;
      }

      return res;
    }
private:
    int evenodd_bfs(vector<vector<int>> &adj, int starting_node, bool use_even) {
      unordered_set<int> visited;
      queue<int> q;
      int cnt = 0;

      q.push(starting_node);
      visited.insert(starting_node);

      int steps = 1;
      while (!q.empty()) {
        // processing all that are "current step size" away, then incrementing
        // step size
        int qsize = q.size(); // since we mutate we have to "take a snapshot"
        for (int i=0; i<qsize; ++i) {
          int curr = q.front();
          q.pop();

          // Find all neighbours of that
          for (int other : adj[curr]) {
            if (visited.find(other) == visited.end()) {
              visited.insert(other);
              q.push(other);
              if ((use_even && steps%2==0) || (!use_even && steps%2==1)) {
                cnt++;
              }
            }
          }
        }
        steps++;
      }
      return cnt;
    }
};

int main() {
  Solution solution;
  vector<vector<int>> edges1 = {{0,1}, {0,2}, {0,3}, {0,4}};
  vector<vector<int>> edges2 = {{0,1}, {1,2}, {2,3}};
  vector<int> result = solution.maxTargetNodes(edges1, edges2);
  cout << "Result: ";
  for (int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
  }
  cout << endl;
}
