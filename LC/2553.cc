class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        std::vector<int> out{};
        for (auto x: nums) {
            std::vector<int> digits{};
            while (x) {
                int digit = x%10;
                x/=10;
                digits.push_back(digit);
            }
            for (int i=digits.size()-1; i>=0; --i) {
                out.push_back(digits[i]);
            }
        }
        return out;
    }
};
