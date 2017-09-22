func lengthOfLongestSubstring(s string) int {
	count := make([]int, 256)
	i, j, result := 0, 0, 0
	for j < len(s) {
		count[s[j]] += 1
		for count[s[j]] > 1 {
			count[s[i]] -= 1
			i += 1
		}
		if result < j+1-i {
			result = j + 1 - i
		}
		j += 1
	}
	return result
}
