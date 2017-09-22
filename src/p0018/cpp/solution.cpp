class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret; int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; ++i) {
            if (i > 0 && nums[i-1]==nums[i]) continue;
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if (nums[i]+nums[len-3]+nums[len-2]+nums[len-1]<target) continue;
            for (int j=i+1; j < len - 2; ++j) {
                if (j>i+1 && nums[j-1]==nums[j]) continue;
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if (nums[i]+nums[j]+nums[len-2]+nums[len-1]<target) continue;
                for (int p=j+1, q=len-1; p < q; ) {
                    if (p > j+1 && nums[p-1]==nums[p]) {++p; continue;}
                    if (q<len-1 && nums[q+1]==nums[q]) {--q; continue;}
                    if (nums[i]+nums[j]+nums[p]+nums[q]<target) {++p; continue;}
                    if (nums[i]+nums[j]+nums[p]+nums[q]>target) {--q; continue;}
                    ret.push_back(vector<int>({nums[i],nums[j],nums[p],nums[q]}));
                    ++p; --q;
                }
            }
        }
        return ret;
    }
};
