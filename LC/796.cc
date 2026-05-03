class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        for (int shift{0}; shift<s.size(); ++shift) {
            bool any_unequal{false};
            for (int i{0}; i<s.size(); ++i) {
                if (s[(i+shift)%s.size()] != goal[i]) {
                    any_unequal=true;
                    break;
                }
            }
            if (!any_unequal) return true;
        }
        return false;
    }
};
