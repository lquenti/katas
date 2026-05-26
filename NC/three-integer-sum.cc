/*
// naive
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> my_set;
        for (int i=0; i<nums.size(); ++i) {
            for (int j{i+1}; j<nums.size(); ++j) {
                for (int k{j+1}; k<nums.size(); ++k) {
                    if (nums[i]+nums[j]+nums[k] == 0) {
                        vector<int> xs{{nums[i], nums[j], nums[k]}};
                        sort(xs.begin(), xs.end());
                        my_set.insert(xs);
                    }
                }
            }
        }
        vector<vector<int>> ret;
        for (const auto &x: my_set) {
            ret.push_back(x);
        }
        return ret;
    }
};
*/
