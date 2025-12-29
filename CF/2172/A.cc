#include<bits/stdc++.h>
int main() {
  int tmp;
  std::array<int, 3> xs;
  std::cin >> tmp; xs[0]=tmp; std::cin >> tmp; xs[1]=tmp; std::cin >> tmp; xs[2]=tmp;
  std::sort(xs.begin(), xs.end());
  if (xs[2]-xs[0]>=10) {
    std::cout << "check again" << std::endl;
  } else {
    std::cout << "final " << xs[1] << std::endl;
  }
}
