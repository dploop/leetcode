class Solution {
public:
    int minSwaps(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<int> f(n, n);
        for (int i = 0; i < n; i++) {
            while (f[i] > 0 && grid[i][f[i] - 1] == 0) {
                f[i]--;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j;
            for (j = i; j < n && f[j] > i + 1; j++) {}
            if (j == n) return -1;
            ans += j - i;
            for (; i < j; j--) swap(f[j - 1], f[j]);
        }
        return ans;
    }
};
