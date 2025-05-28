#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
      int n = edges1.size(), m = edges2.size();
      vector<int> res{};

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

      // we can precompute!
      int max_from_2 = 0;
      if (k-1 >= 0) {
        for (int i=0; i<=m; ++i) {
          int curr = k_step_bfs(adj2, i, k-1);
          max_from_2 = max(max_from_2, curr);
        }
      }

      for (int i=0; i<=n; ++i) {
        int curr = k_step_bfs(adj1, i, k);
        res.push_back(curr + max_from_2);
      }
      return res;
    }
private:
    int k_step_bfs(vector<vector<int>> &adj, int starting_node, int k) {
      if (k < 0) {
        return 0;
      }
      unordered_set<int> visited;
      queue<int> q;

      q.push(starting_node);
      visited.insert(starting_node);

      int steps = 0;
      while (!q.empty() && steps < k) {
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
            }
          }
        }
        steps++;
      }
      return visited.size();
    }
};


#if 0
Better problem description from the comments:

You are given two trees (which are just connected graphs with no cycles).
	- The first tree has n nodes and is described by edges1.
	- The second tree has m nodes and is described by edges2.
	- You are also given an integer k.

Now, for each node in the first tree, you can temporarily connect it to one node
in the second tree (only one extra edge is added). Then you ask:

How many nodes in this combined graph (both trees + this one extra edge) are
reachable from that node within k or fewer steps?

In other words, you try all possible nodes in the second tree to connect with
that node from the first tree, and you choose the one that gives you the
maximum number of reachable nodes within k steps.

You must repeat this for every node in the first tree, one at a time, and reset
after each one.

Example Summary (first one):
	-	You try connecting node 0 from the first tree to every node in the second tree.
	-	You see how many nodes become "target nodes" (within k=2 distance).
	-	You choose the best connection that gives the highest number of targets.
	-	Store this number in the answer for node 0.
	-	Then do the same for node 1, and so on...
#endif

// int main() {
//   Solution solution;
//   vector<vector<int>> edges1 = {{0,1}, {0,2}, {0,3}, {0,4}};
//   vector<vector<int>> edges2 = {{0,1}, {1,2}, {2,3}};
//   int k = 1;
//   vector<int> result = solution.maxTargetNodes(edges1, edges2, k);
//   cout << "Result: ";
//   for (int i = 0; i < result.size(); i++) {
//       cout << result[i] << " ";
//   }
//   cout << endl;
// }
