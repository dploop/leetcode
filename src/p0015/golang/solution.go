func threeSum(nums []int) (result [][]int) {
	n := len(nums)
	sort.Ints(nums)
	for i := 0; i < len(nums); {
		for j, k := i+1, n-1; j < k; {
			if nums[i]+nums[j]+nums[k] < 0 {
				j++
			} else if nums[i]+nums[j]+nums[k] > 0 {
				k--
			} else {
				result = append(result, []int{nums[i], nums[j], nums[k]})
				j++
				k--
				for j < k && nums[j-1] == nums[j] {
					j++
				}
				for j < k && nums[k] == nums[k+1] {
					k--
				}
			}
		}
		i++
		for i < len(nums) && nums[i-1] == nums[i] {
			i++
		}
	}
	return result
}
