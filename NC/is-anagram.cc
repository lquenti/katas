#include<bits/stdc++.h>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> ss{}, ts{};
        for (const char c: s) {
            ss[c] += 1;
        }
        for (const char c: t) {
            ts[c] += 1;
        }
        return ss == ts;
    }
};

