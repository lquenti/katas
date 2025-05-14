class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            nums1.insert(nums1.end(), nums2.begin(), nums2.end());
            sort(nums1.begin(), nums1.end());
            if (nums1.size() % 2 == 1) {
                return static_cast<double>(nums1[nums1.size()/2]);
            } else {
                return (static_cast<double>(nums1[nums1.size()/2-1]) + nums1[nums1.size()/2])/2.0;
            }
        } else {
            nums2.insert(nums2.end(), nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            if (nums2.size() % 2 == 1) {
                return static_cast<double>(nums2[nums2.size()/2]);
            } else {
                return (static_cast<double>(nums2[nums2.size()/2-1]) + nums2[nums2.size()/2])/2.0;
            }
        }
    }
};
