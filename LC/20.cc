#include<bits/stdc++.h>
class Solution {
  public:
    bool isValid(std::string s) {
      std::vector<char> xs;
      for (const char c:s) {
        // ik switch is more efficient but more tedious to write
        if (c=='(' || c=='[' || c=='{') {
          xs.push_back(c);
        } else if (c==')') {
          if (xs.size()==0 || xs.back() != '(') return false;
          xs.pop_back();
        } else if (c==']') {
          if (xs.size()==0 || xs.back() != '[') return false;
          xs.pop_back();
        } else if (c=='}') {
          if (xs.size()==0 || xs.back() != '{') return false;
          xs.pop_back();
        } else {
          std::terminate();
        }
      }
      return xs.size() == 0;
    }
};
