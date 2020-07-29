class Solution {
public:
    string restoreString(string s, vector<int> &t) {
        int n = static_cast<int>(t.size());
        for (int i = 0; i < n; i++) {
            while (t[i] != i) {
                swap(s[t[i]], s[i]);
                swap(t[t[i]], t[i]);
            }
        }
        return s;
    }
};
