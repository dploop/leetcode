class Solution {
public:
    int trap(vector<int> &height) {
        auto l = height.begin(), r = height.end();
        int water = 0, lbound = 0, rbound = 0;
        while (l < r) {
            if (lbound < rbound) {
                int curr = *(l++);
                lbound = max(lbound, curr);
                water += lbound - curr;
            } else {
                int curr = *(--r);
                rbound = max(rbound, curr);
                water += rbound - curr;
            }
        }
        return water;
    }
};
