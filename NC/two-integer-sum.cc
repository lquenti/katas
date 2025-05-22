#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> xs{};
        for (int i=0; i<nums.size(); ++i) {
            if (xs.find(target-nums[i]) != xs.end()) {
                int j = xs[target-nums[i]];
                if (i<j) {
                    return {i,j};
                }
                return {j,i};
            }
            xs[nums[i]] = i;
        }
    }
};

