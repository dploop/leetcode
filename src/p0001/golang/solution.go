func twoSum(nums []int, target int) []int {
	var result []int
	dict := make(map[int]int)
	for j, y := range nums {
		x := target - y
		if i, ok := dict[x]; ok {
			result = append(result, i, j)
			break
		}
		dict[y] = j
	}
	return result
}
