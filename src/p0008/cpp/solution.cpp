#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int myAtoi(string &s) {

        int i = 0;

        // Consume whitespaces.
        while (i < s.length() && s[i] == ' ') i++;

        // Consume sign.
        int32_t sign = 1;
        if (i >= s.length()) return 0;
        switch (s[i]) {
            case '-': sign = -1;
            case '+': i++; break;
        }

        // Consume value.
        int32_t y = 0;
        while (i < s.length() && isdigit(s[i])) {
            if (y > INT_MAX / 10 || (y == INT_MAX / 10 && s[i] > '7')) {
                return (sign > 0) ? INT_MAX : INT_MIN;
            }
            y = y * 10 + (s[i] - '0'); i++;
        }

        return sign * y;
    }
};

int main() {
    Solution sol;
    string s("-91283472332");
    cout << sol.myAtoi(s) << endl;
}