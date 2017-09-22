class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        unordered_map<size_t, size_t> dict;
        for (size_t j = 0; j < nums.size(); j++) {
            size_t y = nums[j], x = target - y;
            auto i = dict.find(x);
            if (i != dict.end()) {
                result.push_back(int(i->second));
                result.push_back(int(j));
                break;
            }
            dict[y] = j;
        }
        return result;
    }
};
