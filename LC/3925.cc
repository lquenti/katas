class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> res;
        res.reserve(nums.size()*2);
        for (int i{0}; i<nums.size(); ++i) {
            res.push_back(nums[i]);
        }
        for (int i{0}; i<nums.size(); ++i) {
            res.push_back(nums[nums.size()-1-i]);
        }
        return res;
    }
};
