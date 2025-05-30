#include<bits/stdc++.h>

// returns distances to starting node, -1 is unreachable
std::vector<int> bfs_adj_list(std::vector<std::vector<int>> adj_list, int starting_node) {
  size_t n{adj_list.size()};
  if (n == 0) {
    return {};
  }
  std::vector<int> res(n, -1);

  std::unordered_set<int> visited;

  std::queue<int> q;
  q.push(starting_node);

  res[starting_node] = 0;
  visited.insert(starting_node);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v: adj_list[u]) {
      if (visited.count(v) == 0) {
        res[v] = res[u]+1;
        // you can also track some other stuff like parents

        q.push(v);
        visited.insert(v);
      }
    }
  }
  return res;
}

std::vector<int> bfs_adj_mat(std::vector<std::vector<bool>> adj_mat, int starting_node) {
  size_t n{adj_mat.size()};
  if (n == 0) {
    return {};
  }
  std::vector<int> res(n, -1);

  std::unordered_set<int> visited;

  std::queue<int> q;
  q.push(starting_node);

  res[starting_node] = 0;
  visited.insert(starting_node);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v=0; v<n; ++v) {
      if (!adj_mat[u][v]) {
        // does not exist
        continue;
      }
      if (visited.count(v) == 0) {
        res[v] = res[u]+1;
        // you can also track some other stuff like parents

        q.push(v);
        visited.insert(v);
      }
    }
  }
  return res;
}
