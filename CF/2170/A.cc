#include<bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    if (n==1) {
      std::cout << 1 << std::endl;
    } else if (n == 2) {
      std::cout << 9 << std::endl;
    } else if (n <= 4) {
      std::cout << (n*n) + (n*n-1) + (n*n-2) + (n*n-1-n) << std::endl;
    } else {
      int n_sq{n*n};
      std::cout << n_sq-n + n_sq-n-1 + n_sq-n-2 + n_sq-1 + n_sq-2*n-1 << std::endl;
    }
  }
}
