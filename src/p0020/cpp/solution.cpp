class Solution {
private:
    bool isMatch(char p, char q) {
        return (p=='(' && q==')')
            || (p=='{' && q=='}')
            || (p=='[' && q==']');
    }
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto x : s) {
            if (stk.empty()) {
                stk.push(x);
            } else {
                auto y = stk.top();
                if (isMatch(y, x)) {
                    stk.pop();
                } else {
                    stk.push(x);
                }
            }
        }
        return stk.empty();
    }
};
