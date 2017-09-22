class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); if (n<=0) return 0;
        int acc = 0, pivot = 0, lhs = 0, rhs = n-1;
        for (int i = 0; i < n; ++i) {
            if (height[i]>height[pivot]) pivot = i;
        }
        for (int i=lhs+1; i < pivot; ++i) {
            if (height[lhs]<=height[i]) {lhs=i;}
            else {acc += height[lhs]-height[i];}
        }
        for (int i=rhs-1; i > pivot; --i) {
            if (height[i]>=height[rhs]) {rhs=i;}
            else {acc += height[rhs]-height[i];}
        }
        return acc;
    }
};
