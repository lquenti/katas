#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string encode(vector<string>& strs) {
      ostringstream oss;
      for (const auto &s: strs) {
        auto n{s.size()};
        oss << n/100 << (n%100)/10 << n%10;
        oss << s;
      }
      return oss.str();
    }
    vector<string> decode(string s) {
      auto n{s.size()};
      vector<string> ret;
      size_t i{0};
      while (i<n) {
        int len = stoi(s.substr(i, 3));
        i+=3;
        ret.push_back(s.substr(i, len));
        i+=len;
      }
      return ret;
    }
};


int main() {
  Solution s;
  vector<string> strs = {"we", "say", ":", "yes"};
  string e = s.encode(strs);
  cout << e << endl;
  auto d = s.decode(e);
  cout << "---" << endl;
  for (const auto &x:d) {
    cout << x << endl;
  }
}
