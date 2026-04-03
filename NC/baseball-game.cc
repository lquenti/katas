#include<bits/stdc++.h>
class Solution {
  public:
    int calPoints(std::vector<std::string> &operations) {
      std::vector<int> stack{};
      for (const auto &s: operations) {
        if (s[0]=='+') {
          stack.push_back(stack[stack.size()-1]+stack[stack.size()-2]);
        } else if (s[0]=='D') {
          stack.push_back(stack.back()*2);
        } else if (s[0]=='C') {
          stack.pop_back();
        } else {
          stack.push_back(std::stoi(s));
        }
      }
      int res{0};
      while (!stack.empty()) {
        res+=stack.back();
        stack.pop_back();
      }
      return res;
    }
};
