#include<bits/stdc++.h>
class Solution {
  public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
      size_t minlen{std::numeric_limits<size_t>::max()};
      for (const auto &s: strs) {
        minlen = std::min(minlen, s.size());
      }
      for (size_t i{0}; i<minlen+1; ++i) {
        bool all_share_prefix{true};
        for (size_t j{1}; j<strs.size(); ++j) {
          if (std::strncmp(strs[0].c_str(), strs[j].c_str(), i)) {
            all_share_prefix = false;
            break;
          }
        }
        if (!all_share_prefix) {
          std::cout << "a " << i << std::endl;
          return strs[0].substr(0, i-1);
        }
      }
      std::cout << "b " << minlen << std::endl;
      return strs[0].substr(0, minlen);
    }
};

// int main() {
//   Solution s{};
//   std::vector<std::string> v;
//   v.push_back("bat");
//   v.push_back("bag");
//   v.push_back("bank");
//   v.push_back("band");
//   s.longestCommonPrefix(v);
// }
