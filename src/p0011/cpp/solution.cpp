#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxArea(const vector<int> &hs) {
        int result = 0, i = 0, j = hs.size() - 1;
        while (i < j) {
            if (hs[i] < hs[j]) {
                result = max(result, (j - i) * hs[i]);
                i++;
            } else {
                result = max(result, (j - i) * hs[j]);
                j--;
            }
        }
        return result;
    }
};
