#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;
      unordered_map<string, vector<string>> xs;
      for (const auto &s: strs) {
        array<int, 26> chars = {0};
        for (const char c:s) {
          chars[c-'a']++;
        }
        ostringstream oss;
        for (const int i: chars) {
          oss << i << ",";
        }
        string key = oss.str();
        xs[key].push_back(s);
      }
      for (const auto &p:xs) {
        res.push_back(p.second);
      }
      return res;
    }
};
