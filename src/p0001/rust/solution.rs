use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut result = Vec::new();
        let mut dict = HashMap::new();
        for (j, y) in nums.iter().enumerate() {
            let x = target - *y;
            if let Some(i) = dict.get(&x) {
                result.push(*i);
                result.push(j as i32);
                break;
            }
            dict.insert(*y, j as i32);
        }
        return result;
    }
}
