class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[]{};
        HashMap<Integer, Integer> dict = new HashMap<>();
        for (int j = 0; j < nums.length; j++) {
            int y = nums[j], x = target - y;
            Integer i = dict.get(x);
            if (i != null) {
                result = new int[]{i, j};
                break;
            }
            dict.put(y, j);
        }
        return result;
    }
}
