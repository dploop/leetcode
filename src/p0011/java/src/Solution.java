class Solution {
    public int maxArea(int[] h) {
        int result = 0, i = 0, j = h.length - 1;
        while (i < j) {
            if (h[i] < h[j]) {
                result = Math.max(result, (j - i) * h[i]);
                i++;
            } else {
                result = Math.max(result, (j - i) * h[j]);
                j--;
            }
        }
        return result;
    }
}
