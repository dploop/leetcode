#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        int i, j, k, x, y, z, n = int(nums.size());
        sort(nums.begin(), nums.end());
        for (i = 0; i < n && (x = nums[i]) <= 0; i++) {
            if (i && nums[i - 1] == x) continue;
            for (j = i + 1, k = n - 1; j < k;) {
                y = nums[j];
                if (j > i + 1 && nums[j - 1] == y) { ++j; continue; }
                z = nums[k];
                if (k < n - 1 && nums[k + 1] == z) { --k; continue; }
                if (x + y + z < 0) { ++j; continue; }
                if (x + y + z > 0) { --k; continue; }
                result.push_back({x, y, z}); j++; k--;
            }
        }
        return result;
    }
};

