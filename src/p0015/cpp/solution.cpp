class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size();) {
            for (size_t j = i + 1, k = nums.size() - 1; j < k;) {
                if (nums[j] + nums[k] + nums[i] < 0) {
                    j++;
                } else if (nums[j] + nums[k] + nums[i] > 0) {
                    k--;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j - 1] == nums[j]) { j++; }
                    while (j < k && nums[k] == nums[k + 1]) { k--; }
                }
            }
            i++;
            while (i < nums.size() && nums[i - 1] == nums[i]) { i++; }
        }
        return result;
    }
};
