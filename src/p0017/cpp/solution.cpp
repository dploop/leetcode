class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret, alpha;
        if (digits.length() == 0) return ret;
        string n2s[10] = {" ","","abc","def","ghi","jkl"
                            ,"mno","pqrs","tuv","wxyz"};
        for (auto x : digits) {
            alpha.push_back(n2s[x-'0']);
        }
        cartesianProduct(ret, "", alpha);
        return ret;
    }
private:
    void cartesianProduct(vector<string> &ret, string foo
                                , vector<string> &alpha) {
        int len=foo.length(), size=alpha.size();
        if (len >= size) {
            ret.push_back(foo); return;
        }
        string sigma = alpha[len];
        for (auto x : sigma) {
            string bar=foo; bar.push_back(x);
            cartesianProduct(ret, bar, alpha);
        }
    }
};
