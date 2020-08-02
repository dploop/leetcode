class Solution {
public:
    int maxSum(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int64_t dp = 0, s1 = 0, s2 = 0;
        for (int i1 = 0, i2 = 0;;) {
            if (i1 < n1 && (i2 == n2 || nums1[i1] < nums2[i2])) {
                s1 += nums1[i1++];
            } else
            if (i2 < n2 && (i1 == n1 || nums2[i2] < nums1[i1])) {
                s2 += nums2[i2++];
            } else {
                dp = (dp + max(s1, s2)) % 1000000007;
                if (i1 == n1 && i2 == n2) { break; }
                s1 = s2 = nums1[i1++] = nums2[i2++];
            }
        }
        return dp;
    }
};
