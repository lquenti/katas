class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> xs;
        int best{};
        for (auto x: nums) {
            xs.insert(x);
        }
        for (auto x: nums) {
            if (xs.contains(x-1)) {
                continue; // already part of 
            }
            int score{0}, curr{x};
            while (xs.contains(curr)) {
                curr++;
                score++;
            }
            best = max(score, best);
        }
        return best;
    }
};
