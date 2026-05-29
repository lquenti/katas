class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for (char c: s) {
            switch (c) {
                case '(':
                case '{':
                case '[': {
                    st.push_back(c);
                }
                break;
                case ')': {
                    if (st.size() == 0) {
                        return false;
                    }
                    char x{st.back()};
                    st.pop_back();
                    if (x != '(') {
                        return false;
                    }
                }
                break;
                case '}': {
                    if (st.size() == 0) {
                        return false;
                    }
                    char x{st.back()};
                    st.pop_back();
                    if (x != '{') {
                        return false;
                    }
                }
                break;
                default: { // ']'
                    if (st.size() == 0) {
                        return false;
                    }
                    char x{st.back()};
                    st.pop_back();
                    if (x != '[') {
                        return false;
                    }
                }
                break;
            }
        }
        return st.size() == 0;
    }
};
