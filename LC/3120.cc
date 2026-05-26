class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::array<unsigned int, 26> letters{};
        for (const char c: word) {
            if (islower(c)) {
                letters[c-'a'] |= 1;
            } else {
                letters[c-'A'] |= 2;
            }
        }
        int cnt{};
        for (const auto l: letters) {
            if (l==3) {
                cnt++;
            }
        }
        return cnt;
    }
};
