#include<bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, tmp;
    std::cin >> n;
    std::set<int> colors;
    while (n--) {
      std::cin >> tmp;
      colors.insert(tmp);
    }
    int cnt=colors.size();
    for (const int i: colors) {
      if (i>=cnt) {
        std::cout << i << std::endl;
        break;
      }
    }
  }
}
