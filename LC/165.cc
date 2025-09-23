#include <bits/stdc++.h>
class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
      auto versionToVec = [](std::string_view version) {
        return version
        | std::ranges::views::split('.')
        | std::ranges::views::transform([](auto &&subrange) {
            return std::stoi(std::string(subrange.begin(), subrange.end()));
        })
        | std::ranges::to<std::vector<int>>();
      };
      std::vector<int> ns1{versionToVec(version1)}, ns2{versionToVec(version2)};
      if (ns1.size() < ns2.size()) {
        ns1.insert(ns1.end(), ns2.size()-ns1.size(), 0);
      } else {
        ns2.insert(ns2.end(), ns1.size()-ns2.size(), 0);
      }
      for (int i : std::ranges::iota_view(0, static_cast<int>(ns1.size()))) {
          if (ns1[i] > ns2[i]) {
            return 1;
          } else if (ns2[i] > ns1[i]) {
            return -1;
          }
      }
      return 0;
    }
};

