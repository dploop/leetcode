impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort();
        let mut result = Vec::new();
        let mut i = 0;
        while i < nums.len() {
            let (mut j, mut k) = (i + 1, nums.len() - 1);
            while j < k {
                if nums[i] + nums[j] + nums[k] < 0 {
                    j += 1;
                } else if nums[i] + nums[j] + nums[k] > 0 {
                    k -= 1;
                } else {
                    result.push(vec![nums[i], nums[j], nums[k]]);
                    j += 1;
                    k -= 1;
                    while j < k && nums[j - 1] == nums[j] { j += 1; }
                    while j < k && nums[k] == nums[k + 1] { k -= 1; }
                }
            }
            i += 1;
            while i < nums.len() && nums[i - 1] == nums[i] { i += 1; }
        }
        return result;
    }
}
