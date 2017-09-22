package main

import (
	"sort"
)

func threeSum(nums []int) (result [][]int) {
	n := len(nums)
	sort.Ints(nums)
	for i, x := range nums {
		if x > 0 {
			break
		}
		if i > 0 && nums[i - 1] == x {
			continue
		}
		for j, k := i + 1, n - 1; j < k; {
			y, z := nums[j], nums[k]
			if (j > i + 1 && nums[j - 1] == y) || x + y + z < 0 {
				j++
				continue
			}
			if (k < n - 1 && nums[k + 1] == z) || x + y + z > 0 {
				k--
				continue
			}
			result = append(result, []int{x, y, z})
			j++
			k--
		}
	}
	return result
}
