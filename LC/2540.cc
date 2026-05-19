class Solution {
public:
    int getCommon(vector<int>& xs, vector<int>& ys) {
        int xi=xs.size()-1, yi=ys.size()-1;
        int ret = INT_MAX;
        while (xi >= 0 && yi >= 0) {
            if (xs[xi]==ys[yi]) {
                ret=min(ret, xs[xi]);
                xi--; yi--;
            } else if (xs[xi] > ys[yi]) {
                xi--;
            } else {
                yi--;
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};
