class Solution {
public:
    bool checkOnesSegment(string s) {
        bool found_first_zero{false};
        for (const char c : s) {
            if (found_first_zero && c == '1') {
                return false;
            }
            if (c == '0') {
                found_first_zero=true;
            }
        }
        return true;
    }
};
