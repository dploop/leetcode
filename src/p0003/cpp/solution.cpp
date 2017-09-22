class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        vector<int> count(256, 0);
        size_t result = 0, i = 0, j = 0;
        while (j < s.length()) {
            count[s[j]] += 1;
            while (count[s[j]] > 1) {
                count[s[i]] -= 1;
                i += 1;
            }
            result = max(result, j + 1 - i);
            j += 1;
        }
        return result;
    }
};
