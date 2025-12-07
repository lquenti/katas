class Solution {
public:
    int countOdds(int low, int high) {
        int res{0};
        if (low&1) {
            res++; low++;
        } if (high&1) {
            res++; low++;
        }
        return res+(high-low)/2;
    }
};
