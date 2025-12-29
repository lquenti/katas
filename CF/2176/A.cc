#include<bits/stdc++.h>
#if 0
/* O(n^2) solution: Index on right side; 2 pointer backwards each time until higher elem found */
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, tmp;
    std::cin >> n;
    std::vector<int> xs;
    while (n--) {
      std::cin >> tmp;
      xs.push_back(tmp);
    }

    size_t cnt{0};
    int r = xs.size()-1;
    while (r>0) {
      for (int l=r-1; l>=0; --l) {
        if (xs[r]<xs[l]) {
          cnt++;
          break;
        }
      }
      r--;
    }
    std::cout << cnt << std::endl;
  }
}
#endif

// Linear: go left to right; remember best one
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, tmp;
    std::cin >> n;
    std::vector<int> xs;
    while (n--) {
      std::cin >> tmp;
      xs.push_back(tmp);
    }

    size_t cnt{0};
    int M{xs[0]};
    for (size_t i{1}; i<xs.size(); ++i) {
      if (M > xs[i]) { // can be removed, is not even better
        cnt++;
        continue;
      }
      M = std::max(M, xs[i]);
    }
    std::cout << cnt << std::endl;
  }
}
