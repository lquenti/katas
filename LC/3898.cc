class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ret;
        for (int i{0}; i<matrix.size(); ++i) {
            int cnt{0};
            for (int j{0}; j<matrix.size(); ++j) {
                cnt+=matrix[i][j];
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};
