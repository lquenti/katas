/* Naive O(N^2)
class Solution {
public:
    int trap(vector<int>& height) {
        int total{};
        for (int i=0; i<height.size(); ++i) {
            // find biggest value left and right of it
            int biggest_left{}, biggest_right{};
            for (int l{i-1}; l>=0; --l) {
                biggest_left = max(biggest_left, height[l]);
            }
            for (int r{i+1}; r<height.size(); ++r) {
                biggest_right = max(biggest_right, height[r]);
            }
            if (biggest_left > height[i] && biggest_right > height[i]) {
                total += min(biggest_left, biggest_right)-height[i];
            }
        }
        return total;
    }
};
*/
