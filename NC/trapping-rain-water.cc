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
// Prefix Sums O(n) time O(n) space (Suffices for me for now)
class Solution {
public:
    int trap(vector<int>& height) {
        int res{};
        vector<int> biggest_left;
        vector<int> biggest_right;
        {
            int curr_left{};
            for (int i=0; i<height.size(); ++i) {
                curr_left = max(curr_left, height[i]);
                biggest_left.push_back(curr_left);
            }
        }
        {
            int curr_right{};
            for (int j=height.size()-1; j>=0; --j) {
                curr_right = max(curr_right, height[j]);
                biggest_right.push_back(curr_right);
            }
        }
        reverse(biggest_right.begin(), biggest_right.end());
        for (int i=1; i<height.size()-1; ++i) {
            if (biggest_left[i] > height[i] && biggest_right[i] > height[i]) {
                res+=min(biggest_left[i], biggest_right[i])-height[i];
            }
        }
        return res;
    }
};
