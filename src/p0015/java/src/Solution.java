import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        int i, j, k, x, y, z, n = nums.length;
        for (i = 0; i < n; i++) {
            x = nums[i]; if (x > 0) break;
            if (i > 0 && nums[i - 1] == x) continue;
            for (j = i + 1, k = n - 1; j < k;) {
                y = nums[j];
                if (j > i + 1 && nums[j - 1] == y) { j++; continue; }
                z = nums[k];
                if (k < n - 1 && nums[k + 1] == z) { k--; continue; }
                if (x + y + z < 0) { j++; continue; }
                if (x + y + z > 0) { k--; continue; }
                result.add(Arrays.asList(x, y, z)); j++; k--;
            }
        }
        return result;
    }
}
