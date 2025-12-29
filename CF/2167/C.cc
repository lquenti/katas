#include<bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, tmp;
    std::cin >> n;
    std::vector<int> xs; xs.reserve(n);
    bool iseven{false}, isodd{false};
    while (n--) {
      std::cin >> tmp;
      if (tmp%2) {
        isodd=true;
      } else {
        iseven=true;
      }
      xs.push_back(tmp);
    }
    if (iseven && isodd) {
      std::sort(xs.begin(), xs.end());
    }
    for (const int &x: xs) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }
}
