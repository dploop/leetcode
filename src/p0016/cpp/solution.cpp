#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int ret = INT_MAX/2, len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            for (int j=i+1, k=len-1; j < k; ) {
                int sum=nums[i]+nums[j]+nums[k], delta=sum-target;
                if (abs(ret-target) > abs(delta)) {ret = sum;}
                if (delta < 0) {++j; continue;}
                if (delta > 0) {--k; continue;}
                return ret;
            }
        }
        return ret;
    }
};
