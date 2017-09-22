class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] count = new int[256];
        int i = 0, j = 0, result = 0;
        while (j < s.length()) {
            count[s.charAt(j)] += 1;
            while (count[s.charAt(j)] > 1) {
                count[s.charAt(i)] -= 1;
                i += 1;
            }
            result = Math.max(result, j + 1 - i);
            j += 1;
        }
        return result;
    }
}
