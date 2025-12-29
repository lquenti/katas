#include<bits/stdc++.h>
using namespace std;
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    std::string bin;
    std::cin >> bin;

    size_t cnt{0};
    size_t cooldown{0};
    for (size_t i{0}; i<bin.size(); ++i) {
      if (bin[i] == '1') {
        cooldown=k;
      } else {
        if (cooldown) {
          cooldown--;
          continue;
        }
        cnt++;
      }
    }
    std::cout << cnt << std::endl;
  }
}
