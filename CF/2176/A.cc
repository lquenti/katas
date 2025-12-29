#include<bits/stdc++.h>
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
