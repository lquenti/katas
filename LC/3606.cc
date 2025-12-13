#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> elec, groc, phar, res;
        std::unordered_map<string, vector<string> &> map{{
          {"electronics", elec}, {"grocery", groc}, {"pharmacy", phar}, {"restaurant", res}
        }};
        for (const auto &[c, bl, ia] : views::zip(code, businessLine, isActive)) {
          auto it = map.find(bl);
          if (it != map.end() && ia && c.size() && all_of(c.begin(), c.end(), [](char c){return (c=='_' || isalnum(c));})) {
            it->second.push_back(c);
          }
        }
        sort(elec.begin(), elec.end()); sort(groc.begin(), groc.end()); sort(phar.begin(), phar.end()); sort(res.begin(), res.end());
        elec.insert(elec.end(), groc.begin(), groc.end()); elec.insert(elec.end(), phar.begin(), phar.end()); elec.insert(elec.end(), res.begin(), res.end());
        return elec;
    }
};
