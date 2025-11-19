#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        std::unordered_set<int> xs;
        for (int i=0; i<nums.size(); ++i) {
            xs.insert(nums[i]);
        }
        while (xs.find(original) != xs.end()) {
            original*=2;
        }
        return original;
    }
};
