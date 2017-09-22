#include <iostream>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        int y = 0, n;
        for (; x; x /= 10) {
            n = y * 10 + x % 10;
            if ((n - x % 10) / 10 != y) {
                y = 0; break;
            }
            y = n;
        }
        return y;
    }
};
