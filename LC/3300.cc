class Solution {
public:
    int minElement(vector<int>& nums) {
        int res{10000+1};
        for (int &n: nums) {
            int qs{0};
            while (n) {
                qs+=n%10;
                n/=10;
            }
            res = min(res, qs);
            n = qs;
        }
        return res;
    }
};
