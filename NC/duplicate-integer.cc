#include<bits/stdc++.h>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> xs{};
        for (const auto num: nums) {
            if (xs.find(num) != xs.end()) {
                return true;
            }
            xs.insert(num);
        }
        return false;
    }
};

