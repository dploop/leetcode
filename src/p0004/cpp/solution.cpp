class Solution {
public:
    double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
        size_t total = nums1.size() + nums2.size();
        size_t kth = (total + 1) / 2;
        size_t begin = max(kth, nums2.size()) - nums2.size();
        size_t end = min(kth, nums1.size());
        while (begin < end) {
            size_t i = begin + (end - begin) / 2;
            size_t j = kth - i;
            if (nums1[i] - nums2[j - 1] < 0) {
                begin = i + 1;
            } else {
                end = i;
            }
        }
        size_t i = begin;
        size_t j = kth - i;
        double left;
        if (j == 0) {
            left = nums1[i - 1];
        } else if (i == 0) {
            left = nums2[j - 1];
        } else {
            left = max(nums1[i - 1], nums2[j - 1]);
        }
        if (total % 2 != 0) {
            return left;
        }
        double right;
        if (j == nums2.size()) {
            right = nums1[i];
        } else if (i == nums1.size()) {
            right = nums2[j];
        } else {
            right = min(nums1[i], nums2[j]);
        }
        return (left + right) / 2;
    }
};
