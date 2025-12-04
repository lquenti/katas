#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt{0};
        for (int i{0}; i<points.size(); ++i) {
            for (int j{0}; j<points.size(); ++j) {
                if (i == j) {
                    continue;
                }
                auto x1 = points[i][0], y1 = points[i][1];
                auto x2 = points[j][0], y2 = points[j][1];
                if (x1 <= x2 && y1 >= y2) {
                    bool all_good{true};
                    for (int k{0}; k<points.size(); ++k) {
                        if (k == i || k == j) {
                            continue;
                        }
                        auto x3 = points[k][0], y3 = points[k][1];
                        if (x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2) {
                            all_good=false;
                        }
                    }
                    if (all_good) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
