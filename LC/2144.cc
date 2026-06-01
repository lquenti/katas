class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int res{};
        for (int i=cost.size()-1, cnt{0}; i>=0; --i, cnt=(cnt+1)%3) {
            if (cnt != 2) {
                res+=cost[i];
            }
        }
        return res;
    }
};
