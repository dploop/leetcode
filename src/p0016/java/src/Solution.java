import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int result = Integer.MAX_VALUE / 2;
        int n = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, k = n - 1; j < k;) {
                int s = nums[i] + nums[j] + nums[k];
                if (Math.abs(s - target) < Math.abs(result - target)) {
                    result = s;
                }
                if (s < target) {
                    j++;
                } else if (s > target) {
                    k--;
                } else {
                    break;
                }
            }
        }
        return result;
    }
}
