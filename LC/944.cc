#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deleted{0};
        size_t len{strs[0].length()};
        for (size_t i{0}; i<len; ++i) {
          char last{strs[0][i]};
          bool sorted{true};
          for (size_t j{1}; j<strs.size() && sorted; ++j) {
            char curr{strs[j][i]};
            if (last > curr) {
              sorted=false;
            }
            last=curr;
          }
          if (!sorted) {
            deleted++;
          }
        }
        return deleted;
    }
};
//
// int main() {
//   Solution s{};
//   vector<string> vs;
//   vs.push_back("a");
//   vs.push_back("b");
//   cout << s.minDeletionSize(vs) << endl;
