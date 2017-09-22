#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int> &nums) {
        size_t begin = 0, end = nums.size(); if (end == 0) return 0;
        while (begin < end && nums[begin] == nums[end - 1]) end--;
        while (begin < end) {
            auto mid = begin + (end - begin) / 2;
            (nums[mid] >= nums[0]) ? (begin = mid + 1): (end = mid);
        }
        return (end == nums.size()) ? nums[0] : nums[end];
    }
};
