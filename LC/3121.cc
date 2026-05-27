class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<unsigned char, 26> xs{};
        for (char c: word) {
            if ((islower(c) && xs[c-'a'] == 2)) {
                xs[c-'a'] = 3; // unrecoverable invalid
            } else if (isupper(c) && xs[c-'A'] == 0) {
                xs[c-'A'] = 3; // unrecoverable invalid
            }
            else if (islower(c) && xs[c-'a'] == 0) {
                xs[c-'a'] = 1; // lower
            } else if (isupper(c) && xs[c-'A'] == 1) {
                xs[c-'A'] = 2; // lower + upper
            }
        }
        int res{};
        for (char x: xs) {
            if (x==2) {
                res++;
            }
        }
        return res;
    }
};
